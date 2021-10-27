/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:43:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/27 10:50:05 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int	keycode, t_pos *pos)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		printf("destroy window\n");
	else if (keycode == A_KEY)
		move_left(pos->map, pos);
	else if (keycode == S_KEY)
		move_bottom(pos->map, pos);
	else if (keycode == D_KEY)
		move_right(pos->map, pos);
	else if (keycode == W_KEY)
		move_up(pos->map, pos);
	return (0);
}

void	add_func(void	*win, t_pos *pos)
{
	mlx_key_hook(win, key_hook, pos);
}
