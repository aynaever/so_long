/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:14:29 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/18 21:32:26 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

static int	check_line(int	is_middle, char	*line)
{
	size_t	len_line;
	size_t	i;

	len_line = ft_strlen(line);
	if (is_middle == 1)
	{
		if (line[0] == '1' && line[len_line - 1] == '1')
			return (1);
	}
	else
	{
		while (i < len_line)
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

static	int	check_valid_chars(char	*line)
{
	size_t	len_line;
	size_t	i;

	len_line = ft_strlen(line);
	printf("len_line : %d\n", len_line);
	i = 0;
	while (i < len_line - 2)
	{
		if (!(line[i] == '0' || line[i] == '1'
				|| line[i] == 'P' || line[i] == 'C' || line[i] == 'E'))
		{
			printf("from check valid : %d i=%d\n", line[i], i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(int argc, char	*path)
{
	int		fd;
	size_t	nl;
	char	*line;
	size_t	len_frst_line;

	fd = open(path, O_RDONLY);
	nl = 1;
	if (fd == -1 || argc != 2)
		return (0);
	line = get_next_line(fd);
	len_frst_line = ft_strlen(line);
	while (line != NULL)
	{
		printf("%s", line);
		if (ft_strlen(line) != len_frst_line)
			return (0);
		if (check_valid_chars(line) == 0 || check_line(1, line) == 0)
			return (0);
		line = get_next_line(fd);
		nl++;
	}
	if (nl == len_frst_line)
		return (0);
	return (1);
}
