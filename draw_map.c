/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/28 13:38:31 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	*draw_row(t_coor *coor, char	*line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	coor->x = 0;
	while (i < len - 1)
	{
		if (line[i] == '1')
			draw_wall(coor);
		else if (line[i] == '0')
			draw_floor(coor);
		else if (line[i] == 'C')
			draw_coll(coor);
		else if (line[i] == 'P')
			draw_player(coor);
		else if (line[i] == 'E')
			draw_exit(coor);
		coor->x += 60;
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

void	*draw_map(char	**map, void	*mlx)
{
	void	*win;
	int		i;
	int		n_rows;
	int		n_cols;
	t_coor	coor;

	coor.x = 0;
	coor.y = 0;
	n_rows = calc_rows(map);
	n_cols = ft_strlen(map[0]);
	i = 0;
	win = mlx_new_window(mlx, n_cols * 60, n_rows * 60, "Funny Game");
	coor.win = win;
	coor.mlx = mlx;
	while (i < 5)
	{
		draw_row(&coor, map[i]);
		coor.y += 63;
		i++;
	}
	return (win);
}
