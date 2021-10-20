/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:55 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/20 12:16:22 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**store_map(char	*path, int noc, int nor)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	fd = open(path, O_RDONLY);
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

	map = store_map(argv[1], 13, 5);
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
