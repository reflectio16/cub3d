/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_contour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:29 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/16 17:36:37 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_start(t_data *map)
{
	map->contour.start_x = map->contour.base_x;
	map->contour.start_y = map->contour.base_y;
}

static void	set_end(int tile, t_data *map)
{
	map->contour.end_x = map->contour.base_x + tile - 1;
	map->contour.end_y = map->contour.base_y + tile - 1;
}

void	tile_contour_render(int tile, t_data *map, t_mlx *mlx, int color)
{
	set_start(map);
	set_end(tile, map);
	while (map->contour.start_x <= map->contour.end_x)
	{
		handle_pixel(map->contour.start_x, map->contour.start_y, mlx, color);
		map->contour.start_x++;
	}
	set_start(map);
	while (map->contour.start_x <= map->contour.end_x)
	{
		handle_pixel(map->contour.start_x, map->contour.end_y, mlx, color);
		map->contour.start_x++;
	}
	set_start(map);
	while (map->contour.start_y <= map->contour.end_y)
	{
		handle_pixel(map->contour.start_x, map->contour.start_y, mlx, color);
		map->contour.start_y++;
	}
	set_start(map);
	while (map->contour.start_y <= map->contour.end_y)
	{
		handle_pixel(map->contour.end_x, map->contour.start_y, mlx, color);
		map->contour.start_y++;
	}
}
