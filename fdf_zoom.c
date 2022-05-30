/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:00:45 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 13:42:29 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_zoom(int key, t_params *params)
{
	if (key == NUM_PLUS_KEY)
		params->map->scale_z++;
	if (key == NUM_MINUS_KEY)
	{
		if (params->map->scale_z > 1)
			params->map->scale_z--;
	}
	if (key == KEY_1)
		params->map->scale++;
	if (key == KEY_2 && params->map->scale > 1)
		params->map->scale--;
	return (0);
}
