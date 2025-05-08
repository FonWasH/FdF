/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:17:16 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_mouse(t_data *data)
{
	data->mouse.x = 0;
	data->mouse.y = 0;
	data->mouse.left = false;
	data->mouse.right = false;
}

int	ft_button_press(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK)
		data->mouse.left = true;
	else if (button == MIDDLE_CLICK)
		data->map.pro++;
	else if (button == RIGHT_CLICK)
		data->mouse.right = true;
	else if (button == WHEEL_UP)
		data->map.zoom += (double)M_ZOOM_P + (M_ZOOM_F * data->key.fast_mode);
	else if (button == WHEEL_DOWN)
		data->map.zoom -= (double)M_ZOOM_P + (M_ZOOM_F * data->key.fast_mode);
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

int	ft_button_release(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK)
		data->mouse.left = false;
	else if (button == RIGHT_CLICK)
		data->mouse.right = false;
	(void)x;
	(void)y;
	return (0);
}

int	ft_mouse_motion(int x, int y, t_data *data)
{
	if (data->mouse.left)
	{
		data->map.pos_x += (double)(x - data->mouse.x)
			/ (M_MOVE_P - (M_MOVE_F * data->key.fast_mode));
		data->map.pos_y += (double)(y - data->mouse.y)
			/ (M_MOVE_P - (M_MOVE_F * data->key.fast_mode));
	}
	if (data->mouse.right)
	{
		data->map.axis_x -= (double)(y - data->mouse.y)
			/ (M_AXIS_P - (M_AXIS_F * data->key.fast_mode));
		data->map.axis_z -= (double)(x - data->mouse.x)
			/ (M_AXIS_P - (M_AXIS_F * data->key.fast_mode));
	}
	return (0);
}
