/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:13:43 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/06 20:02:58 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_len + x * (data->bpp / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_read(t_img *data, int x, int y)
{
	char	*color;
	int		offset;
	
	if (x >= 0 && x <= data->width && y >= 0 && y < data->height)
	{
		offset = (y * data->line_len + x * (data->bpp / 8));
		color = data->addr + offset;
	}
	return (color);
}