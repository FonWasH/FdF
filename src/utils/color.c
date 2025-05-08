/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:14:34 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_color(t_color color)
{
	static const int	c[12] = {
		C_RED, C_GREEN, C_BLUE,
		C_YELLOW, C_CYAN, C_MAGENTA,
		C_ORANGE, C_TURQUOISE, C_PURPLE,
		C_WHITE, C_GRAY, C_BLACK};

	return (c[color]);
}

int	ft_create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	ft_get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	ft_get_blue(int color)
{
	return (color & 0xFF);
}
