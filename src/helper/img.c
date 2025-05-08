/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:27:23 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_new_image(t_data *data, t_imgb *img, int width, int height)
{
	img->ptr = mlx_new_image(data->mlx, width, height);
	if (!img->ptr)
		ft_error(ERR_IMG, data, NULL, NULL);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		ft_error(ERR_GET, data, NULL, NULL);
}

void	ft_put_pixel(t_imgb *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = img->addr + (y * img->len + x * (img->bpp / BYTE));
	*(unsigned int *)pixel = color;
}
