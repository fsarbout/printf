/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fzero_wsn_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:20:18 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:19:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_s_n_x(void)
{
	(g_st.argms == 0) ? g_st.calc = g_st.wth :
		(g_st.calc = g_st.wth - g_st.len);
	if (g_st.argms != 0 || (g_st.argms == 0 && g_st.prcsn_star != 0))
	{
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
		if (g_st.argms == 0)
			g_st.calc = g_st.calc - 1;
	}
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar(' ');
}

void	p_s_p_x(void)
{
	g_st.calc = g_st.prcsn - g_st.len;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	if (g_st.argms != 0 || (g_st.argms == 0 && g_st.prcsn != 0))
	{
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
	if (g_st.prcsn < g_st.wth)
	{
		g_st.calc = g_st.wth - g_st.prcsn;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
}

void	p_s_0_x(void)
{
	if (g_st.pnt == 0)
		if (g_st.argms == 0)
			ft_putchar('0');
	if (g_st.argms == 0)
	{
		if (g_st.pnt == 1)
			while (g_st.wth > 0 && g_st.wth--)
				ft_putchar(' ');
		else if (g_st.pnt == 0)
			while (g_st.wth > 1 && g_st.wth--)
				ft_putchar(' ');
	}
}

void	wp_pn_x(void)
{
	g_st.calc = g_st.prcsn - g_st.len;
	if (g_st.prcsn >= g_st.wth)
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	else
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	if (g_st.v_frmt == 'u')
		ft_putnbr(g_st.argms, 10, 'u');
	else
		ft_putnbr(g_st.argms, 16, 'x');
}
