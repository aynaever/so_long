/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:01:27 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 11:01:55 by anaouadi         ###   ########.fr       */
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

int	main(int argc, char	**argv)
{
	char	**map;
	void	*win;
	void	*mlx;
	void	***imgs;
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
	imgs = (void ***) malloc(pos.n_rows * sizeof(void*));
	pos.n_ate = 0;
	pos.mlx = mlx;
	set_pos_player(map, &pos);
	win = draw_map(map, mlx, imgs, &pos);
	pos.win = win;
	add_func(win, &pos);
	mlx_loop(mlx);
	return (0);
}
