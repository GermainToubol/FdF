/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:39:31 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 11:10:44 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"
#include "libft.h"

unsigned int color_height(int height)
{
	float	h;
	float	scale;
	int		red_color;
	int		blue_color;

	scale = 0.2;
	h = (float)height;
	(void)height;
	red_color = 0xff / (1 + exp(- scale * (h - 4)));
	blue_color = 0xff / (1 + exp(scale * (h + 4)));
	return ((unsigned int)(red_color * 0x10000 + blue_color));
}

void	draw_color_map(void *mlx_ptr, void *win_ptr)
{
	int i;
	t_point pt1;
	t_point pt2;

	i = 200;
	while (i < 300)
	{
		pt1.x = 450;
		pt1.y = i;
		pt1.z = (250 - i) / 10;
		pt2.x = 480;
		pt2.y = i;
		pt2.z = (250 - i);
		trace_line(&pt1, &pt2, mlx_ptr, win_ptr);
		i++;
	}
}
