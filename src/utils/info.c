/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:38:31 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_info_put_str(t_data *data, int offset, char *str, char *label)
{
	mlx_string_put(data->mlx, data->win,
		I_POS_X + I_OFFSET_X, I_POS_Y + offset, C_BLACK, label);
	if (str)
		mlx_string_put(data->mlx, data->win, data->info.pos_x,
			I_POS_Y + offset, C_WHITE, str);
}

void	ft_info_put_nbr(t_data *data, int offset, int n, char *label)
{
	char	*nbr;

	nbr = ft_ltoa(n);
	mlx_string_put(data->mlx, data->win,
		I_POS_X + I_OFFSET_X, I_POS_Y + offset, C_BLACK, label);
	mlx_string_put(data->mlx, data->win, data->info.pos_x,
		I_POS_Y + offset, C_WHITE, nbr);
	free(nbr);
}

void	ft_info_put_fnbr(t_data *data, int offset, double n, char *label)
{
	char	*nbr;

	nbr = ft_double_str(data, n);
	mlx_string_put(data->mlx, data->win,
		I_POS_X + I_OFFSET_X, I_POS_Y + offset, C_BLACK, label);
	mlx_string_put(data->mlx, data->win, data->info.pos_x,
		I_POS_Y + offset, C_WHITE, nbr);
	free(nbr);
}

int	ft_line_pos(bool first)
{
	static int	offset;

	if (first)
		offset = I_OFFSET_Y;
	else
		offset += I_OFFSET_Y;
	return (offset);
}
