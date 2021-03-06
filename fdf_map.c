/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:44:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/27 17:38:41 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int	count_cols(char *line)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

int	fdf_line_map(char *line, t_map *map)
{
	int		n;
	int		i;
	char	**strs;

	n = count_cols(line);
	i = fdf_extend_map(map, map->size_x + 1, n + 1);
	if (i < 0)
		return (-1);
	strs = ft_split(line, ' ');
	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
	{
		map->map[map->size_x - 1][i].exist = 1;
		map->map[map->size_x - 1][i].altitude = ft_atoi(strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

int	fdf_file_map(int fd, t_map *map)
{
	char	*line;
	int		i;

	(void)map;
	line = get_next_line(fd);
	while (line)
	{
		i = fdf_line_map(line, map);
		free(line);
		if (i < 0)
			return (-1);
		line = get_next_line(fd);
	}
	return (0);
}
