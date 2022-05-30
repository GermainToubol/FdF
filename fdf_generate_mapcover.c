/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_generate_mapcover.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:13:49 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 15:17:30 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int 	map_cover_q1(int *i, int *j, t_map *map)
{
	int	changed;

	if (*i == -1 && *j == -1)
	{
		*i = 0;
		*j = -1;
	}
	changed = 0;
	if (*j < map->size_y - 1)
	{
		*j += 1;
		changed = 1;
	}
	else if(*i < map->size_x - 1)
	{
		*j = 0;
		*i += 1;
		changed = 1;
	}
	return (changed);
}

static int 	map_cover_q2(int *i, int *j, t_map *map)
{
	int	changed;

	if (*i == -1 && *j == -1)
	{
		*i = map->size_x;
		*j = 0;
	}
	changed = 0;
	if (*i > 0 )
	{
		*i -= 1;
		changed = 1;
	}
	else if(*j < map->size_y - 1)
	{
		*i = map->size_x - 1;
		*j += 1;
		changed = 1;
	}
	return (changed);
}

static int 	map_cover_q3(int *i, int *j, t_map *map)
{
	int	changed;

	if (*i == -1 && *j == -1)
	{
		*i = -1;
		*j = map->size_y - 1;
	}
	changed = 0;
	if (*i < map->size_x - 1 )
	{
		*i += 1;
		changed = 1;
	}
	else if(*j > 0)
	{
		*i = 0;
		*j -= 1;
		changed = 1;
	}
	return (changed);
}


static int 	map_cover_q4(int *i, int *j, t_map *map)
{
	int	changed;

	if (*i == -1 && *j == -1)
	{
		*i = map->size_x - 1;
		*j = map->size_y;
	}
	changed = 0;
	if (*j > 0 )
	{
		*j -= 1;
		changed = 1;
	}
	else if(*i > 0)
	{
		*j = map->size_y - 1;
		*i -= 1;
		changed = 1;
	}
	return (changed);
}



int	generate_i_j(int *i, int *j, t_map *map)
{
	int	changed;

	changed = 0;
	if (map->theta > -0.7855 && map->theta <= 0.7855)
		changed = map_cover_q1(i, j, map);
	else if (map->theta > 0.7855 && map->theta <= 2.3565)
		changed = map_cover_q2(i, j, map);
	else if (map->theta <= -0.7855 && map->theta > -2.3565)
		changed = map_cover_q3(i, j, map);
	else
		changed = map_cover_q4(i, j, map);
	return (changed);
}
