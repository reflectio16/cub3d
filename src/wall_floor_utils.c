/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_floor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:55:44 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/27 16:26:18 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(int tile, t_wall_floor *wf, t_mlx *mlx)
{
	wf->y = -1;
	while (++wf->y < tile)
	{
		wf->x = -1;
		while (++wf->x < tile)
		{
			wf->pixel_x = wf->j * tile + wf->x;
			wf->pixel_y = wf->i * tile + wf->y;
			handle_pixel(wf->pixel_x, wf->pixel_y, mlx, 0xDD00FF);
		}
	}
}

void	draw_floor(int tile, t_wall_floor *wf, t_mlx *mlx)
{
	wf->y = -1;
	while (++wf->y < tile)
	{
		wf->x = -1;
		while (++wf->x < tile)
		{
			wf->pixel_x = wf->j * tile + wf->x;
			wf->pixel_y = wf->i * tile + wf->y;
			handle_pixel(wf->pixel_x, wf->pixel_y, mlx, 0x000000);
		}
	}
}

void	wall_floor_render(int tile, t_wall_floor *wf, t_mlx *mlx, t_map *map)
{
		
	wf->i = 0;
	while (map->map[wf->i])
	{
		wf->j = 0;
		while (map->map[wf->i][wf->j])
		{
			if (map->map[wf->i][wf->j] == '1')
				draw_wall(tile, wf, mlx);
			else if (map->map[wf->i][wf->j] == '0')
				draw_floor(tile, wf, mlx);
			wf->j++;
		}
		wf->i++;
	}
}
