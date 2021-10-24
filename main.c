/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:37:33 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/24 10:49:26 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	char	**map;
	void	*win;
	void	*mlx;

	if (check_map(argc, argv[1]) == 0)
	{
		printf("Error!\n");
		return (0);
	}
	mlx = mlx_init();
	map = store_map(argv[1]);
	win = draw_map(map, mlx);
	add_func(win);
	mlx_loop(mlx);
	return (0);
}
