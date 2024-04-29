# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:14:01 by lmattern          #+#    #+#              #
#    Updated: 2024/04/26 14:35:54 by lmattern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	cc
NAME	:=	philo
CFLAGS	:=	-Wextra -Wall -Werror
HEADERS	:=	-I ./inc
DEPS	:=	./inc/philo.h
SRCDIR	:=	./src

SRCS	:=	$(SRCDIR)/philo.c \
			$(SRCDIR)/verify_booking.c \
			$(SRCDIR)/prepare_dinner.c \
			$(SRCDIR)/prepare_dinner_utils.c \
			$(SRCDIR)/have_dinner.c \
			$(SRCDIR)/philo_behaviour.c \
			$(SRCDIR)/spectators.c \
			$(SRCDIR)/spectators_utils.c \
			$(SRCDIR)/time_related.c \
			$(SRCDIR)/status_mutex_handling.c \
			$(SRCDIR)/value_mutex_handling.c \
			$(SRCDIR)/forks_handling.c \
			$(SRCDIR)/utils.c

OBJDIR	:=	./.obj

OBJS	:=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -g -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) | $(OBJDIR)
	$(CC) $(OBJS) $(HEADERS) $(CFLAGS) -lpthread -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re