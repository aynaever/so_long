/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/23 19:58:53 by anaouadi         ###   ########.fr       */
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

static	void	*draw_row(void	*mlx, void	*win, t_coor coor, char	*line)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	x = coor->x;
	len = ft_strlen(line);
	while (i < len - 1)
	{
		if (line[i] == '1')
			draw_wall(mlx, win, coor);
		else if(line[i] == '0')
			draw_floor(mlx, win, coor);
		else if(line[i] == 'C')
			draw_coll(mlx, win, coor);
		else if(line[i] == 'P')
			draw_player(mlx, win, coor);
		else if(line[i] == 'E')
			draw_exit(mlx, win, coor);
		x += 50;
		coor->x = x;
		printf("line[%d] = %c; coor.x = %d\n", i, line[i], *coor.x);
		i++;
	}
	return (NULL);
}

int	draw_map(char	**map)
{
	void	*mlx;
	void	*win;
	int		a;
	int		b;
	t_coor	coor;

	coor.x = &a;
	coor.y = &b;
	b = 0;
	a = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Funny Game");
	draw_row(mlx, win, coor, map[0]);
	mlx_loop(mlx);
	return (0);
}
