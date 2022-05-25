/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 14:12:19 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

/* Ray tracing using the Bresenham algorithm. 								  */

static int	trace_q1(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	e = dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pt1->x, pt1->y, 0xFFFFFF);
		pt1->x += 1;
		if (pt1->x == pt2->x)
			return (0);
		e = e - dy;
		if (e < 0)
		{
			pt1->y += 1;
			e += dx;
		}
	}
}

static int	trace_q2(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	e = dy;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pt1->x, pt1->y, 0xFFFFFF);
		pt1->y += 1;
		if (pt1->y == pt2->y)
			return (0);
		e = e - dx;
		if (e < 0)
		{
			pt1->x += 1;
			e += dy;
		}
	}
}

int	trace_ray(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;

	if (pt1->x > pt2->x)
		trace_ray(pt2, pt1, mlx_ptr, win_ptr);
	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx == 0 && dy == 0)
		return (0);
	if (dx == 0 && dy != 0)
		return (0);
	if (dy == 0 && dx != 0)
		return (0);
	if (dx >= dy)
		return (trace_q1(pt1, pt2, mlx_ptr, win_ptr));
	trace_q2(pt1, pt2, mlx_ptr, win_ptr);
	return (0);
}
