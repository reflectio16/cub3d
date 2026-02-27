/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pixel_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:39:31 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/27 16:40:27 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pixel_render(int tile, t_player_pixel *player_pixel, t_map *map, t_mlx *mlx)
{
	player_pixel->px = map->player.x * tile;
	player_pixel->py = map->player.y * tile;
	player_pixel->dx = -3;
	while (player_pixel->dx < 3)
	{
		player_pixel->dy = -3;
		while (player_pixel->dy < 3)
		{
			handle_pixel((int)(player_pixel->px + player_pixel->dx),
				(int) (player_pixel->py + player_pixel->dy), mlx, 0xFFEE00);
			player_pixel->dy++;
		}
		player_pixel->dx++;
	}
}
