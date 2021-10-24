/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:21:59 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/24 10:58:49 by anaouadi         ###   ########.fr       */
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

#define	ESC_KEY 65307

typedef struct s_coor {
	int	x;
	int	y;
	int	*width;
	int	*height;
}				t_coor;

int		check_map(int argc, char	*path);
void	*draw_map(char	**map, void	*mlx);
char	**store_map(char	*path);
void	*add_func(void	*win);

#endif
