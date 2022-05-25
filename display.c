/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:39:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 18:32:08 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void dessine(void *mlx_ptr, void *win_ptr)
{
	t_point	origin;
	t_point	pt1;
	t_point pt2;
	int scale = 10;
	int i;
	int j;

	origin.x = 250;
	origin.y = 50;
	i = 0;
	while (i < 20)
	{
		j = 0;
		pt1.x = origin.x + (int)(i * scale * (sqrt(3) / 2));
		while (j < 20)
		{

			pt1.x = origin.x + (int)((i - j) * scale * (sqrt(3) / 2));
			pt1.y = origin.y + (i + j) * scale / 2;
			// same Y
			pt2.x = origin.x + (int)((i + 1 - j) * scale * (sqrt(3) / 2));
			pt2.y = origin.y + (i + j + 1) * scale / 2;
			trace_line(&pt1, &pt2, mlx_ptr, win_ptr);
			// same X
			pt1.x = origin.x + (int)((i - j) * scale * (sqrt(3) / 2));
			pt1.y = origin.y + (i + j) * scale / 2;
			pt2.x = origin.x + (int)((i - j - 1) * scale * (sqrt(3) / 2));
			pt2.y = origin.y + (i + j + 1) * scale / 2;
			trace_line(&pt1, &pt2, mlx_ptr, win_ptr);
			j++;
		}
		i++;
	}

}
