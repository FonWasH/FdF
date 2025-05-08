/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:00:37 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:21:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *error, t_data *data, char *str, char **tab)
{
	if (str)
		free(str);
	if (tab)
		ft_mfree((void **)tab, ft_mstrlen(tab));
	if (data)
		ft_destroy(data);
	ft_putstr(ERROR, STDERR_FILENO);
	ft_putstr(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
