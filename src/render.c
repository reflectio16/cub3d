/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/24 18:31:04 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_pixel(int x, int y, t_data *map, int color)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&map->img, x, y, color);		
		i++;
	}
}

void	map_render(t_data *map)
{
	int			x;
	int			y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y % 2 == 0)
				handle_pixel(x, y, map, 0xFF0000);
			else
			{
				handle_pixel(x, y, map, 0x0000FF);
			}
		}
	}
	mlx_put_image_to_window(map->mlx_connection,
		map->mlx_window, map->img.img, 0, 0);
}
