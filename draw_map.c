/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/24 00:18:57 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	*draw_wall(void	*mlx, void *win, t_coor coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", coor.width, coor.height);
	mlx_put_image_to_window(mlx, win, img, coor.x, coor.y);
	return (img);
}

static	void	*draw_floor(void	*mlx, void *win, t_coor coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", coor.width, coor.height);
	mlx_put_image_to_window(mlx, win, img, coor.x, coor.y);
	return (img);
}

static	void	*draw_exit(void	*mlx, void *win, t_coor coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", coor.width, coor.height);
	mlx_put_image_to_window(mlx, win, img, coor.x, coor.y);
	return (img);
}

static	void	*draw_coll(void	*mlx, void *win, t_coor coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "img/coll.xpm", coor.width, coor.height);
	mlx_put_image_to_window(mlx, win, img, coor.x, coor.y);
	return (img);
}

static	void	*draw_player(void	*mlx, void *win, t_coor coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "img/player.xpm", coor.width, coor.height);
	mlx_put_image_to_window(mlx, win, img, coor.x, coor.y);
	return (img);
}

static	void	*draw_row(void	*mlx, void	*win, t_coor coor, char	*line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	coor.x = 0;
	while (i < len - 1)
	{
		if (line[i] == '1')
			draw_wall(mlx, win, coor);
		else if (line[i] == '0')
			draw_floor(mlx, win, coor);
		else if (line[i] == 'C')
			draw_coll(mlx, win, coor);
		else if (line[i] == 'P')
			draw_player(mlx, win, coor);
		else if (line[i] == 'E')
			draw_exit(mlx, win, coor);
		coor.x += 50;
		printf("col[%d] = %c; coor.x = %d; coo.y = %d\n", i, line[i], coor.x, coor.y);
		i++;
	}
	return (NULL);
}

int	calc_rows(char	**map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	draw_map(char	**map)
{
	void	*mlx;
	void	*win;
	int		i;
	int		n_rows;
	int		n_cols;
	int		a;
	int		b;
	t_coor	coor;

	coor.x = 0;
	coor.y = 0;
	n_rows = calc_rows(map);
	n_cols = ft_strlen(map[0]);
	printf("n_rows = %d , n_cols = %d \n", n_rows, n_cols);
	i = 0;
	coor.width = &a;
	coor.height = &b;
	mlx = mlx_init();
	win = mlx_new_window(mlx, n_cols * 60, n_rows * 60, "Funny Game");
	while (i < 5)
	{
		draw_row(mlx, win, coor, map[i]);
		coor.y += 60;
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
