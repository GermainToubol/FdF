/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

int	show_key(int key, t_params *params)
{
	fdf_quit(key, params);
	fdf_zoom(key, params);
	fdf_move(key, params);
	fdf_rotate(key, params);
	fdf_reset_scale(key, params);
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
