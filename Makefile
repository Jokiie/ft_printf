# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 12:04:14 by ccodere           #+#    #+#              #
#    Updated: 2023/12/07 14:02:09 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

HEADER = libftprintf.h

RM = rm -rf

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putbase.c ft_putbase_hex.c ft_itoa_base.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	ar -rcs $(NAME) $(OBJECTS)

$.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
