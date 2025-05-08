/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:00:44 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:18 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO
	// ADD ROTATION FROM THE CENTER OF THE MAP
	// CENTERED MAP POSITION
	// CENTERED ZOOM
	// APP PERPECTIVE PROJECTION
	// COLOR POLYGON

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != REQUIRED_ARGS)
		ft_error(ERR_ARG, NULL, NULL, NULL);
	ft_init(&data, av[1]);
	ft_hook(&data);
	mlx_loop(data.mlx);
}
