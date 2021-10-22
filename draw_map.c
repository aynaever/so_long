/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/22 20:20:41 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Funny Game");
	img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
	printf("img = %p\n", img);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
