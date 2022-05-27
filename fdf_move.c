/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:09:50 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 17:22:55 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int fdf_move(int key, t_params *params)
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

int fdf_reset_scale(int key, t_params *params)
{
	if (key == ESP_KEY)
	{
		fdf_init_map_param(params->map);
	}
	return (0);
}
