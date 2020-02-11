/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:25:52 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:07:45 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	w_p_l(void)
{
	if (g_st.mns != 1)
	{
		g_st.calc = g_st.wth - g_st.prcsn;
		if ((int)g_st.args < 0)
			g_st.calc = g_st.calc - 1;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		if ((int)g_st.args < 0)
			ft_putchar('-');
		g_st.calc = g_st.prcsn - g_st.len;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		ft_putnbr(g_st.args, 10, 'd');
	}
	else if (g_st.mns == 1 && g_st.zero == 0)
		w_p_l2();
}

void	w_p_l2(void)
{
	if ((int)g_st.args < 0)
		ft_putchar('-');
	g_st.calc = g_st.prcsn - g_st.len;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	ft_putnbr(g_st.args, 10, 'd');
	g_st.calc = g_st.wth - g_st.prcsn;
	if ((int)g_st.args < 0)
		g_st.calc = g_st.calc - 1;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar(' ');
}

void	p_w_l(void)
{
	g_st.prcsn = g_st.prcsn - g_st.len;
	if ((int)g_st.args < 0)
		ft_putchar('-');
	while (g_st.prcsn > 0 && g_st.prcsn--)
		ft_putchar('0');
	ft_putnbr(g_st.args, 10, 'd');
}

void	w_l_p(void)
{
	if ((g_st.mns == 1 && g_st.zero == 0)
			|| (g_st.mns == 1 && g_st.zero == 1 && g_st.prcsn_star == 1)
			|| (g_st.mns == 1 && g_st.zero == 1 && g_st.pnt == 1))
	{
		if ((int)g_st.args < 0)
			ft_putchar('-');
		ft_putnbr(g_st.args, 10, 'd');
		g_st.calc = (g_st.wth) - g_st.len;
		if ((int)g_st.args < 0)
			g_st.calc = g_st.calc - 1;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
	else if (g_st.mns != 1)
	{
		g_st.calc = (g_st.wth) - g_st.len;
		if ((int)g_st.args < 0)
			g_st.calc = g_st.calc - 1;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		if ((int)g_st.args < 0)
			ft_putchar('-');
		ft_putnbr(g_st.args, 10, 'd');
	}
}

void	ft(void)
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
