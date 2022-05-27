/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_straight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:07:36 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 15:31:31 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

int	trace_horizontal(t_point *pt1, t_point *pt2, t_data *img)
{
	int	dx;
	int	i;

	dx = pt2->x - pt1->x;
	i = 0;
	if (dx > 0)
	{
		while (i < dx)
		{
			fdf_pixel_put(img, pt1->x + i, pt2->y, color_height(pt1->z));
			i++;
		}
	}
	if (dx < 0)
	{
		while (i < -dx)
		{
			fdf_pixel_put(img, pt1->x - i, pt2->y, color_height(pt1->z));
			i++;
		}
	}
	return (0);
}

int	trace_vertical(t_point *pt1, t_point *pt2, t_data *img)
{
	int	dy;
	int	i;

	dy = pt2->y - pt1->y;
	i = 0;
	if (dy > 0)
	{
		while (i < dy)
		{
			fdf_pixel_put(img, pt1->x, pt2->y + i, color_height(pt1->z));
			i++;
		}
	}
	if (dy < 0)
	{
		while (i < -dy)
		{
			fdf_pixel_put(img, pt1->x, pt2->y - i, color_height(pt1->z));
			i++;
		}
	}
	return (0);
}
