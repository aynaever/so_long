/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:21:59 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/29 15:36:56 by me               ###   ########.fr       */
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

# define	ESC_KEY 65307
# define	A_KEY 97
# define	W_KEY 119
# define	S_KEY 115
# define	D_KEY 100

typedef struct s_coor {
	void	*mlx;
	void	*win;
	void	***imgs;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_coor;

typedef struct s_pos {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		n_rows;
	int		n_cols;
	int		n_coll;
	int		n_ate;
	t_coor	*coor;
	void	***imgs;
	char	**map;
}				t_pos;

int		check_map(int argc, char	*path);
int		check_right(char **map, t_pos *pos);
int		check_left(char **map, t_pos *pos);
int		check_up(char **map, t_pos *pos);
int		check_bottom(char **map, t_pos *pos);
int		move_right(char **map, t_pos *pos);
int		move_left(char **map, t_pos *pos);
int		move_up(char **map, t_pos *pos);
int		move_bottom(char **map, t_pos *pos);
int		calc_rows(char	**map);
void	*draw_map(char	**map, void	*mlx, void	***imgs, t_pos *pos);
char	**store_map(char	*path);
void	add_func(void	*win, t_pos *pos);
void	*draw_wall(t_coor *coor);
void	*draw_floor(t_coor *coor);
void	*draw_exit(t_coor *coor);
void	*draw_coll(t_coor *coor);
void	*draw_player(t_coor *coor);
int		do_gmove_r(void	***imgs, t_pos *pos);
int		do_gmove_l(void	***imgs, t_pos *pos);
int		do_gmove_u(void	***imgs, t_pos *pos);
int		do_gmove_b(void	***imgs, t_pos *pos);

#endif
