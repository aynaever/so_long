/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/20 13:03:29 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_nor(char *path)
{
	int		nor;
	char	*line;
	int		fd;

	line = get_next_line(fd);
	fd = open(path, O_RDONLY);
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
	if (map == NULL || fd == -1)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	return (map);
}

int	main(int argc, char	**argv)
{
	char	**map;
	int		i;

	map = store_map(argv[1]);
	if (map == NULL || argc != 2)
		return (0);
	i = 0;
	while (i <= 4)
	{
		printf("map[%d] = %s\n", i, map[i]);
		i++;
	}
	return (0);
}
