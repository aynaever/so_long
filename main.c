/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:01:27 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 14:13:46 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos_player(char	**map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	pos->n_coll = 0;
	while (i < pos->n_rows)
	{
		j = 0;
		while (j < pos->n_cols)
		{
			if (map[i][j] == 'P')
			{
				pos->y = i;
				pos->x = j;
			}
			else if (map[i][j] == 'C')
				pos->n_coll++;
			j++;
		}
		i++;
	}
}

static	int	show_error_map(int argc, char **map, char *path)
{
	int	ret;

	ret = check_map(argc, map, path);
	if (ret == 0)
	{
		printf("Error!\n");
		return (0);
	}
	else if (ret == -2)
	{
		printf("Error!\nEnter a valid path and one argument\n");
		return (0);
	}
	else if (ret == -1)
	{
		printf("Error!\nEnter a valid map containing all required chars\n");
		return (0);
	}
	else if (ret == 2)
	{
		printf("Error!\nThe map must be square and surrounded by walls\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	char	**map;
	void	*win;
	void	*mlx;
	void	***imgs;
	t_pos	pos;

	map = store_map(argv[1]);
	if (show_error_map(argc, map, argv[1]) == 0)
		return (0);
	mlx = mlx_init();
	pos.map = map;
	pos.n_movs = 1;
	pos.n_rows = calc_rows(map);
	pos.n_cols = ft_strlen(map[0]);
	imgs = (void ***) malloc(pos.n_rows * sizeof(void *));
	pos.n_ate = 0;
	pos.mlx = mlx;
	set_pos_player(map, &pos);
	win = draw_map(map, mlx, imgs, &pos);
	pos.win = win;
	add_func(win, &pos);
	mlx_loop(mlx);
	return (0);
}
