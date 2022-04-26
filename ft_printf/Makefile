# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 13:40:46 by creyt             #+#    #+#              #
#    Updated: 2021/11/19 11:59:38 by creyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEAD = printf.h
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ft_printf.c \
	  ft_putchar_c.c \
	  ft_putnbr_d.c \
	  ft_putnbr_u.c \
	  ft_putnbr_i.c \
	  ft_putstr_s.c \
	  ft_len_nbr.c \
	  ft_puthexa_p.c \
	  ft_puthexa_x.c \
	  ft_puthexa_xx.c

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
		ar -rcs  $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

