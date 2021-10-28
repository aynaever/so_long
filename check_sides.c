/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me </var/spool/mail/me>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:58:08 by me                #+#    #+#             */
/*   Updated: 2021/10/27 12:12:44 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_right(char **map, t_pos *pos)
{
	if (((pos->x) + 1 > pos->n_cols))
		return (0);
	else if ((map[pos->y][(pos->x) + 1] == 'P') || (map[pos->y][(pos->x) + 1] == '0'))
		return (1);
	else if ((map[pos->y][(pos->x) + 1] == 'C'))
		return (2);
	else if ((map[pos->y][(pos->x) + 1] == 'E'))
		return (3);
	else
		return (0);
}

int	check_left(char **map, t_pos *pos)
{
	if ((pos->x - 1) < 0)
		return (0);
	else if ((map[pos->y][pos->x - 1] == 'P') || (map[pos->y][pos->x - 1] == '0'))
		return (1);
	else if ((map[pos->y][pos->x - 1] == 'C'))
		return (2);
	else if ((map[pos->y][pos->x - 1] == 'E'))
		return (3);
	else
		return (0);
}

int	check_up(char **map, t_pos *pos)
{
	if ((pos->y - 1) <= 0)
		return (0);
	else if ((map[pos->y - 1][pos->x] == 'P') || (map[pos->y - 1][pos->x] == '0'))
		return (1);
	else if ((map[pos->y - 1][pos->x] == 'C'))
		return (2);
	else if ((map[pos->y - 1][pos->x] == 'E'))
		return (3);
	else
		return (0);
}

int	check_bottom(char **map, t_pos *pos)
{
	if ((pos->y + 1) >= pos->n_rows)
		return (0);
	else if ((map[pos->y + 1][pos->x] == 'p') || (map[pos->y + 1][pos->x] == '0'))
		return (1);
	else if ((map[pos->y + 1][pos->x] == 'C'))
		return (2);
	else if ((map[pos->y + 1][pos->x] == 'E'))
		return (3);
	else
		return (0);
}
