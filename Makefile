# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spereyra <spereyra@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 16:13:19 by spereyra          #+#    #+#              #
#    Updated: 2024/08/20 13:26:03 by spereyra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	so_long
SRC		:=	so_long.c setters.c game_utils1.c game_utils2.c map_utils1.c \
			map_utils2.c
OBJ		:=	$(SRC:%.c=%.o)
HEADER	:=	so_long.h
LIBFT	:=	./libft/libft.a
MLX		:=	./mlx_linux/libmlx.a
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra# -framework OpenGL -framework AppKit
LFLAGS	:=	-Llibft -lft -Lmlx_linux -lmlx -lX11 -lXext -lm -lz

.PHONY	:	all clean fclean re

all	:
	make --no-print-directory -C ./libft
	make --no-print-directory -C ./mlx_linux
	make --no-print-directory $(NAME)

$(NAME)	:	$(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Ilibft -Imlx_linux $(LFLAGS) $(CFLAGS)

%.o		:	%.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -Ilibft -Imlx_linux -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MLX)	:
	make -C ./mlx_linux

clean	:
	rm -f ./libft/*.o
	rm -f ./mlx_linux/*.o
	rm -f ./*.o

fclean	:	clean
	rm -f ./libft/libft.a
	rm -f ./mlx_linux/libmlx.a
	rm -f ./so_long

re		:	fclean all
