/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 14:15:02 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	deal_key(int key, void *param)
{
	(void)param;
	ft_printf("%d\n", key);
	return (0);
}



int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	t_point pt1;
	t_point pt2;

	(void) argc;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "elx 40");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	pt1.x = ft_atoi(argv[1]);
	pt1.y = ft_atoi(argv[2]);
	pt2.x = ft_atoi(argv[3]);
	pt2.y = ft_atoi(argv[4]);
	trace_ray(&pt1, &pt2, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}
