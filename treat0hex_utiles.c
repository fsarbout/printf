/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat0hex_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:49:20 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:26:38 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	w10_p_x(void)
{
	g_st.calc = g_st.wth - g_st.prcsn;
	if (((g_st.prcsn == 0) && (g_st.argms != 0))
			|| ((g_st.len > g_st.prcsn) && (g_st.argms != 0)))
		g_st.calc = g_st.wth - g_st.len;
	if (g_st.argms == 0 && g_st.pnt == 1 && g_st.prcsn_star == 1)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	}
	if ((g_st.wth == 0) && (g_st.prcsn == 0))
		w0_p0_x();
	else if (g_st.pnt == 0)
		point0_x();
	else if (g_st.pnt == 1)
		point1_x();
}

int		w0_p0_x(void)
{
	if (g_st.pnt == 1)
	{
		if (g_st.argms == 0 && g_st.prcsn_star != 1)
			return (0);
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
	if (g_st.pnt == 0)
	{
		if (g_st.argms == 0)
			ft_putchar('0');
		else
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
		}
	}
	return (0);
}

void	point0_x(void)
{
	if ((g_st.prcsn_star == 1) || (g_st.pnt == 0))
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	else if ((g_st.prcsn_star == 0) || (g_st.pnt == 1))
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	if (g_st.argms != 0 || (g_st.argms = 0 && g_st.prcsn != 0))
	{
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
}

void	point1_x(void)
{
	if (g_st.prcsn_star == 1)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
	}
	else
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	g_st.calc = g_st.prcsn - g_st.len;
	(g_st.argms != 0) ? g_st.calc : (g_st.calc = g_st.prcsn);
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

void	treat0_pn_str_x(void)
{
	if (g_st.prcsn_star == 2)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar('0');
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
	else if (g_st.prcsn_star == 0)
	{
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
		if (g_st.argms != 0)
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
		}
	}
	else
		norme1();
}
