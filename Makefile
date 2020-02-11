# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:57:10 by fsarbout          #+#    #+#              #
#    Updated: 2020/02/07 18:19:08 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = count_p.c\
	 print_c_pr_p.c\
	 print_string.c\
	 collect_data.c\
   	 ft_atoi_nrml.c\
   	 ft_printf.c\
	 ft_strchr_point.c\
	 fzero_wsn_u.c\
	 p_w_len_x.c\
 	 print_hex_utiles.c\
	 print_int_utiles.c\
	 treat0hex_utiles.c\
	 treat_zero_hexa.c\
	 whch_frmt_spcfr.c\
	 ft_atoi.c\
	 ft_calcul.c\
	 ft_strlen.c\
	 fzero_wsn_u_x.c\
 	 p_w_len.c\
   	 print_hex.c\
	 print_int.c\
	 treat0_utiles.c\
  	 treat_zero.c\
	 what_next.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf *.o

fclean :
	rm -rf *.o
	rm -rf $(NAME)

re : fclean all
