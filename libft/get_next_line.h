/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:05:15 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/18 09:57:21 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*append_line(char *line, char *remainder, int sline_index, char *ptr);
char	*put_remainder(char *remainder, int sline_index, int alloc, int ret);
int		sline_index(char *s);
int		len(char *s);
char	*ft_strncpy_gnl(char *s, int n);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2, int sline_index);
void	ft_bzero_gnl(char *s, int n);
char	*free_mem(char *ptr1, char *ptr2);

#endif
