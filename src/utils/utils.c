/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:59:10 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_data *data, char *map_path)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.img.ptr = NULL;
	data->info.img.ptr = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(ERR_MLX, data, NULL, NULL);
	ft_init_window(data);
	ft_init_map(data, map_path);
	ft_init_info(data);
	ft_init_keys(data);
	ft_init_mouse(data);
}

static int	ft_refresh(t_data *data)
{
	ft_refresh_keys(data);
	ft_check_map_values(data);
	ft_check_map_refresh(data);
	if (data->map.refresh)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_refresh_map(data);
		ft_refresh_info(data);
		data->map.refresh = false;
	}
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, ft_key_release, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask,
		ft_button_press, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask,
		ft_button_release, data);
	mlx_hook(data->win, MotionNotify,
		PointerMotionMask, ft_mouse_motion, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask,
		ft_close, data);
	mlx_hook(data->win, ConfigureNotify, StructureNotifyMask,
		ft_handle_win_config, data);
	mlx_loop_hook(data->mlx, ft_refresh, data);
}

void	ft_destroy(t_data *data)
{
	if (data->map.val)
		ft_mfree((void **)data->map.val, data->map.height);
	if (data->info.img.ptr)
		mlx_destroy_image(data->mlx, data->info.img.ptr);
	if (data->map.img.ptr)
		mlx_destroy_image(data->mlx, data->map.img.ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	ft_close(t_data *data)
{
	ft_destroy(data);
	exit(EXIT_SUCCESS);
	return (0);
}
