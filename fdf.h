/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:51:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/30 15:52:26 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080

enum e_keys
{
	ESC_KEY = 65307,
	ESP_KEY = 32,
	NUM_PLUS_KEY = 65453,
	NUM_MINUS_KEY = 65451,
	W_KEY = 119,
	S_KEY = 115,
	A_KEY = 97,
	D_KEY = 100,
	KEY_1 = 49,
	KEY_2 = 50,
	Q_KEY = 113,
	E_KEY = 101
};

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map_point
{
	char	exist;
	int		altitude;

}	t_map_point;

typedef struct s_map
{
	int			scale;
	int			scale_z;
	t_point		origin;
	float		centering;
	int			size_x;
	int			size_y;
	float		theta;
	float		sin_theta;
	float		cos_theta;
	int			iso;
	t_map_point	**map;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}	t_params;

int				trace_o1(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o2(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o3(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o4(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o5(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o6(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o7(t_point *pt1, t_point *pt2, t_data *img);
int				trace_o8(t_point *pt1, t_point *pt2, t_data *img);

int				trace_horizontal(t_point *pt1, t_point *pt2, t_data *img);
int				trace_vertical(t_point *pt1, t_point *pt2, t_data *img);

void			trace_line(t_point *pt1, t_point *pt2, t_data *img);
void			display_map(t_map *map, t_data *img);

void			init_img(t_data *img, void *mlx_ptr, int width, int height);
void			fdf_pixel_put(t_data *data, int x, int y, int color);

unsigned int	color_height(int height);
void			draw_color_map(t_data *img);

void			fdf_init_map(t_map *map);
void			fdf_free_map(t_map *map);
void			fdf_init_map_param(t_map *map);

int				fdf_open(char *filename);
int				fdf_file_map(int fd, t_map *map);
int				fdf_extend_map(t_map *map, int x, int y);

void			fdf_error(char *s);
void			fdf_error_msg(char *s);

int				show_key(int key, t_params *params);
int				x_quit(t_params *params);
int				draw_all(t_params *params);
int				render(t_params *params);

int	generate_i_j(int *i, int *j, t_map *map);
void	fdf_set_pt_coordinates(int x, int y, t_point *pt, t_map *map);

int				fdf_quit(int key, t_params *params);
int				fdf_zoom(int key, t_params *params);
int				fdf_move(int key, t_params *params);
int				fdf_rotate(int key, t_params *params);
int				fdf_reset_scale(int key, t_params *params);
#endif
