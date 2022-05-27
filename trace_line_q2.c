/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_q2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:37:05 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 15:31:08 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include  "libft.h"
#include "fdf.h"

int	trace_o4(t_point *pt1, t_point *pt2, t_data *img)
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
		fdf_pixel_put(img, pt1->x, pt1->y, color_height(pt1->z));
		pt1->x -= 1;
		if (pt1->x == pt2->x)
			return (0);
		e = e + dy;
		if (e >= 0)
		{
			pt1->y += 1;
			e += dx;
		}
	}
}

int	trace_o3(t_point *pt1, t_point *pt2, t_data *img)
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
		fdf_pixel_put(img, pt1->x, pt1->y, color_height(pt1->z));
		pt1->y += 1;
		if (pt1->y == pt2->y)
			return (0);
		e = e + dx;
		if (e <= 0)
		{
			pt1->x -= 1;
			e += dy;
		}
	}
}

int	trace_o5(t_point *pt1, t_point *pt2, t_data *img)
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
		fdf_pixel_put(img, pt1->x, pt1->y, color_height(pt1->z));
		pt1->x -= 1;
		if (pt1->x == pt2->x)
			return (0);
		e = e - dy;
		if (e >= 0)
		{
			pt1->y -= 1;
			e += dx;
		}
	}
}

int	trace_o6(t_point *pt1, t_point *pt2, t_data *img)
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
		fdf_pixel_put(img, pt1->x, pt1->y, color_height(pt1->z));
		pt1->y -= 1;
		if (pt1->y == pt2->y)
			return (0);
		e = e - dx;
		if (e >= 0)
		{
			pt1->x -= 1;
			e += dy;
		}
	}
}
