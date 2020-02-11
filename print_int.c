/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 02:28:06 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:23:36 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(const char **frmt)
{
	while (**frmt)
	{
		(*frmt)--;
		if ((**frmt == '%' || **frmt == '-')
				|| (**frmt == '.' && g_st.wth == 0))
		{
			if (g_st.args > 0)
			{
				ft_putnbr(g_st.args, 10, 'd');
				(*frmt)++;
				break ;
			}
			else if (g_st.args <= 0)
				g_st.npn = arg(frmt);
			if (g_st.npn == 1)
				break ;
			(*frmt)++;
		}
		(*frmt)++;
		g_st.npn = treat_some_cases();
		if (g_st.npn != 1)
			compare_pwl();
		break ;
	}
}

int		treat_some_cases(void)
{
	if (((g_st.len > g_st.prcsn && g_st.len > g_st.wth))
			|| ((g_st.prcsn == g_st.wth
					&& g_st.prcsn == g_st.len && g_st.wth == g_st.len)))
	{
		if ((int)g_st.args < 0)
			ft_putchar('-');
		if (g_st.args != 0 || (g_st.args == 0 && g_st.pnt != 1)
				|| (g_st.args == 0 && g_st.prcsn_star == 1))
			ft_putnbr(g_st.args, 10, 'd');
		return (1);
	}
	else if ((g_st.prcsn == 0) && (g_st.args == 0)
			&& (g_st.prcsn_star == 0))
	{
		if (g_st.wth == 0 && g_st.pnt == 0)
			ft_putchar('0');
		else if (g_st.wth != 0)
			ft();
		return (1);
	}
	return (0);
}

void	compare_pwl(void)
{
	if (g_st.len > g_st.prcsn && g_st.len < g_st.wth)
		w_l_p();
	else if (g_st.len > g_st.wth && g_st.len < g_st.prcsn)
		p_l_w();
	else if (g_st.len < g_st.prcsn && g_st.len < g_st.wth
			&& (g_st.wth != g_st.prcsn))
		(g_st.prcsn < g_st.wth) ? w_p_l() : p_w_l();
	else if (g_st.len == g_st.prcsn || g_st.len == g_st.wth
			|| g_st.prcsn == g_st.wth)
		p_w_len();
}

int		arg(const char **frmt)
{
	while (**frmt)
	{
		if (g_st.args == 0)
		{
			if (g_st.pnt != 1)
			{
				ft_putnbr(g_st.args, 10, 'd');
				(*frmt)++;
				return (1);
			}
			else if (g_st.pnt == 1 && (*frmt)++)
				return (1);
		}
		else if ((int)g_st.args < 0)
		{
			ft_putchar('-');
			ft_putnbr(g_st.args, 10, 'd');
			(*frmt)++;
			return (1);
		}
		break ;
	}
	return (0);
}

void	p_l_w(void)
{
	if ((int)g_st.args < 0)
	{
		g_st.npn = g_st.args * (-1);
		ft_putchar('-');
	}
	else
		g_st.npn = g_st.args;
	if (g_st.wth != 0 && g_st.wth > g_st.prcsn)
	{
		g_st.calc = ((g_st.prcsn) - (g_st.wth - g_st.len));
		if ((int)g_st.args < 0)
			g_st.calc = g_st.calc - 1;
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
	g_st.calc = g_st.prcsn - g_st.len;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	ft_putnbr(g_st.npn, 10, 'd');
}
