/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:14:19 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/03 12:08:25 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	collect_data(const char **frmt, va_list args)
{
	ft_strchr_pnt(*frmt);
	while (**frmt)
	{
		if (**frmt != '.')
		{
			if (**frmt == '*')
				treat_start_wth(frmt, args);
			else
				g_st.wth = ft_atoi(frmt);
		}
		if (**frmt == '.')
		{
			(*frmt)++;
			if (**frmt == '*')
				treat_start_prcsn(frmt, args);
			else
			{
				g_st.prcsn = ft_atoi(frmt);
				(g_st.prcsn <= 0) ? g_st.prcsn_star
					: (g_st.prcsn_star = 2);
			}
		}
		break ;
	}
}

void	treat_start_wth(const char **frmt, va_list args)
{
	int i;

	i = va_arg(args, int);
	while (**frmt)
	{
		if (i < 0)
		{
			g_st.wth = (i * (-1));
			g_st.mns = 1;
			g_st.wth_star = 1;
		}
		else
		{
			g_st.wth = i;
			(g_st.wth == 0) ? (g_st.wth_star = 0)
				: (g_st.wth_star = 2);
		}
		(*frmt)++;
		break ;
	}
}

void	treat_start_prcsn(const char **frmt, va_list args)
{
	int i;

	i = va_arg(args, int);
	while (**frmt)
	{
		if (i < 0)
		{
			g_st.prcsn = 0;
			g_st.prcsn_star = 1;
			(*frmt)++;
			break ;
		}
		else
		{
			g_st.prcsn = i;
			(g_st.prcsn == 0) ? (g_st.prcsn_star = 0)
				: (g_st.prcsn_star = 2);
			(*frmt)++;
			break ;
		}
		(*frmt)++;
		break ;
	}
}
