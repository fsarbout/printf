/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_zero_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:49:53 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:17:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		treat_zero_x(void)
{
	if (g_st.wth_star == 1)
		wth_star_n_x();
	else if (g_st.wth_star != 1)
	{
		if (g_st.wth >= g_st.prcsn)
			w10_p_x();
		else if (g_st.wth < g_st.prcsn)
		{
			g_st.calc = g_st.prcsn - g_st.len;
			treat0_pn_str_x();
		}
	}
	return (0);
}

void	wth_star_n_x(void)
{
	if (g_st.prcsn_star == 1)
		p_s_n_x();
	else if (g_st.prcsn_star == 2)
		p_s_p_x();
	else if (g_st.prcsn_star == 0)
	{
		g_st.calc = g_st.wth - g_st.len;
		if (g_st.argms <= 0)
			p_s_0_x();
		else
		{
			if (g_st.v_frmt == 'u')
				ft_putnbr(g_st.argms, 10, 'u');
			else
				ft_putnbr(g_st.argms, 16, 'x');
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
		}
	}
}
