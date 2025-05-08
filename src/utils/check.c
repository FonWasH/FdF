/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:13:50 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_check_map_fvalues(t_data *data)
{
	if (data->map.pos_x > WIN_WIDTH)
		data->map.pos_x = WIN_WIDTH;
	if (data->map.pos_y > WIN_HEIGHT)
		data->map.pos_y = WIN_HEIGHT;
	if (data->map.axis_x < 0)
		data->map.axis_x = PI * 2;
	if (data->map.axis_x > (PI * 2))
		data->map.axis_x = 0;
	if (data->map.axis_y < 0)
		data->map.axis_y = PI * 2;
	if (data->map.axis_y > (PI * 2))
		data->map.axis_y = 0;
	if (data->map.axis_z < 0)
		data->map.axis_z = PI * 2;
	if (data->map.axis_z > (PI * 2))
		data->map.axis_z = 0;
}

void	ft_check_map_values(t_data *data)
{
	ft_check_map_fvalues(data);
	if (data->map.zoom < MAP_ZOOM_MIN)
		data->map.zoom = MAP_ZOOM_MIN;
	if (data->map.zoom > MAP_ZOOM_MAX)
		data->map.zoom = MAP_ZOOM_MAX;
	if (data->map.depth < MAP_DEPTH_MIN)
		data->map.depth = MAP_DEPTH_MIN;
	if (data->map.depth > MAP_DEPTH_MAX)
		data->map.depth = MAP_DEPTH_MAX;
	if (data->map.pro > PARALLEL)
		data->map.pro = ISOMETRIC;
	if (data->map.color_l > BLACK)
		data->map.color_l = RED;
	if (data->map.color_m > BLACK)
		data->map.color_m = RED;
	if (data->map.color_h > BLACK)
		data->map.color_h = RED;
}

void	ft_check_map_refresh(t_data *data)
{
	if ((data->map.backup.pos_x != data->map.pos_x)
		|| (data->map.backup.pos_y != data->map.pos_y)
		|| (data->map.backup.axis_x != data->map.axis_x)
		|| (data->map.backup.axis_y != data->map.axis_y)
		|| (data->map.backup.axis_z != data->map.axis_z)
		|| (data->map.backup.zoom != data->map.zoom)
		|| (data->map.backup.depth != data->map.depth)
		|| (data->map.backup.pro != data->map.pro)
		|| (data->map.backup.color_l != data->map.color_l)
		|| (data->map.backup.color_m != data->map.color_m)
		|| (data->map.backup.color_h != data->map.color_h))
	{
		data->map.backup.pos_x = data->map.pos_x;
		data->map.backup.pos_y = data->map.pos_y;
		data->map.backup.axis_x = data->map.axis_x;
		data->map.backup.axis_y = data->map.axis_y;
		data->map.backup.axis_z = data->map.axis_z;
		data->map.backup.zoom = data->map.zoom;
		data->map.backup.depth = data->map.depth;
		data->map.backup.pro = data->map.pro;
		data->map.backup.color_l = data->map.color_l;
		data->map.backup.color_m = data->map.color_m;
		data->map.backup.color_h = data->map.color_h;
		data->map.refresh = true;
	}
}
