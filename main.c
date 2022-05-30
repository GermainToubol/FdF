/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 19:32:02 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

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

int	fdf_init_mlx(t_params *params, char *filename)
{
	params->mlx_ptr = mlx_init();
	if (params->mlx_ptr == NULL)
		return (1);
	params->win_ptr = mlx_new_window(params->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			filename);
	if (params->win_ptr == NULL)
	{
		free(params->mlx_ptr);
		return (1);
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
		return (1);
	if (fdf_init_mlx(&params, argv[1]))
		return (1);
	params.map = &map;
	fdf_init_map_param(&map);
	map.iso = 1;
	mlx_loop_hook(params.mlx_ptr, render, &params);
	mlx_hook(params.win_ptr, 2, 1L << 0, show_key, &params);
	mlx_hook(params.win_ptr, 17, 0, x_quit, &params);
	mlx_loop(params.mlx_ptr);
	mlx_destroy_display(params.mlx_ptr);
	free(params.mlx_ptr);
	return (0);
}
