/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me </var/spool/mail/me>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:36:06 by me                #+#    #+#             */
/*   Updated: 2021/10/30 13:47:51 by anaouadi         ###   ########.fr       */
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
