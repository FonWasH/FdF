/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:33:05 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *y, double *z, double angle)
{
	double	temp_y;
	double	temp_z;

	temp_y = *y;
	temp_z = *z;
	*y = temp_y * cos(angle) - temp_z * sin(angle);
	*z = temp_y * sin(angle) + temp_z * cos(angle);
}

void	rotate_y(double *x, double *z, double angle)
{
	double	temp_x;
	double	temp_z;

	temp_x = *x;
	temp_z = *z;
	*x = temp_x * cos(angle) + temp_z * sin(angle);
	*z = -temp_x * sin(angle) + temp_z * cos(angle);
}

void	rotate_z(double *x, double *y, double angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(angle) - temp_y * sin(angle);
	*y = temp_x * sin(angle) + temp_y * cos(angle);
}
