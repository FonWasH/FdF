/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:27:26 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:47:26 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_window(t_data *data)
{
	data->win = mlx_new_window(
			data->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data->win)
		ft_error(ERR_WIN, data, NULL, NULL);
}

int	ft_handle_win_config(int width, int height, t_data *data)
{
	(void)width;
	(void)height;
	data->map.refresh = true;
	return (0);
}
