/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:39:31 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 19:22:35 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"
#include "libft.h"

unsigned int	color_height(int height, t_map *map)
{
	float	h;
	float	scale;
	int		red_color;
	int		blue_color;

	scale = 0.2 / 4 * map->color_width;
	h = (float)height;
	(void)height;
	red_color = 0xff / (1 + exp(-scale
				* (h - (map->color_offset + map->color_width))));
	blue_color = 0xff / (1 + exp(scale
				* (h - (map->color_offset - map->color_width))));
	if (red_color > 0x25 || blue_color > 0x25)
		return ((unsigned int)((red_color << 16) + blue_color));
	else
		return (0x250025);
}

void	draw_color_map(t_data *img, t_map *map)
{
	int		i;
	t_point	pt1;
	t_point	pt2;

	i = 200;
	while (i < 300)
	{
		pt1.x = WIN_WIDTH - 50;
		pt1.y = i;
		pt1.z = (250 - i) / 10;
		pt2.x = WIN_WIDTH - 20;
		pt2.y = i;
		pt2.z = (250 - i);
		trace_line(&pt1, &pt2, img, map);
		i++;
	}
}
