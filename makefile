# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 18:19:39 by mgrissen          #+#    #+#              #
#    Updated: 2020/12/22 18:19:42 by mgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utilities.c ft_convert.c ft_getflags.c ft_isdigit.c \
ft_printd.c ft_strchr.c ft_printu.c ft_printp.c ft_printx.c ft_prints.c \
ft_printc.c ft_print_perc.c ft_len.c ft_printd_utils.c ft_len2.c ft_printd_utils2.c \
ft_slen.c ft_prints_dash.c ft_printx_both.c ft_printu_utils.c\

OBJ = $(SRC:.c=.o)
 
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re