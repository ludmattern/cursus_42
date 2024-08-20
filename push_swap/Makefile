# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:49:19 by lmattern          #+#    #+#              #
#    Updated: 2024/01/06 11:02:08 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRCS =		./src/main.c ./src/check_args.c ./src/push_n_swap.c \
			./src/r_n_rotate.c ./src/sorts.c ./src/secret_actions.c

OBJS = $(SRCS:.c=.o)

INCLUDES =	-I ./inc
INCLUDE =	./inc/push_swap.h

all: libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

libft:
	make -C libft

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re
