/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat0_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:12:41 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:20:17 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	w10_p(void)
{
	g_st.calc = g_st.wth - g_st.prcsn;
	if (((g_st.prcsn == 0) && (g_st.args != 0))
			|| ((g_st.len > g_st.prcsn) && (g_st.args != 0)))
		g_st.calc = g_st.wth - g_st.len;
	((int)g_st.args < 0) ? (g_st.calc = g_st.calc - 1) : g_st.calc;
	if (g_st.args == 0 && g_st.pnt == 1 && g_st.prcsn_star == 1)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	}
	if ((g_st.wth == 0) && (g_st.prcsn == 0))
		w0_p0();
	else if (g_st.pnt == 0)
		point0();
	else if (g_st.pnt == 1)
		point1();
}

int		w0_p0(void)
{
	if (g_st.pnt == 1)
	{
		if (g_st.args == 0 && g_st.prcsn_star != 1)
			return (0);
		if ((int)g_st.args < 0)
			ft_putchar('-');
		ft_putnbr(g_st.args, 10, 'd');
	}
	if (g_st.pnt == 0)
	{
		if (g_st.args == 0)
			ft_putchar('0');
		else
		{
			if ((int)g_st.args < 0)
				ft_putchar('-');
			ft_putnbr(g_st.args, 10, 'd');
		}
	}
	return (0);
}

void	point0(void)
{
	if ((int)g_st.args < 0)
		ft_putchar('-');
	if ((g_st.prcsn_star == 1) || (g_st.pnt == 0))
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	else if ((g_st.prcsn_star == 0) || (g_st.pnt == 1))
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	if (g_st.args != 0 || (g_st.args = 0 && g_st.prcsn != 0))
		ft_putnbr(g_st.args, 10, 'd');
}

void	point1(void)
{
	if (g_st.prcsn_star == 1)
	{
		if ((int)g_st.args < 0)
			ft_putchar('-');
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	}
	else
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	if ((int)g_st.args < 0 && g_st.prcsn_star != 1)
		ft_putchar('-');
	g_st.calc = g_st.prcsn - g_st.len;
	(g_st.args != 0) ? g_st.calc : (g_st.calc = g_st.prcsn);
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	if (g_st.args != 0 || (g_st.args = 0 && g_st.prcsn != 0))
		ft_putnbr(g_st.args, 10, 'd');
}

void	treat0_pn_str(void)
{
	if (g_st.prcsn_star == 2)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		ft_putnbr(g_st.args, 10, 'd');
	}
	else if (g_st.prcsn_star == 0)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		if (g_st.args != 0)
			ft_putnbr(g_st.args, 10, 'd');
	}
	else if (g_st.prcsn_star != 1)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		if (g_st.args != 0 || (g_st.args = 0 && g_st.prcsn != 0))
			ft_putnbr(g_st.args, 10, 'd');
	}
	else if (g_st.prcsn_star == 1)
		wp_pn();
}
