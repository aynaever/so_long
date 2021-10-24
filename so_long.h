/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:21:59 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/23 20:36:47 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_coor {
	int	x;
	int	y;
	int	*width;
	int	*height;
}				t_coor;

int		check_map(int argc, char	*path);
int		draw_map(char	**map);
char	**store_map(char	*path);

#endif
