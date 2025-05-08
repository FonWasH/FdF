/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:02 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:44 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_convert_map(t_data *data, char **str)
{
	int	i;

	data->map.val = (int **)ft_realloc(data->map.val,
			sizeof(int *) * (data->map.height - 1),
			sizeof(int *) * data->map.height);
	if (!data->map.val)
		ft_error(ERR_MEM, data, NULL, str);
	data->map.val[data->map.height - 1] = (int *)malloc(
			sizeof(int) * data->map.width);
	if (!data->map.val[data->map.height - 1])
		ft_error(ERR_MEM, data, NULL, str);
	i = 0;
	while (i < data->map.width)
	{
		data->map.val[data->map.height - 1][i] = (int)ft_atol(str[i]);
		i++;
	}
}

void	ft_parse_map(t_data *data, char *map_path)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno), data, NULL, NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!data->map.width)
			data->map.width = ft_strcount(line, SPACE);
		data->map.height++;
		split_line = ft_split(line, SPACE);
		free(line);
		if (!split_line)
			ft_error(ERR_MEM, data, NULL, NULL);
		ft_convert_map(data, split_line);
		ft_mfree((void **)split_line, data->map.width);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_reset_map(t_data *data)
{
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
}
