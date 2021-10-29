/*                                                        :::      ::::::::   */
/*   move_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me </var/spool/mail/me>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:02:46 by me                #+#    #+#             */
/*   Updated: 2021/10/27 12:09:23 by me               ###   ########.fr       */
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
		printf("pos->coor->imgs (do_gmove_r) = %p\n", pos->imgs);
		printf("pos->coor = (do_move_r) %p\n", pos->coor);
		do_gmove_r(pos->imgs, pos);
		printf("Move to right x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		map[pos->y][pos->x] = '0';
		do_gmove_r(pos->imgs, pos);
		printf("Eat Collectible x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->x++;
		do_gmove_r(pos->imgs, pos);
		printf("Exit x=%d ; y=%d \n", pos->x, pos->y);
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
		printf("Move to left x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		map[pos->y][pos->x] = '0';
		do_gmove_l(pos->imgs, pos);
		printf("Eat Collectible x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->x--;
		do_gmove_l(pos->imgs, pos);
		printf("Exit x=%d ; y=%d \n", pos->x, pos->y);
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
		printf("Move to up x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		map[pos->y][pos->x] = '0';
		do_gmove_u(pos->imgs, pos);
		printf("Eat Collectible up x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		pos->y--;
		printf("Exit up x=%d ; y=%d \n", pos->x, pos->y);
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
		printf("Move to bottom up x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 2)
	{
		pos->n_ate++;
		map[pos->y][pos->x] = '0';
		do_gmove_b(pos->imgs, pos);
		printf("Eat Collectible up x=%d ; y=%d \n", pos->x, pos->y);
	}
	else if (ret_check == 3 && pos->n_ate == pos->n_coll)
	{
		do_gmove_b(pos->imgs, pos);
		printf("Exit up x=%d ; y=%d \n", pos->x, pos->y);
		exit(0);
	}
	return (0);
}
