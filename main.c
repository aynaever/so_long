/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:37:33 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/27 11:31:24 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos_player(char	**map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < pos->n_rows)
	{
		j = 0;
		while (j < pos->n_cols)
		{
			if (map[i][j] == 'P')
			{
				pos->y = i;
				pos->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char	**argv)
{
	char	**map;
	void	*win;
	void	*mlx;
	t_pos	pos;

	if (check_map(argc, argv[1]) == 0)
	{
		printf("Error!\n");
		return (0);
	}
	mlx = mlx_init();
	map = store_map(argv[1]);
	pos.map = map;
	pos.n_rows = calc_rows(map);
	pos.n_cols = ft_strlen(map[0]);
	set_pos_player(map, &pos);
	win = draw_map(map, mlx);
	add_func(win, &pos);
	mlx_loop(mlx);
	return (0);
}
