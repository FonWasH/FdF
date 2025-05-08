/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:54:17 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_keys(t_data *data)
{
	data->key.fast_mode = false;
	data->key.move_up = false;
	data->key.move_down = false;
	data->key.move_left = false;
	data->key.move_right = false;
	data->key.axis_x_up = false;
	data->key.axis_x_down = false;
	data->key.axis_y_up = false;
	data->key.axis_y_down = false;
	data->key.axis_z_up = false;
	data->key.axis_z_down = false;
	data->key.zoom_in = false;
	data->key.zoom_out = false;
	data->key.depth_up = false;
	data->key.depth_down = false;
}

void	ft_refresh_keys(t_data *data)
{
	ft_refresh_axis_key(data);
	if (data->key.move_up && !data->key.move_down)
		data->map.pos_y -= (double)K_MOVE_P + (K_MOVE_F * data->key.fast_mode);
	if (data->key.move_down && !data->key.move_up)
		data->map.pos_y += (double)K_MOVE_P + (K_MOVE_F * data->key.fast_mode);
	if (data->key.move_right && !data->key.move_left)
		data->map.pos_x += (double)K_MOVE_P + (K_MOVE_F * data->key.fast_mode);
	if (data->key.move_left && !data->key.move_right)
		data->map.pos_x -= (double)K_MOVE_P + (K_MOVE_F * data->key.fast_mode);
	if (data->key.zoom_in && !data->key.zoom_out)
		data->map.zoom += (double)K_ZOOM_P + (K_ZOOM_F * data->key.fast_mode);
	if (data->key.zoom_out && !data->key.zoom_in)
		data->map.zoom -= (double)K_ZOOM_P + (K_ZOOM_F * data->key.fast_mode);
	if (data->key.depth_up && !data->key.depth_down)
		data->map.depth += (double)K_DEPT_P + (K_DEPT_F * data->key.fast_mode);
	if (data->key.depth_down && !data->key.depth_up)
		data->map.depth -= (double)K_DEPT_P + (K_DEPT_F * data->key.fast_mode);
}

static void	ft_handle_key(t_data *data, int key)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == XK_space)
		ft_reset_map(data);
	else if (key == XK_Tab)
	{
		data->info.visible = !data->info.visible;
		data->map.refresh = true;
	}
	else if (key == XK_v)
		data->map.pro++;
	else if (key == XK_z)
		data->map.color_l++;
	else if (key == XK_x)
		data->map.color_m++;
	else if (key == XK_c)
		data->map.color_h++;
}

int	ft_key_press(int key, t_data *data)
{
	ft_axis_key_press(key, data);
	if (key == XK_Shift_L)
		data->key.fast_mode = true;
	else if (key == XK_w)
		data->key.move_up = true;
	else if (key == XK_a)
		data->key.move_left = true;
	else if (key == XK_s)
		data->key.move_down = true;
	else if (key == XK_d)
		data->key.move_right = true;
	else if (key == XK_r)
		data->key.zoom_in = true;
	else if (key == XK_f)
		data->key.zoom_out = true;
	else if (key == XK_t)
		data->key.depth_up = true;
	else if (key == XK_g)
		data->key.depth_down = true;
	else
		ft_handle_key(data, key);
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	ft_axis_key_release(key, data);
	if (key == XK_Shift_L)
		data->key.fast_mode = false;
	else if (key == XK_w)
		data->key.move_up = false;
	else if (key == XK_a)
		data->key.move_left = false;
	else if (key == XK_s)
		data->key.move_down = false;
	else if (key == XK_d)
		data->key.move_right = false;
	else if (key == XK_r)
		data->key.zoom_in = false;
	else if (key == XK_f)
		data->key.zoom_out = false;
	else if (key == XK_t)
		data->key.depth_up = false;
	else if (key == XK_g)
		data->key.depth_down = false;
	return (0);
}
