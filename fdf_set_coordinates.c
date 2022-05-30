/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_parallele.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:44:11 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 18:41:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"

static void	fdf_set_pt_coordinates_para(int x, int y, t_point *pt, t_map *map)
{
	pt->x = -map->scale * ((map->cos_theta + 0.707 * map->sin_theta)
			* (float)x - (0.707 * map->cos_theta - map->sin_theta) * (float)y);
	pt->y = map->scale * (float)0.707
		* (map->cos_theta * x + map->sin_theta * y) - map->scale
		* map->map[x + map->size_x / 2][y + map->size_y / 2].altitude
		/ map->scale_z;
	pt->z = map->map[x + map->size_x / 2][y + map->size_y / 2].altitude;
	pt->x += map->origin.x;
	pt->y += map->origin.y;
}

static void	fdf_set_pt_coordinates_iso(int x, int y, t_point *pt, t_map *map)
{
	pt->x = -map->scale * (sqrt(3) / 2)
		* ((map->cos_theta - map->sin_theta) * x
			- (map->cos_theta + map->sin_theta) * y);
	pt->y = ((map->cos_theta + map->sin_theta) * x
			+ (map->cos_theta - map->sin_theta) * y) * map->scale / 2;
	pt->y -= map->scale
		* map->map[x + map->size_x / 2][y + map->size_y / 2].altitude
		/ map->scale_z;
	pt->z = map->map[x + map->size_x / 2][y + map->size_y / 2].altitude;
	pt->x += map->origin.x;
	pt->y += map->origin.y;
}

void	fdf_set_pt_coordinates(int x, int y, t_point *pt, t_map *map)
{
	pt->x = 0;
	pt->y = 0;
	pt->z = 0;
	if (map->iso == 1)
		fdf_set_pt_coordinates_iso(x, y, pt, map);
	else
		fdf_set_pt_coordinates_para(x, y, pt, map);
}
