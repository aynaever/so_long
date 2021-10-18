/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:24:04 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/18 09:59:40 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*rem;
	char		*line;
	int			ret;

	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		if (len(rem) != 0)
		{
			line = append_line(line, rem, ret, NULL);
			rem = put_remainder(rem, sline_index(rem), 1, ret);
		}
		else
		{
			ft_bzero_gnl(buff, BUFFER_SIZE + 1);
			ret = read(fd, buff, BUFFER_SIZE);
			line = append_line(line, buff, ret, rem);
			rem = put_remainder(buff, sline_index(buff), 0, ret);
		}
		if (ret == 0 || (len(line) >= 1 && line[len(line) - 1] == '\n'))
			return (line);
	}
	return (free_mem(rem, line));
}

char	*free_mem(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

void	ft_bzero_gnl(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2, int sline_index)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(len(s1) + len(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && j < sline_index)
	{
		str[i] = s2[j++];
		i++;
	}
	str[i] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);
}
