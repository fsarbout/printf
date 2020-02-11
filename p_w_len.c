/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_w_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:56:10 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:15:04 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_w_len(void)
{
	if (g_st.prcsn == g_st.wth)
	{
		if (g_st.prcsn > g_st.len)
			p_w_l();
		else if (g_st.prcsn < g_st.len)
		{
			if (g_st.args < 0)
				ft_putchar('-');
			ft_putnbr(g_st.args, 10, 'd');
		}
	}
	else if (g_st.wth == g_st.len)
		p_w_len2();
	else if (g_st.prcsn == g_st.len)
		w_p_l();
}

void	p_w_len2(void)
{
	if (g_st.prcsn < g_st.len)
	{
		if (g_st.args < 0)
			ft_putchar('-');
		ft_putnbr(g_st.args, 10, 'd');
	}
	else if (g_st.prcsn > g_st.len)
	{
		g_st.calc = g_st.prcsn - g_st.len;
		if (g_st.args < 0)
			ft_putchar('-');
		while (g_st.calc--)
			ft_putchar('0');
		ft_putnbr(g_st.args, 10, 'd');
	}
}
