/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:13:28 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:23:39 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	norme1(void)
{
	if (g_st.prcsn_star != 1)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		if (g_st.argms != 0 || (g_st.argms = 0 && g_st.prcsn != 0))
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
		}
	}
	else if (g_st.prcsn_star == 1)
		wp_pn_x();
}
