# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 16:37:28 by anaouadi          #+#    #+#              #
#    Updated: 2021/10/22 19:41:34 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CFLAGS=-Wall -Wextra -Werror -g
CC=gcc
SRCS=main.c check_map.c draw_map.c store_map.c
OBJS=$(SRCS:.c=.o)
LIBFT=-L libft/ -lft
.ONESHELL:

all: $(NAME)

$(OBJS):$(SRCS) 
	cd objs
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $(SRCS)
	cd ..

$(NAME): $(OBJS) $(LIBFT)
<<<<<<< HEAD
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L./minilibx-linux -lmlx -lXext -lX11 -L/usr/lib -Iminilibx-linux  
=======
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
>>>>>>> put_image_to_window
$(LIBFT):
	make -C ./libft/

clean:
	rm -rf *.o
	make fclean -C ./libft/ 

fclean: clean
	rm -rf $(NAME)

re: fclean all

no:
	norminette *.c *.h

.PHONY: clean fclean re no
