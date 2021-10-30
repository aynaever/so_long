/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:43:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 17:48:43 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_pos *pos)
{
	free_imgs(pos);
	free(pos->map);
	free(pos->imgs);
	mlx_destroy_window(pos->mlx, pos->win);
	mlx_destroy_display(pos->mlx);
	free(pos->mlx);
	exit(0);
}

static int	key_hook(int keycode, t_pos *pos)
{
	if (keycode == ESC_KEY)
		close_window(pos);
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

void	free_imgs(t_pos	*pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < pos->n_rows)
	{
		j = 0;
		free(pos->map[i]);
		while (j < pos->n_cols - 1)
		{
			mlx_destroy_image(pos->mlx, pos->imgs[i][j]);
			j++;
		}
		free(pos->imgs[i]);
		i++;
	}
}

void	add_func(void	*win, t_pos *pos)
{
	mlx_key_hook(win, key_hook, pos);
	mlx_hook(win, 17, (1L << 17), close_window, pos);
}
