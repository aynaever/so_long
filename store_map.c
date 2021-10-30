/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:09:00 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 16:38:48 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_nor(char *path)
{
	int		nor;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	nor = 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nor++;
	}
	return (nor);
}

char	**store_map(char	*path)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int		nor;

	fd = open(path, O_RDONLY);
	nor = get_nor(path);
	map = (char **)malloc(nor * sizeof(char *));
	if (map == NULL || fd == -1 || nor == -1)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = '\0';
	return (map);
}
