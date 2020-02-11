/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:23:32 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/07 16:23:17 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ndigit_p(unsigned long long n)
{
	if (n == 0)
		g_st.len++;
	while (n > 0)
	{
		n /= 16;
		g_st.len++;
	}
}

void	put_p(unsigned long long n)
{
	char			*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[(n % 16)]);
	else
	{
		put_p(n / 16);
		ft_putchar(base[(n % 16)]);
	}
}
