/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:47:41 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:05:17 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	w_p_l_x(void)
{
	if (g_st.mns != 1)
	{
		g_st.calc = g_st.wth - g_st.prcsn;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		g_st.calc = g_st.prcsn - g_st.len;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
	else if (g_st.mns == 1 && g_st.zero == 0)
		w_p_l2_x();
}

void	w_p_l2_x(void)
{
	g_st.calc = g_st.prcsn - g_st.len;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	if (g_st.v_frmt == 'u')
		ft_putnbr(g_st.argms, 10, 'u');
	else
		ft_putnbr(g_st.argms, 16, 'x');
	g_st.calc = g_st.wth - g_st.prcsn;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar(' ');
}

void	p_w_l_x(void)
{
	g_st.prcsn = g_st.prcsn - g_st.len;
	while (g_st.prcsn > 0 && g_st.prcsn--)
		ft_putchar('0');
	if (g_st.v_frmt == 'u')
		ft_putnbr(g_st.argms, 10, 'u');
	else
		ft_putnbr(g_st.argms, 16, 'x');
}

void	w_l_p_x(void)
{
	if ((g_st.mns == 1 && g_st.zero == 0)
			|| (g_st.mns == 1 && g_st.zero == 1 && g_st.prcsn_star == 1)
			|| (g_st.mns == 1 && g_st.zero == 1 && g_st.pnt == 1))
	{
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
		g_st.calc = (g_st.wth) - g_st.len;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
	else if (g_st.mns != 1)
	{
		g_st.calc = (g_st.wth) - g_st.len;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
}

void	ft_x(void)
{
	if (g_st.mns != 1 || ((g_st.mns == 1) && (g_st.wth_star == 1)))
	{
		if (g_st.pnt != 1)
			g_st.wth = g_st.wth - 1;
		if (g_st.pnt != 1 && g_st.wth_star == 1)
			ft_putchar('0');
		while (g_st.wth > 0 && g_st.wth--)
			ft_putchar(' ');
		if (g_st.pnt != 1 && g_st.wth_star != 1)
			ft_putchar('0');
	}
	else if (g_st.mns == 1)
	{
		if (g_st.pnt != 1)
		{
			ft_putchar('0');
			g_st.wth = g_st.wth - 1;
		}
		while (g_st.wth > 0 && g_st.wth--)
			ft_putchar(' ');
	}
}
