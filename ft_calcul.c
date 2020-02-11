/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:48:11 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:14:32 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_rtrn++;
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ndigit(unsigned int n, int bas, char c)
{
	if ((int)n < 0 && (c == 'd' || c == 'i'))
		n = n * (-1);
	if (n == 0)
		g_st.len++;
	while (n > 0)
	{
		n /= bas;
		g_st.len++;
	}
}

void	ft_putnbr(unsigned int n, unsigned int nbase, char c)
{
	unsigned int	nb;
	char			*base;

	base = "0123456789abcdef";
	if ((int)n < 0 && (nbase == 10) && (c == 'd' || c == 'i'))
		nb = n * (-1);
	else
		nb = n;
	if (nb < nbase)
	{
		if (g_st.v_frmt == 'X')
			ft_putchar(ft_toupper((base[nb % nbase])));
		else
			ft_putchar(base[(nb % nbase)]);
	}
	else
	{
		ft_putnbr(nb / nbase, nbase, c);
		if (g_st.v_frmt == 'X')
			ft_putchar(ft_toupper((base[nb % nbase])));
		else
			ft_putchar(base[(nb % nbase)]);
	}
}
