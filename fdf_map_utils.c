/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:33:57 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 14:25:18 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
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
	map->size_x = 0;
	map->size_y = 0;
}
