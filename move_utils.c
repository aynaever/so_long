/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:01:15 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 13:15:46 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_gmove_r(void ***imgs, t_pos *pos)
{
	void	*floor;
	void	*player;
	t_coor	*coor;

	coor = pos->coor;
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x]);
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x + 1]);
	floor = mlx_xpm_file_to_image(pos->mlx, "img/floor.xpm",
			&coor->width, &coor->height);
	player = mlx_xpm_file_to_image(pos->mlx, "img/player.xpm",
			&coor->width, &coor->height);
	imgs[pos->y][pos->x] = floor;
	imgs[pos->y][pos->x + 1] = player;
	mlx_put_image_to_window(pos->mlx, pos->win, floor,
		(pos->x) * 63, pos->y * 63);
	mlx_put_image_to_window(pos->mlx, pos->win, player,
		(pos->x + 1) * 63, pos->y * 63);
	pos->x++;
	return (0);
}

int	do_gmove_l(void ***imgs, t_pos *pos)
{
	void	*floor;
	void	*player;
	t_coor	*coor;

	coor = pos->coor;
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x]);
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x - 1]);
	floor = mlx_xpm_file_to_image(pos->mlx, "img/floor.xpm",
			&coor->width, &coor->height);
	player = mlx_xpm_file_to_image(pos->mlx, "img/player.xpm",
			&coor->width, &coor->height);
	imgs[pos->y][pos->x] = floor;
	imgs[pos->y][pos->x - 1] = player;
	mlx_put_image_to_window(pos->mlx, pos->win, floor,
		(pos->x) * 63, pos->y * 63);
	mlx_put_image_to_window(pos->mlx, pos->win, player,
		(pos->x - 1) * 63, pos->y * 63);
	pos->x--;
	return (0);
}

int	do_gmove_u(void ***imgs, t_pos *pos)
{
	void	*floor;
	void	*player;
	t_coor	*coor;

	coor = pos->coor;
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x]);
	mlx_destroy_image(pos->mlx, imgs[pos->y - 1][pos->x]);
	floor = mlx_xpm_file_to_image(pos->mlx, "img/floor.xpm",
			&coor->width, &coor->height);
	player = mlx_xpm_file_to_image(pos->mlx, "img/player.xpm",
			&coor->width, &coor->height);
	imgs[pos->y][pos->x] = floor;
	imgs[pos->y - 1][pos->x] = player;
	mlx_put_image_to_window(pos->mlx, pos->win, floor,
		(pos->x) * 63, pos->y * 63);
	mlx_put_image_to_window(pos->mlx, pos->win, player,
		(pos->x) * 63, (pos->y - 1) * 63);
	pos->y--;
	return (0);
}

int	do_gmove_b(void ***imgs, t_pos *pos)
{
	void	*floor;
	void	*player;
	t_coor	*coor;

	coor = pos->coor;
	mlx_destroy_image(pos->mlx, imgs[pos->y][pos->x]);
	mlx_destroy_image(pos->mlx, imgs[pos->y + 1][pos->x]);
	floor = mlx_xpm_file_to_image(pos->mlx, "img/floor.xpm",
			&coor->width, &coor->height);
	player = mlx_xpm_file_to_image(pos->mlx, "img/player.xpm",
			&coor->width, &coor->height);
	imgs[pos->y][pos->x] = floor;
	imgs[pos->y + 1][pos->x] = player;
	mlx_put_image_to_window(pos->mlx, pos->win, floor,
		(pos->x) * 63, pos->y * 63);
	mlx_put_image_to_window(pos->mlx, pos->win, player,
		(pos->x) * 63, (pos->y + 1) * 63);
	pos->y++;
	return (0);
}
