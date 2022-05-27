/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:56:59 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 17:03:37 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "mlx.h"
#include "fdf.h"

int	fdf_quit(int key, t_params *params)
{
	if (key == ESC_KEY)
	{
		fdf_free_map(params->map);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		params->win_ptr = NULL;
	}
	return (0);
}
