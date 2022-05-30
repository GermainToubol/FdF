/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:09:50 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 15:01:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fdf.h"

int	fdf_move(int key, t_params *params)
{
	if (key == A_KEY)
		params->map->origin.x -= params->map->scale;
	if (key == D_KEY)
		params->map->origin.x += params->map->scale;
	if (key == W_KEY)
		params->map->origin.y -= params->map->scale;
	if (key == S_KEY)
		params->map->origin.y += params->map->scale;
	return (0);
}

int	fdf_reset_scale(int key, t_params *params)
{
	if (key == ESP_KEY)
	{
		fdf_init_map_param(params->map);
	}
	return (0);
}

int	fdf_rotate(int key, t_params *params)
{
	int	has_rot;

	has_rot = 0;
	if (key == Q_KEY)
	{
		has_rot = 1;
		params->map->theta += 0.1;
		if (params->map->theta > 3.14)
			params->map->theta -= 6.28;
	}
	if (key == E_KEY)
	{
		has_rot = 1;
		params->map->theta -= 0.1;
		if (params->map->theta < -3.14)
			params->map->theta += 6.28;
	}
	if (has_rot)
	{
		params->map->cos_theta = cos(params->map->theta);
		params->map->sin_theta = sin(params->map->theta);
	}
	return (0);
}
