/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:55:58 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:11:19 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_string(const char **frmt)
{
	while (**frmt)
	{
		(*frmt)--;
		if (**frmt == '%' || **frmt == '-')
		{
			ft_putstr(g_st.str);
			(*frmt)++;
			break ;
		}
		(*frmt)++;
		if (g_st.pnt == 0 || (g_st.pnt == 1 && g_st.prcsn_star == 1))
			point_0str();
		else if (g_st.prcsn >= g_st.len)
			p_len_str();
		else if (g_st.prcsn < g_st.len)
			len_p_str();
		break ;
	}
}

void	point_0str(void)
{
	g_st.calc = g_st.wth - g_st.len;
	if (g_st.len < g_st.wth)
	{
		if (g_st.mns == 1)
		{
			ft_putstr(g_st.str);
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
		}
		else if (g_st.mns == 0)
		{
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
			ft_putstr(g_st.str);
		}
	}
	else
		ft_putstr(g_st.str);
}

void	p_len_str(void)
{
	if (g_st.wth > g_st.len)
	{
		g_st.calc = g_st.wth - g_st.len;
		if (g_st.mns == 1)
		{
			ft_putstr(g_st.str);
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
		}
		else
		{
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
			ft_putstr(g_st.str);
		}
	}
	else if (g_st.wth <= g_st.len)
		ft_putstr(g_st.str);
}

void	len_p_str(void)
{
	if (g_st.wth <= g_st.prcsn)
		put_str(g_st.str, g_st.prcsn);
	else if (g_st.wth > g_st.prcsn)
	{
		g_st.calc = g_st.wth - g_st.prcsn;
		if (g_st.mns == 1)
		{
			put_str(g_st.str, g_st.prcsn);
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
		}
		else
		{
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
			put_str(g_st.str, g_st.prcsn);
		}
	}
}

void	put_str(const char *str, int i)
{
	while (*str && i > 0 && i--)
	{
		ft_putchar(*str);
		str++;
	}
}
