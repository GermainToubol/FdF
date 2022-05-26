/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 17:38:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	show_key(int key, t_params	*params)
{
	(void)params;
	ft_printf("%d\n", key);
	if (key == ESC_KEY)
	{
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int			fd;
	t_map		map;
	t_params	params;

	if (argc == 1)
		return (0);
	if (argc != 2)
	{
		fdf_error_msg("fdf: Too many arguments.\n");
		return (1);
	}
	fd = fdf_open(argv[1]);
	if (fd < 0)
		return (1);
	fdf_init_map(&map);
	if (fdf_file_map(fd, &map) < 0)
	{
		close(fd);
		fdf_free_map(&map);
		return (-1);
	}
	close(fd);
	ft_printf("%d -- %d\n", map.size_x, map.size_y);
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, 500, 500, argv[1]);
	map.scale = 15;
	map.scale_z = 5;
	display_map(&map, params.mlx_ptr, params.win_ptr);
	fdf_free_map(&map);
	draw_color_map(params.mlx_ptr, params.win_ptr);
	mlx_hook(params.win_ptr, 2, 1L<<0, show_key, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
