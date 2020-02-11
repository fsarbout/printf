/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:48:51 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/06 23:16:40 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		treat_zero(void)
{
	if (g_st.wth_star == 1)
		wth_star_n();
	else if (g_st.wth_star != 1)
	{
		if (g_st.wth >= g_st.prcsn)
			w10_p();
		else if (g_st.wth < g_st.prcsn)
		{
			if (g_st.args < 0)
			{
				g_st.calc = (g_st.prcsn - g_st.len);
				ft_putchar('-');
			}
			else
				g_st.calc = g_st.prcsn - g_st.len;
			treat0_pn_str();
		}
	}
	return (0);
}

void	wth_star_n(void)
{
	if (g_st.prcsn_star == 1)
		p_s_n();
	else if (g_st.prcsn_star == 2)
		p_s_p();
	else if (g_st.prcsn_star == 0)
	{
		g_st.calc = g_st.wth - g_st.len;
		if (g_st.args <= 0)
			p_s_0();
		else
		{
			ft_putnbr(g_st.args, 10, 'd');
			while (g_st.calc > 0 && g_st.calc--)
				ft_putchar(' ');
		}
	}
}
