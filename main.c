/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 16:12:14 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	deal_key(int key, void *param)
{
	(void)param;
	ft_printf("%d\n", key);
	return (0);
}

/*
int main()
{
	void *mlx_ptr;
	void *win_ptr;
	t_map map;
	int		**carte;

	carte = ft_calloc(20, sizeof(*carte));
	for(int i = 0; i < 20; i++)
	{
		carte[i] = ft_calloc(30, sizeof(**carte));
		for (int j = 0; j < 30; j++)
		{
			carte[i][j] = 0;
			if (i > 7 && j > 7)
				carte[i][j] = 7;
			if (i > 15 && j > 20)
				carte[i][j] = -2;
		}
	}
	map.size_x = 20;
	map.size_y = 30;
	map.scale = 10;
	map.map = carte;
	ft_printf("coucou\n");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "elx 40");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	ft_printf("coucou\n");
	(void)map;
	display_map(&map, mlx_ptr, win_ptr);
	draw_color_map(mlx_ptr, win_ptr);
	ft_printf("coucou\n");
	mlx_loop(mlx_ptr);
}
*/

int main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	void *mlx_ptr;
	void *win_ptr;

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
	ft_printf("%d -- %d\n", map.size_x, map.size_y);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "elx 40");
	map.scale = 10;
	display_map(&map, mlx_ptr, win_ptr);
	fdf_free_map(&map);
	draw_color_map(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (close(fd));
}
