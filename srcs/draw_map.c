/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/21 13:03:18 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*width = 0;
	int		*height = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Funny Game");
	img = mlx_xpm_file_to_image(mlx, "exit.xpm", width, height);
	printf("img = %p\n", img);
	mlx_loop(mlx);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	return (0);
}
