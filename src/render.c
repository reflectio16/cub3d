/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:28 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/12 18:56:53 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_pixel(int x, int y, t_mlx *mlx, int color)
{
		my_mlx_pixel_put(&mlx->img, x, y, color);		
}

void	cub_render(t_mlx *mlx, t_data *map, int tile)
{
	// dda render
	dda_render(tile, map, mlx);
	
	// minimap wall_floor render
	wall_floor_render(tile, mlx, map);

	// minimap player position pixel filling
	player_pixel_render(tile, map, mlx);
	
	// minimap ray render
	ray_render(tile, map, mlx);
	
	// image on screen
	mlx_put_image_to_window(mlx->connection,
		mlx->window, mlx->img.img, 0, 0);
	
	// data written on screen	
	display_data(mlx, map);
}
