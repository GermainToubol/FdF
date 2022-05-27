/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 15:33:09 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

/* Line tracing using the Bresenham algorithm. 								  */

void	trace_line(t_point *pt1, t_point *pt2, t_data *img)
{
	int	dx;
	int	dy;

	dx = pt2->x - pt1->x;
	dy = pt2->y - pt1->y;
	if (dx > 0 && dy > 0 && dx >= dy)
		trace_o1(pt1, pt2, img);
	if (dx > 0 && dy > 0 && dx < dy)
		trace_o2(pt1, pt2, img);
	if (dx < 0 && dy > 0 && dy > -dx)
		trace_o3(pt1, pt2, img);
	if (dx < 0 && dy > 0 && dy <= -dx)
		trace_o4(pt1, pt2, img);
	if (dx < 0 && dy < 0 && dx <= dy)
		trace_o5(pt1, pt2, img);
	if (dx < 0 && dy < 0 && dx > dy)
		trace_o6(pt1, pt2, img);
	if (dx > 0 && dy < 0 && dx < -dy)
		trace_o7(pt1, pt2, img);
	if (dx > 0 && dy < 0 && dx >= -dy)
		trace_o8(pt1, pt2, img);
	if (dx && !dy)
		trace_horizontal(pt1, pt2, img);
	if (dy && !dx)
		trace_vertical(pt1, pt2, img);
}
