/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:44:00 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/24 17:46:42 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void	events_init(t_data *map)
{
	mlx_hook(map->mlx_window, KeyPress, KeyPressMask,
		key_handler, map);
	mlx_hook(map->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, map);
}

void	map_init(t_data *map)
{
	map->mlx_connection = mlx_init();
	if (map->mlx_connection == NULL)
		malloc_error();
	map->mlx_window = mlx_new_window(map->mlx_connection, WIDTH, HEIGHT, "the_game");
	if (map->mlx_window == NULL)
	{
		mlx_destroy_display(map->mlx_connection);
		free(map->mlx_connection);
		malloc_error();
	}
	map->img.img = mlx_new_image(map->mlx_connection, WIDTH, HEIGHT);
	if (map->img.img == NULL)
	{
		mlx_destroy_window(map->mlx_connection, map->mlx_window);
		mlx_destroy_display(map->mlx_connection);
		free(map->mlx_connection);
		malloc_error();
	}
	map->img.addr = mlx_get_data_addr(map->img.img,
		&map->img.bpp,
		&map->img.line_len,
		&map->img.endian);
	events_init(map);

	/*
	data_init(map);

	TODO : initialize every variables of our data structure
	*/ 
}