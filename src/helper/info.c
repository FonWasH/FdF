/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:31:41 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_info(t_data *data)
{
	data->info.visible = true;
	data->info.width = I_OFFSET_X * (ft_strlen(I_SEP) + 2);
	data->info.height = (I_OFFSET_Y * I_LINE_COUNT) + I_OFFSET_X + 2;
	data->info.pos_x = I_POS_X + (I_OFFSET_X * (ft_strlen(I_NAME) + 2));
	data->info.color_box.x = data->info.pos_x;
	data->info.color_box.xm = data->info.pos_x + I_BOX_SIZE;
	data->info.color_box.ly = I_BOX_POS;
	data->info.color_box.lym = I_BOX_POS + I_BOX_SIZE;
	data->info.color_box.my = I_BOX_POS + I_OFFSET_Y;
	data->info.color_box.mym = I_BOX_POS + I_OFFSET_Y + I_BOX_SIZE;
	data->info.color_box.hy = I_BOX_POS + (I_OFFSET_Y * 2);
	data->info.color_box.hym = I_BOX_POS + (I_OFFSET_Y * 2) + I_BOX_SIZE;
	ft_new_image(data, &data->info.img, data->info.width, data->info.height);
}

static void	ft_draw_info_panel(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->info.width)
	{
		y = 0;
		while (y < data->info.height)
		{
			ft_put_pixel(&data->info.img, x, y,
				ft_info_color(data, x, y, data->info.color_box));
			y++;
		}
		x++;
	}
}

static void	ft_put_static_info(t_data *data)
{
	size_t				i;
	static const char	*str[25][2] = {
	{NULL, I_COLOR}, {NULL, I_COLOR_L}, {NULL, I_COLOR_M}, {NULL, I_COLOR_H},
	{NULL, I_SEP}, {NULL, I_KEY}, {I_K_HIDE, I_L_HIDE}, {I_K_FAST, I_L_FAST},
	{I_K_MOVE, I_L_MOVE}, {I_K_AXIS_X, I_L_AXIS_X}, {I_K_AXIS_Y, I_L_AXIS_Y},
	{I_K_AXIS_Z, I_L_AXIS_Z}, {I_K_ZOOM, I_L_ZOOM}, {I_K_DEPTH, I_L_DEPTH},
	{I_K_PRO, I_L_PRO}, {I_K_COLOR, I_L_COLOR}, {I_K_RESET, I_L_RESET},
	{I_K_CLOSE, I_L_CLOSE}, {NULL, I_MOUSE}, {I_M_MOVE, I_L_MOVE},
	{I_M_AXIS, I_L_AXIS_X}, {I_M_AXIS, I_L_AXIS_Z}, {I_M_ZOOM, I_L_ZOOM},
	{I_M_PRO, I_L_PRO}, {NULL, NULL}
	};

	i = 0;
	while (str[i][1])
	{
		ft_info_put_str(data, ft_line_pos(false),
			(char *)str[i][0], (char *)str[i][1]);
		i++;
	}
}

void	ft_refresh_info(t_data *data)
{
	char	*size;

	if (!data->info.visible)
		return ;
	ft_draw_info_panel(data);
	mlx_put_image_to_window(data->mlx, data->win, data->info.img.ptr,
		I_POS_X, I_POS_Y);
	ft_info_put_str(data, ft_line_pos(true), data->map.name, I_NAME);
	size = ft_size_str(data, data->map.width, data->map.height);
	ft_info_put_str(data, ft_line_pos(false), size, I_SIZE);
	free(size);
	size = ft_size_str(data, data->map.pos_x, data->map.pos_y);
	ft_info_put_str(data, ft_line_pos(false), size, I_POS);
	free(size);
	ft_info_put_nbr(data, ft_line_pos(false),
		(data->map.axis_x * MAP_ANGLE_MAX) / (PI * 2), I_AXIS_X);
	ft_info_put_nbr(data, ft_line_pos(false),
		(data->map.axis_y * MAP_ANGLE_MAX) / (PI * 2), I_AXIS_Y);
	ft_info_put_nbr(data, ft_line_pos(false),
		(data->map.axis_z * MAP_ANGLE_MAX) / (PI * 2), I_AXIS_Z);
	ft_info_put_fnbr(data, ft_line_pos(false), data->map.zoom, I_ZOOM);
	ft_info_put_fnbr(data, ft_line_pos(false), data->map.depth, I_DEPTH);
	ft_info_put_str(data, ft_line_pos(false), ft_pro_str(data->map.pro), I_PRO);
	ft_put_static_info(data);
}
