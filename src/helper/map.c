/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:38:01 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_map_backup(t_data *data)
{
	data->map.backup.pos_x = -1;
	data->map.backup.pos_y = -1;
	data->map.backup.axis_x = -1;
	data->map.backup.axis_y = -1;
	data->map.backup.axis_z = -1;
	data->map.backup.zoom = -1;
	data->map.backup.pro = -1;
	data->map.backup.color_l = -1;
	data->map.backup.color_m = -1;
	data->map.backup.color_h = -1;
}

static void	ft_get_z_min_max(t_data *data)
{
	int		x;
	int		y;

	data->map.z_min = data->map.val[0][0];
	data->map.z_max = data->map.val[0][0];
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.val[y][x] < data->map.z_min)
				data->map.z_min = data->map.val[y][x];
			if (data->map.val[y][x] > data->map.z_max)
				data->map.z_max = data->map.val[y][x];
			x++;
		}
		y++;
	}
}

void	ft_init_map(t_data *data, char *map_path)
{
	data->map.refresh = true;
	data->map.name = ft_strrchr(map_path, SLASH);
	if (data->map.name)
		data->map.name++;
	else
		data->map.name = map_path;
	data->map.val = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.pos_x = WIN_WIDTH / 2;
	data->map.pos_y = WIN_HEIGHT / 2;
	data->map.axis_x = 0;
	data->map.axis_y = 0;
	data->map.axis_z = 0;
	data->map.zoom = 1;
	data->map.depth = 1;
	data->map.pro = ISOMETRIC;
	data->map.color_l = WHITE;
	data->map.color_m = YELLOW;
	data->map.color_h = RED;
	ft_init_map_backup(data);
	ft_parse_map(data, map_path);
	ft_get_z_min_max(data);
	ft_new_image(data, &data->map.img, WIN_WIDTH, WIN_HEIGHT);
}

static void	ft_draw_map_background(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ft_put_pixel(&data->map.img, x, y, C_BLACK);
			y++;
		}
		x++;
	}
}

void	ft_refresh_map(t_data *data)
{
	ft_draw_map_background(data);
	ft_draw_map(data, &data->map.p);
	mlx_put_image_to_window(data->mlx, data->win, data->map.img.ptr, 0, 0);
}
