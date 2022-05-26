/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extend_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:02:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 14:27:56 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

/* fdf_map_linencpy:
 *
 * Copy the content of src in dest. If src is NULL, set each point of dest
 * to zero.
 *
 */

static void	fdf_map_linencpy(t_map_point *dest, t_map_point *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (src == NULL)
		{
			dest[i].exist = 0;
			dest[i].altitude = 0;
		}
		else
		{
			dest[i].exist = src[i].exist;
			dest[i].altitude = dest[i].altitude;
		}
		i++;
	}
}

static int	fdf_extend_map_y(t_map *map, int y)
{
	int			i;
	t_map_point	*newline;

	if (map->size_y >= y)
		return (0);
	i = 0;
	while (i < map->size_x)
	{
		newline = ft_calloc(y, sizeof(*newline));
		if (!newline)
			return (-1);
		fdf_map_linencpy(newline, map->map[i], map->size_y);
		fdf_map_linencpy(newline + map->size_y, NULL, y - map->size_y);
		free(map->map[i]);
		map->map[i] = newline;
		i++;
	}
	map->size_y = y;
	return (0);
}

static int	fdf_extend_map_x(t_map *map, int x)
{
	int			i;
	t_map_point	**newtab;
	t_map_point	*newline;

	if (map->size_x >= x)
		return (0);
	newtab = ft_calloc(x, sizeof(*newtab));
	if (!newtab)
		return (-1);
	i = -1;
	while (++i < map->size_x)
		newtab[i] = map->map[i];
	free(map->map);
	map->map = newtab;
	while (i < x)
	{
		newline = ft_calloc(map->size_y, sizeof(*newline));
		if (!newline)
			return (-1);
		fdf_map_linencpy(newline, NULL, map->size_y);
		map->map[i] = newline;
		i++;
	}
	map->size_x = x;
	return (0);
}

int	fdf_extend_map(t_map *map, int x, int y)
{
	int	i;

	i = fdf_extend_map_y(map, y);
	if (i < 0)
		return (-1);
	i = fdf_extend_map_x(map, x);
	return (i);
}
