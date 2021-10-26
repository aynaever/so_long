/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: me </var/spool/mail/me>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:02:46 by me                #+#    #+#             */
/*   Updated: 2021/10/26 12:16:54 by me               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(char	**map, t_pos pos)
{
	int	ret_check;

	ret_check = check_right(map, pos);
	if (ret_check == 0)
	{
		printf("I can't move");
	}
	else if(ret_check == 1)
	{
		printf("Move to right");
	}
	else if (ret_check == 2)
	{
		printf("Eat Collectible");
	}
	else if (ret_check == 3)
	{
		printf("Exit");
	}
	return (0);
}

int	move_left(char	**map, t_pos pos)
{
	int	ret_check;

	ret_check = check_right(map, pos);
	if (ret_check == 0)
	{
		printf("I can't move");
	}
	else if(ret_check == 1)
	{
		printf("Move to left");
	}
	else if (ret_check == 2)
	{
		printf("Eat Collectible");
	}
	else if (ret_check == 3)
	{
		printf("Exit");
	}
	return (0);
}

int	move_up(char	**map, t_pos pos)
{
	int	ret_check;

	ret_check = check_right(map, pos);
	if (ret_check == 0)
	{
		printf("I can't move");
	}
	else if(ret_check == 1)
	{
		printf("Move to up");
	}
	else if (ret_check == 2)
	{
		printf("Eat Collectible");
	}
	else if (ret_check == 3)
	{
		printf("Exit");
	}
	return (0);
}

int	move_bottom(char	**map, t_pos pos)
{
	int	ret_check;

	ret_check = check_right(map, pos);
	if (ret_check == 0)
	{
		printf("I can't move");
	}
	else if(ret_check == 1)
	{
		printf("Move to bottom");
	}
	else if (ret_check == 2)
	{
		printf("Eat Collectible");
	}
	else if (ret_check == 3)
	{
		printf("Exit");
	}
	return (0);
}
