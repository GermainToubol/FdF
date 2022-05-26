/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:15:29 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/26 11:34:19 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <errno.h>
#include <stdio.h>
#include "libft.h"
#include "fdf.h"

void	fdf_error(char *s)
{
	perror(s);
}

void	fdf_error_msg(char *s)
{
	ft_putstr_fd(s, 2);
}
