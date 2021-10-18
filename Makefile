# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 16:37:28 by anaouadi          #+#    #+#              #
#    Updated: 2021/10/18 11:22:06 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CFLAGS= -Wall -Wextra -Werror
CC=gcc
_SRCS=main.c check_map.c
SRCDIR=srcs
SRCS=$(patsubst %,$(SRCDIR)/%,$(_SRCS))
ODIR=objs
_OBJS=$(_SRCS:.c=.o)
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))
LIBFT=./libft/libft.a
.ONESHELL:

all: $(NAME)

$(OBJS):$(SRCS) 
	cd objs
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux/ -O3 -c $(patsubst %,../%,$(SRCS))
	cd ..

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -Lminilibx-linux/ -Lminilibx-linux/ -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) $(LIBFT) ./minilibx-linux/libmlx_Linux.a -o $(NAME)

$(LIBFT):
	make -C ./libft/

clean:
	rm -rf $(ODIR)/*.o
	make fclean -C ./libft/ 

fclean: clean
	rm -rf $(NAME)

re: fclean all

no:
	norminette *.c

.PHONY: clean fclean re no
