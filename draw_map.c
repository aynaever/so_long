/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/23 18:16:15 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	*draw_wall(void	*mlx, void *win, t_coor coor)
{
	void	*img;
	int		*width;
	int		*height;

	width = coor.x;
	height = coor.y;
	img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", width, height);
	mlx_put_image_to_window(mlx, win, img, *coor.x, *coor.y);
	return (img);
}

static	void	*draw_floor(void	*mlx, void *win, t_coor coor)
{
	void	*img;
	int		*width;
	int		*height;

	width = coor.x;
	height = coor.y;
	img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", width, height);
	mlx_put_image_to_window(mlx, win, img, *coor.x, *coor.y);
	return (img);
}

static	void	*draw_exit(void	*mlx, void *win, t_coor coor)
{
	void	*img;
	int		*width;
	int		*height;

	width = coor.x;
	height = coor.y;
	img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", width, height);
	mlx_put_image_to_window(mlx, win, img, *coor.x, *coor.y);
	return (img);
}

static	void	*draw_coll(void	*mlx, void *win, t_coor coor)
{
	void	*img;
	int		*width;
	int		*height;

	width = coor.x;
	height = coor.y;
	img = mlx_xpm_file_to_image(mlx, "img/collectible.xpm", width, height);
	mlx_put_image_to_window(mlx, win, img, *coor.x, *coor.y);
	return (img);
}

static	void	*draw_player(void	*mlx, void *win, t_coor coor)
{
	void	*img;
	int		*width;
	int		*height;

	width = coor.x;
	height = coor.y;
	img = mlx_xpm_file_to_image(mlx, "img/player.xpm", width, height);
	mlx_put_image_to_window(mlx, win, img, *coor.x, *coor.y);
	return (img);
}

int	draw_map(void)
{
	void	*mlx;
	void	*win;
	int		a;
	int		b;
	t_coor	coor;

	coor.x = &a;
	coor.y = &b;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Funny Game");
	draw_floor(mlx, win, coor);
	draw_player(mlx, win, coor);
	draw_coll(mlx, win, coor);
	draw_exit(mlx, win, coor);
	draw_wall(mlx, win, coor);
	mlx_loop(mlx);
	return (0);
}
