/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:43:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/24 11:25:24 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_win(int	keycode, void *)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
	{
		printf("destroy window\n");
		exit(0);
	}
	return (0);
}

void	*add_func(void	*win)
{
	mlx_hook(win, 17, 1L<<17, close_win, NULL);
	mlx_key_hook(win, close_win, NULL);
	return (NULL);
}
