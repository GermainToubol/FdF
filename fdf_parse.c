/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:31:01 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 11:46:15 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include "fdf.h"

int	fdf_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fdf_error(filename);
		return (-1);
	}
	close(fd);
	fd = open(filename, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		errno = EISDIR;
		fdf_error(filename);
		close(fd);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fdf_error(filename);
		return (-1);
	}
	return (fd);
}
