/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:51:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 13:26:22 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int	trace_ray(t_point *pt1, t_point *pt2, void *mlx_ptr, void *win_ptr);

#endif
