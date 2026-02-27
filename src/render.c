/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/27 17:15:21 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_pixel(int x, int y, t_mlx *mlx, int color)
{
		my_mlx_pixel_put(&mlx->img, x, y, color);		
}

void	map_render(t_mlx *mlx, t_map *map)
{
	int				tile;
	t_wall_floor	wf;
	t_player_pixel	player_pixel;
	t_ray			ray;
	
	tile = 30;
	wall_floor_init(&wf);
	wall_floor_render(tile, &wf, mlx, map);

	// player position pixel filling
	player_pixel_init(&player_pixel);
	player_pixel_render(tile, &player_pixel, map, mlx);

	// directional arrow
	ray_init(&ray);
	ray_render(tile, &ray, &player_pixel, &wf, map, mlx);
	
	// image on screen
	mlx_put_image_to_window(mlx->mlx_connection,
		mlx->mlx_window, mlx->img.img, 0, 0);
}
