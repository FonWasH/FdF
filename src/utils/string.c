/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:23:48 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:20:49 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_size_str(t_data *data, int width, int height)
{
	char	*size;
	char	*s1;
	char	*s2;

	s1 = ft_ltoa(width);
	if (!s1)
		ft_error(ERR_MEM, data, NULL, NULL);
	s2 = ft_strjoin(s1, I_SIZE_SEP);
	free(s1);
	if (!s2)
		ft_error(ERR_MEM, data, NULL, NULL);
	s1 = ft_ltoa(height);
	if (!s1)
		ft_error(ERR_MEM, data, s2, NULL);
	size = ft_strjoin(s2, s1);
	free(s1);
	free(s2);
	if (!size)
		ft_error(ERR_MEM, data, NULL, NULL);
	return (size);
}

char	*ft_double_str(t_data *data, double n)
{
	double	int_part;
	double	dec_part;
	char	*s1;
	char	*s2;
	char	*s3;

	dec_part = modf(n, &int_part);
	s1 = ft_ltoa((ssize_t)int_part);
	if (!s1)
		ft_error(ERR_MEM, data, NULL, NULL);
	s2 = ft_strjoin(s1, I_DOUBLE_DOT);
	free(s1);
	if (!s2)
		ft_error(ERR_MEM, data, NULL, NULL);
	s1 = ft_ltoa(ft_abs((ssize_t)(dec_part * 1000)));
	if (!s1)
		ft_error(ERR_MEM, data, s2, NULL);
	s3 = ft_strjoin(s2, s1);
	free(s1);
	free(s2);
	if (!s3)
		ft_error(ERR_MEM, data, NULL, NULL);
	return (s3);
}

char	*ft_pro_str(t_pro projection)
{
	if (projection == ISOMETRIC)
		return (I_PRO_ISO);
	if (projection == PARALLEL)
		return (I_PRO_PAR);
	return (NULL);
}
