/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:09:58 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_refresh_axis_key(t_data *data)
{
	if (data->key.axis_x_up && !data->key.axis_x_down)
		data->map.axis_x += (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
	if (data->key.axis_x_down && !data->key.axis_x_up)
		data->map.axis_x -= (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
	if (data->key.axis_y_up && !data->key.axis_y_down)
		data->map.axis_y -= (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
	if (data->key.axis_y_down && !data->key.axis_y_up)
		data->map.axis_y += (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
	if (data->key.axis_z_up && !data->key.axis_z_down)
		data->map.axis_z += (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
	if (data->key.axis_z_down && !data->key.axis_z_up)
		data->map.axis_z -= (double)K_AXIS_P + (K_AXIS_F * data->key.fast_mode);
}

void	ft_axis_key_press(int key, t_data *data)
{
	if (key == XK_Up)
		data->key.axis_x_up = true;
	else if (key == XK_Down)
		data->key.axis_x_down = true;
	else if (key == XK_Left)
		data->key.axis_y_up = true;
	else if (key == XK_Right)
		data->key.axis_y_down = true;
	else if (key == XK_q)
		data->key.axis_z_up = true;
	else if (key == XK_e)
		data->key.axis_z_down = true;
}

void	ft_axis_key_release(int key, t_data *data)
{
	if (key == XK_Up)
		data->key.axis_x_up = false;
	else if (key == XK_Down)
		data->key.axis_x_down = false;
	else if (key == XK_Left)
		data->key.axis_y_up = false;
	else if (key == XK_Right)
		data->key.axis_y_down = false;
	else if (key == XK_q)
		data->key.axis_z_up = false;
	else if (key == XK_e)
		data->key.axis_z_down = false;
}
