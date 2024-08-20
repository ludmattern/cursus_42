# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:14:01 by lmattern          #+#    #+#              #
#    Updated: 2024/01/22 19:35:11 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	:=	-Wall -Werror -Wextra
NAME	:=	libftprintf.a
LIBFT	:=	../libft
LIBS	:=	-L$(LIBFT)
SRCS	:=	printf_fmt.c itoa_printf.c libftprintf.c
OBJS	:=	$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

%.o:%.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

$(LIBFT)/libft.a: FORCE
	make -C $(LIBFT)

$(NAME): $(LIBFT)/libft.a $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

FORCE:

.PHONY: all, clean, FORCE, fclean, re