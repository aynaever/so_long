/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:21:59 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/19 13:34:58 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define	SO_LONG_H

typedef	struct	s_ncomps {
	int	n_exits;
	int	n_collects;
	int	n_starts;
}				t_ncomps;

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
int	check_map(int argc,char	*path);

#endif
