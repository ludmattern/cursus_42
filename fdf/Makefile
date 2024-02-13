# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 13:49:19 by lmattern          #+#    #+#              #
#    Updated: 2024/01/22 14:32:31 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
NAME		:=	fdf
CFLAGS		:=	-Wextra -Wall -Werror -Ofast
LIBFT		:=	./lib/libft
LIBMLX		:=	./lib/minilibx_linux
HEADERS		:=	-I ./inc -I $(LIBMLX)
LIBS		:=	-L$(LIBFT) -lft -L$(LIBMLX) -lmlx
PATHLIBS	:=	./lib/libft.a ./lib/libmlx.a
LFLAGS		:=	-lXext -lX11 -lm -lz
DEPS		:=	./inc/fdf.h $(LIBFT)/libft.a $(LIBMLX)/libmlx.a
SRCS		:=	./src/main.c ./src/array_utils.c ./src/create_layout.c \
				./src/handle_error.c ./src/list_utils.c ./src/parse_input.c \
				./src/adjust_map.c ./src/draw_map.c ./src/display_map.c \
				./src/altitude_to_color.c ./src/color_utils.c ./src/misc.c
OBJS		:=	${SRCS:.c=.o}

all: $(LIBFT) $(LIBMLX) $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -g -o $@ -c $< $(HEADERS)

$(LIBFT)/libft.a: FORCE
	make -C $(LIBFT)

$(LIBMLX)/libmlx.a: FORCE
	make -C $(LIBMLX)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(CFLAGS) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make clean -C $(LIBMLX)

re: clean all

FORCE:

.PHONY: all, clean, FORCE, fclean, re