# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 16:37:28 by anaouadi          #+#    #+#              #
#    Updated: 2021/10/22 08:05:29 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CFLAGS=-Wall -Wextra -Werror -g
CC=gcc
_SRCS=main.c check_map.c draw_map.c store_map.c
SRCDIR=srcs
SRCS=$(patsubst %,$(SRCDIR)/%,$(_SRCS))
ODIR=objs
_OBJS=$(_SRCS:.c=.o)
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))
LIBFT=-L libft/ -lft
.ONESHELL:

all: $(NAME)

$(OBJS):$(SRCS) 
	cd objs
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $(patsubst %,../%,$(SRCS))
	cd ..

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
$(LIBFT):
	make -C ./libft/

clean:
	rm -rf $(ODIR)/*.o
	make fclean -C ./libft/ 

fclean: clean
	rm -rf $(NAME)

re: fclean all

no:
	norminette $(SRCDIR)/*.c $(SRCDIR)/*.h

.PHONY: clean fclean re no
