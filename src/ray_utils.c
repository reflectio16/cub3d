/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:11:38 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/27 18:01:12 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_render(int tile, t_ray *ray, t_player_pixel *player_pixel, t_wall_floor *wf, t_map *map, t_mlx *mlx)
{
	int		l;
	int 	t;
	int		i;
	int		mapX;
	int		mapY;

	l = tile * 10;
	ray->camera_x[0] = -0.5;
	ray->camera_x[1] = 0;
	ray->camera_x[2] = 0.5;
	i = 0;
	while (i < 3)
	{
		t = 0;
		ray->x = map->player.dir_x + map->player.plane_x * ray->camera_x[i];
		ray->y = map->player.dir_y + map->player.plane_y * ray->camera_x[i];
		while (t < l)
		{
			wf->x = player_pixel->px + ray->x * t;
			wf->y = player_pixel->py + ray->y * t;
			mapX = (int)(wf->x / tile);
			mapY = (int)(wf->y / tile);
			// TODO -> check de bounds sur mapX et mapY par rapport a mapHeight et mapWidth !!!!
			if (map->map[mapY][mapX] == '1')
			{
				handle_pixel((int)wf->x, (int)wf->y, mlx, 0xFF0000);
				break ;
			}
			if (wf->x >= 0 && wf->x < WIDTH && wf->y >= 0 && wf->y < HEIGHT)
				handle_pixel((int)wf->x, (int)wf->y, mlx, 0xFFEE00);
			t++;
		}
		i++;
	}
}
