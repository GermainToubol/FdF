/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_straight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:07:36 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 18:58:45 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

int	trace_horizontal(t_point *pt1, t_point *pt2, t_data *img, t_map *map)
{
	int	dx;
	int	i;

	dx = pt2->x - pt1->x;
	i = 0;
	if (dx > 0)
	{
		while (i < dx)
		{
			fdf_pixel_put(img, pt1->x + i, pt1->y, color_height((pt1->z
						+ pt2->z) / 2, map));
			i++;
		}
	}
	if (dx < 0)
	{
		while (i < -dx)
		{
			fdf_pixel_put(img, pt1->x - i, pt1->y, color_height((pt1->z
						+ pt2->z) / 2, map));
			i++;
		}
	}
	return (0);
}

int	trace_vertical(t_point *pt1, t_point *pt2, t_data *img, t_map *map)
{
	int	dy;
	int	i;

	dy = pt2->y - pt1->y;
	i = 0;
	if (dy > 0)
	{
		while (i < dy)
		{
			fdf_pixel_put(img, pt1->x, pt1->y + i, color_height((pt1->z
						+ pt2->z) / 2, map));
			i++;
		}
	}
	if (dy < 0)
	{
		while (i < -dy)
		{
			fdf_pixel_put(img, pt1->x, pt1->y - i, color_height((pt1->z
						+ pt2->z) / 2, map));
			i++;
		}
	}
	return (0);
}
