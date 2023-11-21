# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:14:01 by lmattern          #+#    #+#              #
#    Updated: 2023/11/16 16:23:40 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= 		-Wall -Werror -Wextra

NAME= 		libftprintf.a

SRCS= 		ft_strlen.c ft_itoa.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c \
			printf_fmt.c libftprintf.c itoa_printf.c ft_bzero.c

OBJS= 		$(SRCS:.c=.o)

.PHONY: 	all clean fclean re

all: 		$(NAME)

$(NAME): 	$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o: 		%.c ft_printf.h
				cc $(FLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
				rm -f $(NAME)

re: 		fclean all