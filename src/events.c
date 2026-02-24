/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:22:41 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/24 17:33:00 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_handler(t_data *map)
{
	mlx_destroy_image(map->mlx_connection, map->img.img);
	mlx_destroy_window(map->mlx_connection, map->mlx_window);
	mlx_destroy_display(map->mlx_connection);
	free(map->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_data *map)
{
	if (keysym == XK_Escape)
		close_handler(map);

	// manage left and right arrow keys
	// manage W, A, S, and D keys 
	
	// map_render(map);

	return (0);
}