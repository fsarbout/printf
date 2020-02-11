/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:28:55 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 14:32:40 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		what_next(const char **frmt, va_list args)
{
	(*frmt)++;
	if (**frmt == '0' || **frmt == '.')
	{
		if (**frmt == '0')
		{
			while (**frmt == '0' || **frmt == '-')
			{
				if (**frmt == '-')
					g_st.mns = 1;
				(*frmt)++;
			}
			g_st.zero = 1;
		}
		if (**frmt == '.')
			g_st.pnt_frst = 1;
	}
	if (**frmt == '-')
	{
		while (**frmt == '-' || **frmt == '0')
			(*frmt)++;
		g_st.mns = 1;
	}
	collect_data(frmt, args);
	whch_frmt_spcfr(frmt, args);
}
