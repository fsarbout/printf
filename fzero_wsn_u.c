/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fzero_wsn_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:20:18 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:20:34 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_s_n(void)
{
	(g_st.args == 0) ? g_st.calc = g_st.wth
		: (g_st.calc = g_st.wth - g_st.len);
	if ((int)g_st.args < 0)
	{
		ft_putchar('-');
		g_st.calc = g_st.calc - 1;
	}
	if (g_st.args != 0 || (g_st.args == 0 && g_st.prcsn_star != 0))
	{
		ft_putnbr(g_st.args, 10, 'd');
		if (g_st.args == 0)
			g_st.calc = g_st.calc - 1;
	}
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar(' ');
}

void	p_s_p(void)
{
	g_st.calc = g_st.prcsn - g_st.len;
	if ((int)g_st.args < 0)
		ft_putchar('-');
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	if (g_st.args != 0 || (g_st.args == 0 && g_st.prcsn != 0))
		ft_putnbr(g_st.args, 10, 'd');
	if (g_st.prcsn < g_st.wth)
	{
		g_st.calc = g_st.wth - g_st.prcsn;
		((int)g_st.args < 0) ? g_st.calc = g_st.calc - 1 : g_st.calc;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
}

void	p_s_0(void)
{
	if (g_st.pnt == 0)
		if (g_st.args == 0)
			ft_putchar('0');
	if (g_st.args == 0)
	{
		if (g_st.pnt == 1)
			while (g_st.wth > 0 && g_st.wth--)
				ft_putchar(' ');
		else if (g_st.pnt == 0)
			while (g_st.wth > 1 && g_st.wth--)
				ft_putchar(' ');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(g_st.args, 10, 'd');
		g_st.calc = g_st.calc - 1;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
}

void	wp_pn(void)
{
	g_st.calc = g_st.prcsn - g_st.len;
	if (g_st.prcsn >= g_st.wth)
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	else
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	ft_putnbr(g_st.args, 10, 'd');
}
