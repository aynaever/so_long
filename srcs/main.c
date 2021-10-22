/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:37:33 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/22 09:33:55 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	if (check_map(argc, argv[1]) == 0)
	{
		printf("Error!\n");
		return (0);
	}
	store_map(argv[1]);
	//draw_map(argv[1]);
	void	*mlx;
	void	*win;
	int		height, width;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500,500, "fly");
	img = mlx_xpm_file_to_image(mlx, "/home/me/Projects/level_2/so_long/img/exit.xpm", &width, &height);
	printf("img_ptr = %p\n", img);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
