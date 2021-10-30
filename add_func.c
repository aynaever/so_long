/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:43:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 14:05:22 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int	keycode, t_pos *pos)
{
	if (keycode == ESC_KEY)
		exit(0);
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

static int	close_window(void)
{
	exit(0);
}

void	add_func(void	*win, t_pos *pos)
{
	mlx_key_hook(win, key_hook, pos);
	mlx_hook(win, 17, (1L << 17), close_window, pos);
}
