/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:05:38 by fsarbout          #+#    #+#             */
/*   Updated: 2020/02/07 18:10:26 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_st
{
	int					wth;
	int					zero;
	int					pnt;
	int					prcsn_star;
	int					prcsn;
	int					mns;
	int					wth_star;
	int					pnt_frst;
	int					npn;
	int					calc;
	int					args;
	unsigned int		argms;
	const char			*str;
	char				v_frmt;
	char				c;
	int					len;
	unsigned long long	p;
}				t_st;
t_st			g_st;
int				g_rtrn;
char			ft_toupper(char c);
void			ft_putchar(char c);
void			ndigit(unsigned int n, int bas, char c);
void			ft_putstr(const char *str);
int				ft_printf(const char *frmt, ...);
int				ft_atoi(const char **s);
void			collect_data(const char **frmt, va_list args);
void			what_next(const char **frmt, va_list args);
int				ft_strchr_pnt(const char *s);
void			treat_start_wth(const char **frmt, va_list args);
void			treat_start_wth_x(const char **frmt, va_list args);
void			treat_start_prcsn(const char **frmt, va_list args);
void			treat_start_prcsn_x(const char **frmt, va_list args);
void			whch_frmt_spcfr(const char **frmt, va_list args);
void			print_int(const char **frmt);
void			print_hex(const char **frmt);
size_t			ft_strlen(const char *s);
int				ft_atoi_nrml(const char *s);
void			w_p_l(void);
void			p_w_l(void);
void			p_l_w(void);
void			w_l_p(void);
void			p_w_len(void);
void			w_p_l_x(void);
void			p_w_l_x(void);
void			p_l_w_x(void);
void			w_l_p_x(void);
void			p_w_len_x(void);
int				treat_zero(void);
int				treat_zero_x(void);
void			wth_star_n(void);
void			wth_star_n_x(void);
void			ft(void);
void			ft_x(void);
void			compare_pwl(void);
void			compare_pwl_x(void);
int				treat_some_cases(void);
int				treat_some_cases_x(void);
void			point0(void);
void			point0_x(void);
void			point1(void);
void			point1_x(void);
int				w0_p0(void);
void			treat0_pn_str(void);
void			w10_p(void);
void			p_s_p(void);
void			p_s_n(void);
void			p_s_0(void);
void			wp_pn(void);
int				w0_p0_x(void);
void			treat0_pn_str_x(void);
void			w10_p_x(void);
void			p_s_p_x(void);
void			p_s_n_x(void);
void			p_s_0_x(void);
void			wp_pn_x(void);
int				arg(const char **frmt);
int				arg_x(const char **frmt);
void			ft_putnbr(unsigned int n, unsigned int nbase, char c);
void			p_w_len2(void);
void			w_p_l2(void);
void			p_w_len2_x(void);
void			w_p_l2_x(void);
void			print_string(const char **frmt);
void			p_len_str(void);
void			point_0str(void);
void			len_p_str(void);
void			put_str(const char *str, int i);
void			print_c(void);
void			print_pr(void);
void			norme1(void);
void			frmt_s(const char **frmt, va_list args);
void			frmt_d(const char **frmt, va_list args);
void			frmt_x(const char **frmt, va_list args);
void			print_p(void);
void			ndigit_p(unsigned long long n);
void			put_p(unsigned long long n);

#endif
