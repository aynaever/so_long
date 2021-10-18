/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:14:29 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/18 10:35:26 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(int argc,char	*path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1 || argc != 2)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
