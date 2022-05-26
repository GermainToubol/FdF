/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:51:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 15:54:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

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
	int			size_x;
	int			size_y;
	t_map_point	**map;
}	t_map;

int		trace_o1(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o2(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o3(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o4(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o5(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o6(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o7(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_o8(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);

int		trace_horizontal(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int		trace_vertical(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);

int		trace_line(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
void	display_map(t_map *map, void *mlx_ptr, void *win_ptr);

unsigned int color_height(int height);
void	draw_color_map(void *mlx_ptr, void *win_ptr);

void	fdf_init_map(t_map *map);
void	fdf_free_map(t_map *map);

int	fdf_open(char *filename);
int	fdf_file_map(int fd, t_map *map);
int	fdf_extend_map(t_map *map, int x, int y);

void	fdf_error(char *s);
void	fdf_error_msg(char *s);
#endif
