/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whch_frmt_spcfr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:11:31 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/07 16:24:27 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	whch_frmt_spcfr(const char **frmt, va_list args)
{
	while (**frmt)
	{
		if ((**frmt == 'd') || (**frmt == 'i'))
			frmt_d(frmt, args);
		else if (**frmt == 'x' || **frmt == 'X' || **frmt == 'u')
			frmt_x(frmt, args);
		else if (**frmt == 's')
			frmt_s(frmt, args);
		else if (**frmt == 'p')
		{
			g_st.p = va_arg(args, unsigned long long);
			print_p();
		}
		else if (**frmt == 'c')
		{
			g_st.c = (char)va_arg(args, int);
			print_c();
		}
		else if (**frmt == '%')
			print_pr();
		break ;
	}
}

void	frmt_d(const char **frmt, va_list args)
{
	if (g_st.zero == 1 || ((g_st.prcsn_star == 1)
				&& g_st.mns != 1 && g_st.zero == 1)
			|| (g_st.pnt_frst == 1))
	{
		g_st.args = va_arg(args, int);
		ndigit(g_st.args, 10, 'd');
		treat_zero();
	}
	else
	{
		g_st.args = va_arg(args, int);
		ndigit(g_st.args, 10, 'd');
		print_int(frmt);
	}
}

void	frmt_x(const char **frmt, va_list args)
{
	if (g_st.zero == 1 || ((g_st.prcsn_star == 1)
				&& g_st.mns != 1 && g_st.zero == 1)
			|| (g_st.pnt_frst == 1))
	{
		g_st.v_frmt = **frmt;
		g_st.argms = va_arg(args, unsigned int);
		if (g_st.v_frmt == 'u')
			ndigit(g_st.argms, 10, 'u');
		else
			ndigit(g_st.argms, 16, 'x');
		treat_zero_x();
	}
	else
	{
		g_st.v_frmt = **frmt;
		g_st.argms = va_arg(args, unsigned int);
		if (g_st.v_frmt == 'u')
			ndigit(g_st.argms, 10, 'u');
		else
			ndigit(g_st.argms, 16, 'x');
		(*frmt)--;
		print_hex(frmt);
	}
}

void	frmt_s(const char **frmt, va_list args)
{
	g_st.str = va_arg(args, char *);
	g_st.str = (g_st.str == NULL) ? "(null)" : g_st.str;
	g_st.len = ft_strlen(g_st.str);
	print_string(frmt);
}
