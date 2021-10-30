/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:14:29 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/30 14:11:14 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

static int	check_line(int	is_middle, char	*line)
{
	size_t	len_line;
	size_t	i;

	len_line = ft_strlen(line);
	i = 0;
	if (is_middle != 1)
	{
		if (line[0] == '1' && line[len_line - 2] == '1')
			return (1);
		else
			return (0);
	}
	else
	{
		while (i < len_line - 1)
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
	i = 0;
	while (i < len_line - 2)
	{
		if (!(line[i] == '0' || line[i] == '1'
				|| line[i] == 'P' || line[i] == 'C' || line[i] == 'E'))
			return (0);
		i++;
	}
	return (1);
}

static int	count_comps(char *line, int	*ex, int *col, int *st)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line) - 2)
	{
		if (line[i] == 'E')
			(*ex)++;
		else if (line[i] == 'C')
			(*col)++;
		else if (line[i] == 'P')
			(*st)++;
		i++;
	}
	return (1);
}

static	int	check_comps(char	*path)
{
	char		*line;
	int			fd;
	int			ex;
	int			col;
	int			st;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	ex = 0;
	col = 0;
	st = 0;
	while (line != NULL)
	{
		count_comps(line, &ex, &col, &st);
		free(line);
		line = get_next_line(fd);
	}
	if (ex >= 1 && col >= 1 && st == 1)
		return (1);
	return (0);
}

int	check_map(int argc, char	**map, char	*path)
{
	size_t	nl;
	int		i;
	size_t	len_frst;

	nl = 1;
	i = 0;
	if (argc != 2)
		return (-2);
	len_frst = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (check_valid_chars(map[i]) == 0 || check_line(nl, map[i]) == 0
			|| ft_strlen(map[i]) != len_frst)
			return (-1);
		nl++;
		i++;
	}
	if (nl == len_frst || check_line(1, map[i - 1]) == 0
		|| check_comps(path) == 0)
		return (2);
	return (1);
}
