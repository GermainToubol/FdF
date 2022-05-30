/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:33:57 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 13:41:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"

void	fdf_init_map(t_map *map)
{
	map->size_x = 0;
	map->size_y = 0;
	map->map = NULL;
}

void	fdf_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_x)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	map->scale = 1;
	map->scale_z = 1;
	map->size_x = 0;
	map->size_y = 0;
}

void	fdf_init_map_param(t_map *map)
{
	float	sc1;
	float	sc2;

	sc1 = 2.0 * sqrt(3) * (WIN_WIDTH - 50)
		/ (3.0 * ((float)map->size_x + (float)map->size_y));
	sc2 = 2.0 * (WIN_HEIGHT - 75) / ((float)map->size_x + (float)map->size_y);
	if (sc1 > sc2)
		map->scale = (int)sc2;
	else
		map->scale = (int)sc1;
	map->scale_z = 2;
	map->centering = sqrt(3) * ((float)map->size_y - (float)map->size_x) / 8;
	map->origin.x = WIN_WIDTH / 2 + map->scale * map->centering;
	map->origin.y = WIN_HEIGHT / 2 + map->scale
		* ((float)map->size_y + (float)map->size_x) / 16;
	map->theta = 0;
	map->cos_theta = 1;
	map->sin_theta = 0;
}
