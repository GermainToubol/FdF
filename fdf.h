/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:51:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 18:04:04 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int	trace_o1(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o2(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o3(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o4(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o5(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o6(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o7(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_o8(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);

int	trace_horizontal(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
int	trace_vertical(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);

int	trace_line(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);
void dessine(void *mlx_ptr, void *win_ptr);
#endif
