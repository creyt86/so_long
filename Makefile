# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:55:09 by creyt             #+#    #+#              #
#    Updated: 2022/04/26 14:51:10 by creyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEAD = so_long.h
CC = gcc
CFLAGS = -Werror -Wextra -Wall -Imlx #-g -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit
OBJS = ${SRCS:.c=.o}
FOLDER = ./src/
D_M = src/
SRCS = $(D_M)so_long.c \
		$(D_M)so_check_moves.c \
		$(D_M)so_init.c \
		$(D_M)so_load_map.c \
		$(D_M)so_keyhooks.c \
		$(D_M)so_map_errors.c \
		$(D_M)so_img_map.c \
		$(D_M)so_draw_img.c \
		$(D_M)get_next_line.c \
		$(D_M)get_next_line_utils.c
MLX_PATH = mlx/
LBFT_PATH = libft/
FT_PRINTF_PATH = ft_printf/
LIB = libft/libft.a ft_printf/libftprintf.a mlx/libmlx.a

RM = rm -f
all: ${NAME}
$(NAME):	$(OBJS)
		@$(MAKE) -C $(LBFT_PATH)
		@$(MAKE) -C $(MLX_PATH)
		@$(MAKE) -C $(FT_PRINTF_PATH)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(LIB)
%o:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all
.PHONY: all clean fclean re
