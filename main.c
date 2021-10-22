/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:37:33 by anaouadi          #+#    #+#             */
/*   Updated: 2021/10/22 20:21:31 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	if (check_map(argc, argv[1]) == 0)
	{
		printf("Error!\n");
		return (0);
	}
	store_map(argv[1]);
	draw_map(argv[1]);
	return (0);
}
