/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_pr_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:20:14 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/07 17:28:52 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(void)
{
	g_st.calc = g_st.wth - 1;
	if (g_st.mns == 0)
	{
		while (g_st.calc-- > 0)
			ft_putchar(' ');
		ft_putchar(g_st.c);
	}
	if (g_st.mns == 1)
	{
		ft_putchar(g_st.c);
		while (g_st.calc-- > 0)
			ft_putchar(' ');
	}
}

void	print_pr(void)
{
	g_st.calc = g_st.wth - 1;
	if (g_st.mns == 0)
	{
		if (!g_st.zero)
		{
			while (g_st.calc-- > 0)
				ft_putchar(' ');
		}
		if (g_st.zero)
		{
			while (g_st.calc-- > 0)
				ft_putchar('0');
		}
		ft_putchar('%');
	}
	if (g_st.mns == 1)
	{
		ft_putchar('%');
		while (g_st.calc-- > 0)
			ft_putchar(' ');
	}
}

void	print_p(void)
{
	ndigit_p(g_st.p);
	g_st.calc = g_st.wth - g_st.len - 2;
	if (g_st.p == 0 && g_st.pnt == 1)
		g_st.calc = g_st.calc + 1;
	if (g_st.mns == 0)
	{
		while (g_st.calc-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		if (g_st.p != 0 || (g_st.p == 0 && g_st.pnt != 1))
			put_p(g_st.p);
	}
	if (g_st.mns == 1)
	{
		ft_putstr("0x");
		if (g_st.p != 0 || (g_st.p == 0 && g_st.pnt != 1))
			put_p(g_st.p);
		while (g_st.calc-- > 0)
			ft_putchar(' ');
	}
}
