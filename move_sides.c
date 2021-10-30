/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:23:57 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 14:23:58 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(char	**map, t_pos *pos)
{
	int	ret_check;

	ret_check = check_right(map, pos);
	if (ret_check == 0)
		return (0);
	else if (ret_check == 1)
	{
		do_gmove_r(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		do_gmove_r(pos->imgs, pos);
		map[pos->y][pos->x] = '0';
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->x++;
		do_gmove_r(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
		exit(0);
	}
	return (0);
}

int	move_left(char	**map, t_pos *pos)
{
	int	ret_check;

	ret_check = check_left(map, pos);
	if (ret_check == 0)
		return (0);
	else if (ret_check == 1)
	{
		do_gmove_l(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		do_gmove_l(pos->imgs, pos);
		map[pos->y][pos->x] = '0';
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->x--;
		do_gmove_l(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
		exit(0);
	}
	return (0);
}

int	move_up(char	**map, t_pos *pos)
{
	int	ret_check;

	ret_check = check_up(map, pos);
	if (ret_check == 0)
		return (0);
	else if (ret_check == 1)
	{
		do_gmove_u(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		do_gmove_u(pos->imgs, pos);
		map[pos->y][pos->x] = '0';
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->y--;
		printf("Move %d \n", pos->n_movs++);
		exit(0);
	}
	return (0);
}

int	move_bottom(char	**map, t_pos *pos)
{
	int	ret_check;

	ret_check = check_bottom(map, pos);
	if (ret_check == 0)
		return (0);
	else if (ret_check == 1)
	{
		do_gmove_b(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		do_gmove_b(pos->imgs, pos);
		map[pos->y][pos->x] = '0';
		printf("Move %d \n", pos->n_movs++);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		do_gmove_b(pos->imgs, pos);
		printf("Move %d \n", pos->n_movs++);
		exit(0);
	}
	return (0);
}
