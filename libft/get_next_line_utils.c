/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:05:21 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/18 09:59:15 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_line(char *line, char *remainder, int sline, char *ptr)
{
	char	*line_re;

	if (sline <= 0)
	{
		free(ptr);
		return (line);
	}
	if (!line)
		line_re = ft_strncpy_gnl(remainder, sline_index(remainder) + 1);
	else
		line_re = ft_strjoin_gnl(line, remainder, sline_index(remainder) + 1);
	if (ptr != NULL)
		free(ptr);
	return (line_re);
}

char	*put_remainder(char *remainder, int sline_index, int alloc, int ret)
{
	char	*str;
	int		i;
	int		j;

	if ((sline_index == BUFFER_SIZE || ret <= 0))
		return (NULL);
	i = sline_index + 1;
	j = 0;
	str = malloc(len(remainder) - sline_index + 1);
	if (!str)
		return (NULL);
	ft_bzero_gnl(str, len(remainder) - sline_index + 1);
	while (remainder[i])
	{
		str[j] = remainder[i++];
		j++;
	}
	str[j] = '\0';
	if (alloc == 1)
		free(remainder);
	return (str);
}

int	sline_index(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy_gnl(char *s, int n)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(n + 1);
	if (!line)
		return (NULL);
	while (i < n)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
