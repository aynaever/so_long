/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:23:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 14:23:43 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*draw_wall(t_coor *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, "img/wall.xpm",
			&coor->width, &coor->height);
	mlx_put_image_to_window(coor->mlx, coor->win, img, coor->x, coor->y);
	return (img);
}

void	*draw_floor(t_coor *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, "img/floor.xpm",
			&coor->width, &coor->height);
	mlx_put_image_to_window(coor->mlx, coor->win, img, coor->x, coor->y);
	return (img);
}

void	*draw_exit(t_coor *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, "img/exit.xpm",
			&coor->width, &coor->height);
	mlx_put_image_to_window(coor->mlx, coor->win, img, coor->x, coor->y);
	return (img);
}

void	*draw_coll(t_coor *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, "img/coll.xpm",
			&coor->width, &coor->height);
	mlx_put_image_to_window(coor->mlx, coor->win, img, coor->x, coor->y);
	return (img);
}

void	*draw_player(t_coor *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, "img/player.xpm",
			&coor->width, &coor->height);
	mlx_put_image_to_window(coor->mlx, coor->win, img, coor->x, coor->y);
	return (img);
}
