/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:43:42 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/24 01:50:37 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef	struct	s_vars {
	void	*mlx;
	void	*win;
}

int	esc_hook(int	keycode, t_vars vars)
{
	printf("%d\n", keycode);
	if (keycode == 23)
		exit(0);
}

void	*add_func(void	*win)
{
	mlx_key_hook(win, esc_hook, &vars);
	return (NULL);
}
