/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:49:40 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_gradient_color(double ratio, int color_l, int color_h)
{
	return (ft_create_color(
			ft_get_red(color_l) * (1 - ratio)
			+ ft_get_red(color_h) * ratio,
			ft_get_green(color_l) * (1 - ratio)
			+ ft_get_green(color_h) * ratio,
			ft_get_blue(color_l) * (1 - ratio)
			+ ft_get_blue(color_h) * ratio));
}

int	ft_height_color(t_data *data, int z)
{
	double	percent;

	if (data->map.z_min == data->map.z_max)
		return (ft_get_color(data->map.color_l));
	percent = (double)(z - data->map.z_min)
		/ (data->map.z_max - data->map.z_min);
	if (percent < 0)
		percent = 0;
	else if (percent > 1)
		percent = 1;
	if (percent < 0.5)
		return (ft_gradient_color(percent * 2,
				ft_get_color(data->map.color_l),
				ft_get_color(data->map.color_m)));
	return (ft_gradient_color((percent - 0.5) * 2,
			ft_get_color(data->map.color_m), ft_get_color(data->map.color_h)));
}

int	ft_line_color(t_data *data, t_point p, double ratio)
{
	if (p.color == ft_get_color(data->map.color_l)
		&& p.color_next == ft_get_color(data->map.color_h))
	{
		if (ratio < 0.5)
			return (ft_gradient_color(ratio / 0.5,
					ft_get_color(data->map.color_l),
					ft_get_color(data->map.color_m)));
		else
			return (ft_gradient_color((ratio - 0.5) / 0.5,
					ft_get_color(data->map.color_m),
					ft_get_color(data->map.color_h)));
	}
	else if (p.color == ft_get_color(data->map.color_h)
		&& p.color_next == ft_get_color(data->map.color_l))
	{
		if (ratio > 0.5)
			return (ft_gradient_color((ratio - 0.5) / 0.5,
					ft_get_color(data->map.color_m),
					ft_get_color(data->map.color_l)));
		else
			return (ft_gradient_color(ratio / 0.5,
					ft_get_color(data->map.color_h),
					ft_get_color(data->map.color_m)));
	}
	return (ft_gradient_color(ratio, p.color, p.color_next));
}

int	ft_info_color(t_data *data, int x, int y, t_cb box)
{
	if (x >= box.x && x <= box.xm && y >= box.ly && y <= box.lym)
		return (ft_get_color(data->map.color_l));
	else if (x >= box.x && x <= box.xm && y >= box.my && y <= box.mym)
		return (ft_get_color(data->map.color_m));
	else if (x >= box.x && x <= box.xm && y >= box.hy && y <= box.hym)
		return (ft_get_color(data->map.color_h));
	return (I_COLOR_B);
}
