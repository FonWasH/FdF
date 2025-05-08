/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:33:35 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_line(t_line *l, t_point p)
{
	l->delta_x = ft_abs(p.next_draw_x - p.draw_x);
	l->delta_y = ft_abs(p.next_draw_y - p.draw_y);
	l->step_x = -1 + (2 * (p.draw_x < p.next_draw_x));
	l->step_y = -1 + (2 * (p.draw_y < p.next_draw_y));
	l->error = l->delta_x - l->delta_y;
	if (l->delta_x > l->delta_y)
		l->len = l->delta_x;
	else
		l->len = l->delta_y;
	l->i = 0;
}

static void	ft_next_pixel(t_line *l, t_point *p)
{
	l->error_double = 2 * l->error;
	if (l->error_double > -l->delta_y)
	{
		l->error -= l->delta_y;
		p->draw_x += l->step_x;
	}
	if (l->error_double < l->delta_x)
	{
		l->error += l->delta_x;
		p->draw_y += l->step_y;
	}
}

static void	ft_draw_line(t_data *data, t_point p)
{
	t_line	l;

	ft_init_line(&l, p);
	while (l.i++ <= l.len)
	{
		if ((p.draw_x >= WIN_WIDTH || p.draw_x < 0)
			&& (p.draw_y >= WIN_HEIGHT || p.draw_y < 0))
			break ;
		if (l.len == 0)
			l.ratio = 0.0;
		else
			l.ratio = (double)l.i / l.len;
		ft_put_pixel(&data->map.img, p.draw_x, p.draw_y,
			ft_line_color(data, p, l.ratio));
		ft_next_pixel(&l, &p);
	}
}

static void	ft_iso_transform(t_data *data, int *draw_x, int *draw_y, int *color)
{
	double	x;
	double	y;
	double	z;

	x = data->map.p.x;
	y = data->map.p.y;
	z = data->map.val[data->map.p.y][data->map.p.x] * data->map.depth;
	*color = ft_height_color(data, data->map.val[data->map.p.y][data->map.p.x]);
	rotate_x(&y, &z, data->map.axis_x);
	rotate_y(&x, &z, data->map.axis_y);
	rotate_z(&x, &y, data->map.axis_z);
	if (data->map.pro == ISOMETRIC)
	{
		*draw_x = ((x - y) * (MAP_SCALE * data->map.zoom)) + data->map.pos_x;
		*draw_y = ((x + y) * (MAP_SCALE * data->map.zoom)
				/ 2 - z) + data->map.pos_y;
	}
	else if (data->map.pro == PARALLEL)
	{
		*draw_x = (x * (data->map.zoom * 10)) + data->map.pos_x;
		*draw_y = (y * (data->map.zoom * 10) - z) + data->map.pos_y;
	}
}

void	ft_draw_map(t_data *data, t_point *p)
{
	p->y = 0;
	while (p->y < data->map.height)
	{
		p->x = 0;
		while (p->x < data->map.width)
		{
			ft_iso_transform(data, &p->draw_x, &p->draw_y, &p->color);
			if (++p->x < data->map.width)
			{
				ft_iso_transform(data,
					&p->next_draw_x, &p->next_draw_y, &p->color_next);
				ft_draw_line(data, *p);
			}
			p->x--;
			if (++p->y < data->map.height)
			{
				ft_iso_transform(data,
					&p->next_draw_x, &p->next_draw_y, &p->color_next);
				ft_draw_line(data, *p);
			}
			p->y--;
			p->x++;
		}
		p->y++;
	}
}
