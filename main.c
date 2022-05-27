/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 17:26:56 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	show_key(int key, t_params *params)
{
	ft_printf("%d\n", key);
	fdf_quit(key, params);
	fdf_zoom(key, params);
	fdf_move(key, params);
	fdf_reset_scale(key, params);
	return (0);
}


int	draw_all(t_params *params)
{
	t_data		img;

	init_img(&img, params->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	display_map(params->map, &img);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, img.img, 0, 0);
	mlx_destroy_image(params->mlx_ptr,img.img);
	return (0);
}

int render(t_params *params)
{
	if (params->win_ptr)
		draw_all(params);
	return (0);
}

int	fdf_init_main(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
	{
		fdf_error_msg("fdf: Too many arguments.\n");
		return (1);
	}
	fd = fdf_open(argv[1]);
	if (fd < 0)
		return (1);
	fdf_init_map(map);
	if (fdf_file_map(fd, map) < 0)
	{
		close(fd);
		fdf_free_map(map);
		return (-1);
	}
	if (close(fd))
	{
		fdf_free_map(map);
		return (-1);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_map		map;
	t_params	params;

	if (argc == 1)
		return (0);
	if (fdf_init_main(argc, argv, &map))
		return (-1);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			argv[1]);
	params.map = &map;
	ft_printf("%d -- %d\n", map.size_x, map.size_y);
	fdf_init_map_param(&map);
	mlx_loop_hook(params.mlx_ptr, render, &params);
	mlx_hook(params.win_ptr, 2, 1L << 0, show_key, &params);
	mlx_loop(params.mlx_ptr);
	mlx_destroy_display(params.mlx_ptr);
	free(params.mlx_ptr);
	return (0);
}
