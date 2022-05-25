/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_straight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:07:36 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 17:20:52 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

int	trace_horizontal(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int i;

	dx = pt2->x - pt1->x;
	i = 0;
	if (dx > 0)
	{
		while (i < dx)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pt1->x + i, pt1->y, 0xFFFFFF);
			i++;
		}
	}
	if (dx < 0)
	{
		while (i < -dx)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pt1->x - i, pt1->y, 0xFFFFFF);
			i++;
		}
	}
	return (0);
}

int	trace_vertical(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr)
{
	int	dy;
	int i;

	dy = pt2->y - pt1->y;
	i = 0;
	if (dy > 0)
	{
		while (i < dy)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pt1->x, pt1->y + i, 0xFFFFFF);
			i++;
		}
	}
	if (dy < 0)
	{
		while (i < -dy)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, pt1->x, pt1->y - i, 0xFFFFFF);
			i++;
		}
	}
	return (0);
}
