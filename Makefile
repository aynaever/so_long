# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 16:37:28 by anaouadi          #+#    #+#              #
#    Updated: 2021/10/30 14:21:46 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CFLAGS=-Wall -Wextra -Werror -g
CC=gcc
SRCS=main.c check_map.c draw_map.c store_map.c add_func.c check_sides.c move_sides.c draw_utils.c \
	 move_utils.c
OBJS=$(SRCS:.c=.o)
LIBFT=-L libft/ -lft
MLX=-L minilibx-linux/ -lmlx_Linux
.ONESHELL:

all: $(NAME)

$(OBJS):$(SRCS) 
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $(SRCS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

$(LIBFT):
	make -C ./libft/

$(MLX):
	make -C ./minilibx-linux/

clean:
	rm -rf *.o
	make fclean -C ./libft/ 
	make clean -C ./minilibx-linux/

fclean: clean
	rm -rf $(NAME)

re: fclean all

no:
	norminette *.c *.h

.PHONY: clean fclean re no
