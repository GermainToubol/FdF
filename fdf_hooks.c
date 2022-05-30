/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:08 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 19:34:28 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	fdf_update_color(int key, t_params *params)
{
	if (key == NUM_8)
		params->map->color_width += 1;
	else if (key == NUM_2 && params->map->color_width > 1)
		params->map->color_width -= 1;
	else if (key == NUM_4)
		params->map->color_offset -= 1;
	else if (key == NUM_6)
		params->map->color_offset += 1;
	else if (key == NUM_5)
	{
		params->map->color_width = 4;
		params->map->color_offset = 0;
	}
	return (0);
}

int	show_key(int key, t_params *params)
{
	fdf_quit(key, params);
	fdf_zoom(key, params);
	fdf_move(key, params);
	fdf_rotate(key, params);
	fdf_reset_scale(key, params);
	fdf_update_color(key, params);
	if (key == 102)
		params->map->iso = !params->map->iso;
	return (0);
}

int	x_quit(t_params *params)
{
	fdf_quit(ESC_KEY, params);
	return (0);
}

int	draw_all(t_params *params)
{
	t_data		img;

	init_img(&img, params->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	display_map(params->map, &img);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, img.img, 0, 0);
	mlx_destroy_image(params->mlx_ptr, img.img);
	return (0);
}

int	render(t_params *params)
{
	if (params->win_ptr)
		draw_all(params);
	return (0);
}
