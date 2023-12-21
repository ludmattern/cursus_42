# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:49:19 by lmattern          #+#    #+#              #
#    Updated: 2023/12/15 17:39:37 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

# Add your Push_swap source files here
SRCS =		./src/main.c ./src/check_args.c ./src/push_n_swap.c \
			./src/r_n_rotate.c ./src/sorts.c ./src/secret_actions.c

OBJS = $(SRCS:.c=.o)

# Header files location
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
