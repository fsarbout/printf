/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:07:58 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/07 17:33:10 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *frmt, ...)
{
	va_list	args;

	va_start(args, frmt);
	g_rtrn = 0;
	while (*(frmt))
	{
		g_st = (t_st){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		if (*(frmt) != '%')
			ft_putchar(*(frmt));
		else if (*(frmt) == '%')
			what_next(&frmt, args);
		frmt++;
	}
	va_end(args);
	return (g_rtrn);
}
