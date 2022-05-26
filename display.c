/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:39:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 17:06:06 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void display_map(t_map *map, void *mlx_ptr, void *win_ptr)
{
	t_point	origin;
	t_point	pt1;
	t_point pt2;
	int i;
	int j;

	origin.x = 150;
	origin.y = 200;
	i = 0;
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			if (!map->map[i][j].exist)
			{
				j++;
				continue ;
			}
			pt1.x = origin.x - (int)((i - j) * map->scale * (sqrt(3) / 2));
			pt1.y = origin.y + (i + j) * map->scale / 2;
			pt1.y -= map->scale * map->map[i][j].altitude / map->scale_z;
			pt1.z = map->map[i][j].altitude;
			if (j != map->size_y - 1 && map->map[i][j + 1].exist)
			{
				pt2.x = origin.x - (int)((i - j - 1) * map->scale * (sqrt(3) / 2));
				pt2.y = origin.y + (i + j + 1) * map->scale / 2;
				pt2.y -= map->scale * map->map[i][j + 1].altitude /map->scale_z;
				trace_line(&pt1, &pt2, mlx_ptr, win_ptr);
			}
			pt1.x = origin.x - (int)((i - j) * map->scale * (sqrt(3) / 2));
			pt1.y = origin.y + (i + j) * map->scale / 2;
			pt1.y -= map->scale * map->map[i][j].altitude / map->scale_z;
			if (i != map->size_x - 1 && map->map[i + 1][j].exist)
			{
				pt2.x = origin.x - (int)((i - j + 1) * map->scale * (sqrt(3) / 2));
				pt2.y = origin.y + (i + j + 1) * map->scale / 2;
				pt2.y -= map->scale * map->map[i + 1][j].altitude / map->scale_z;
				trace_line(&pt1, &pt2, mlx_ptr, win_ptr);
			}
			j++;
		}
		i++;
	}

}
