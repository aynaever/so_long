/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 11:07:42 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	**draw_row(t_coor *coor, char	*line)
{
	int		i;
	int		len;
	void	**img_line;

	i = 0;
	len = ft_strlen(line);
	img_line = malloc(len * sizeof(void *));
	coor->x = 0;
	while (i < len - 1)
	{
		if (line[i] == '1')
			img_line[i] = draw_wall(coor);
		else if (line[i] == '0')
			img_line[i] = draw_floor(coor);
		else if (line[i] == 'C')
			img_line[i] = draw_coll(coor);
		else if (line[i] == 'P')
			img_line[i] = draw_player(coor);
		else if (line[i] == 'E')
			img_line[i] = draw_exit(coor);
		coor->x += 63;
		i++;
	}
	return (img_line);
}

int	calc_rows(char	**map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	*draw_map(char	**map, void	*mlx, void	***imgs, t_pos *pos)
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
	win = mlx_new_window(mlx, n_cols * 58.5, n_rows * 63, "Funny Game");
	coor.win = win;
	coor.mlx = mlx;
	coor.imgs = imgs;
	pos->coor = &coor;
	pos->imgs = imgs;
	while (i < 5)
	{
		imgs[i] = draw_row(&coor, map[i]);
		coor.y += 63;
		i++;
	}
	return (win);
}
