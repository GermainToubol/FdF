/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:39:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 18:34:03 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"
#include <stdio.h>

static void	join_y(int x, int y, t_map *map, t_data *img)
{
	t_point	pt1;
	t_point	pt2;

	fdf_set_pt_coordinates(x - map->size_x / 2, y - map->size_y / 2, &pt1, map);
	if (y != map->size_y - 1 && map->map[x][y + 1].exist)
	{
		fdf_set_pt_coordinates(x - map->size_x / 2, y + 1
			- map->size_y / 2, &pt2, map);
		trace_line(&pt1, &pt2, img, map);
	}
}

static void	join_x(int x, int y, t_map *map, t_data *img)
{
	t_point	pt1;
	t_point	pt2;

	fdf_set_pt_coordinates(x - map->size_x / 2, y - map->size_y / 2, &pt1, map);
	if (x != map->size_x - 1 && map->map[x + 1][y].exist)
	{
		fdf_set_pt_coordinates(x + 1 - map->size_x / 2, y
			- map->size_y / 2, &pt2, map);
		trace_line(&pt1, &pt2, img, map);
	}
}

void	display_map(t_map *map, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (generate_i_j(&i, &j, map))
	{
		if (!map->map[i][j].exist)
			continue ;
		join_x(i, j, map, img);
		join_y(i, j, map, img);
	}
}
