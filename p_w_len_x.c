/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_w_len_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:45:47 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 21:16:17 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_w_len_x(void)
{
	if (g_st.prcsn == g_st.wth)
	{
		if (g_st.prcsn > g_st.len)
			p_w_l_x();
		else if (g_st.prcsn < g_st.len)
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
		}
	}
	else if (g_st.wth == g_st.len)
		p_w_len2_x();
	else if (g_st.prcsn == g_st.len)
		w_p_l_x();
}

void	p_w_len2_x(void)
{
	if (g_st.prcsn < g_st.len)
	{
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
	else if (g_st.prcsn > g_st.len)
	{
		g_st.calc = g_st.prcsn - g_st.len;
		while (g_st.calc--)
			ft_putchar('0');
		if (g_st.v_frmt == 'u')
			ft_putnbr(g_st.argms, 10, 'u');
		else
			ft_putnbr(g_st.argms, 16, 'x');
	}
}
