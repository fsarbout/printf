/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:46:14 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:29:18 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_hex(const char **frmt)
{
	while (**frmt)
	{
		if ((**frmt == '%' || **frmt == '-')
				|| (**frmt == '.' && g_st.wth == 0))
		{
			if (g_st.argms != 0)
			{
				if (g_st.v_frmt == 'u')
					ft_putnbr(g_st.argms, 10, 'u');
				else
					ft_putnbr(g_st.argms, 16, 'x');
				(*frmt)++;
				break ;
			}
			else if (g_st.argms == 0)
				g_st.npn = arg(frmt);
			if (g_st.npn == 1)
				break ;
			(*frmt)++;
		}
		(*frmt)++;
		if (!(treat_some_cases_x()))
			compare_pwl_x();
		break ;
	}
}

int		treat_some_cases_x(void)
{
	if (((g_st.len > g_st.prcsn && g_st.len > g_st.wth))
			|| ((g_st.prcsn == g_st.wth
					&& g_st.prcsn == g_st.len && g_st.wth == g_st.len)))
	{
		if (g_st.argms != 0 || (g_st.argms == 0 && g_st.pnt != 1)
				|| (g_st.argms == 0 && g_st.prcsn_star == 1))
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
		}
		return (1);
	}
	else if ((g_st.prcsn == 0) && (g_st.argms == 0)
			&& (g_st.prcsn_star == 0))
	{
		if (g_st.wth == 0 && g_st.pnt == 0)
			ft_putchar('0');
		else if (g_st.wth != 0)
			ft_x();
		return (1);
	}
	return (0);
}

void	compare_pwl_x(void)
{
	if (g_st.len > g_st.prcsn && g_st.len < g_st.wth)
		w_l_p_x();
	else if (g_st.len > g_st.wth && g_st.len < g_st.prcsn)
		p_l_w_x();
	else if (g_st.len < g_st.prcsn && g_st.len < g_st.wth
			&& (g_st.wth != g_st.prcsn))
		(g_st.prcsn < g_st.wth) ? w_p_l_x() : p_w_l_x();
	else if (g_st.len == g_st.prcsn || g_st.len == g_st.wth
			|| g_st.prcsn == g_st.wth)
		p_w_len_x();
}

int		arg_x(const char **frmt)
{
	while (**frmt)
	{
		if (g_st.argms == 0)
		{
			if (g_st.pnt != 1)
			{
				if (g_st.v_frmt == 'u')
					ft_putnbr(g_st.argms, 10, 'u');
				else
					ft_putnbr(g_st.argms, 16, 'x');
				(*frmt)++;
				return (1);
			}
			else if (g_st.pnt == 1 && (*frmt)++)
				return (1);
		}
		break ;
	}
	return (0);
}

void	p_l_w_x(void)
{
	if (g_st.wth != 0 && g_st.wth > g_st.prcsn)
	{
		g_st.calc = ((g_st.prcsn) - (g_st.wth - g_st.len));
		while (g_st.calc > 0 && g_st.calc--)
			ft_putchar(' ');
	}
	g_st.calc = g_st.prcsn - g_st.len;
	while (g_st.calc > 0 && g_st.calc--)
		ft_putchar('0');
	if (g_st.v_frmt == 'u')
		ft_putnbr(g_st.argms, 10, 'u');
	else
		ft_putnbr(g_st.argms, 16, 'x');
}
