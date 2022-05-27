/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:39:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 15:23:43 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"

static void	fdf_set_pt_coordinates(int x, int y, t_point *pt, t_map *map)
{
	pt->x = map->origin.x - map->scale * (x - y) * (sqrt(3) / 2);
	pt->y = map->origin.y + (x + y) * map->scale / 2;
	pt->y -= map->scale * map->map[x][y].altitude / map->scale_z;
	pt->z = map->map[x][y].altitude;
}

static void	join_y(int x, int y, t_map *map, t_data *img)
{
	t_point	pt1;
	t_point	pt2;

	fdf_set_pt_coordinates(x, y, &pt1, map);
	if (y != map->size_y - 1 && map->map[x][y + 1].exist)
	{
		fdf_set_pt_coordinates(x, y + 1, &pt2, map);
		trace_line(&pt1, &pt2, img);
	}
}

static void	join_x(int x, int y, t_map *map, t_data *img)
{
	t_point	pt1;
	t_point	pt2;

	fdf_set_pt_coordinates(x, y, &pt1, map);
	if (x != map->size_x - 1 && map->map[x + 1][y].exist)
	{
		fdf_set_pt_coordinates(x + 1, y, &pt2, map);
		trace_line(&pt1, &pt2, img);
	}
}

void	display_map(t_map *map, t_data *img)
{
	int	i;
	int	j;

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
			join_x(i, j, map, img);
			join_y(i, j, map, img);
			j++;
		}
		i++;
	}
}
