/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:44:00 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/12 18:48:44 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void	events_init(t_game *game)
{
	mlx_hook(game->mlx.window, KeyPress, KeyPressMask,
		key_handler, game);
	mlx_hook(game->mlx.window, DestroyNotify, StructureNotifyMask,
		close_handler, &game->mlx);
}

void	position_init(t_data *map, int i, int j)
{
	map->player.x = j + 0.5;
	map->player.y = i + 0.5;
}

void	direction_init(t_data *map, int i, int j)
{
	if (map->map[i][j] == 'N')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
	}
	else if (map->map[i][j] == 'S')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
	}
	else if (map->map[i][j] == 'E')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
	}
	else if (map->map[i][j] == 'W')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
	}
}

void	plane_init(t_data *map, double k)
{
	map->player.plane_x = -map->player.dir_y * k;
	map->player.plane_y = map->player.dir_x * k;
}

void	player_init(t_data *map)
{
	int	i;
	int	j;
	double k;
	
	k = 0.66;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N'
				|| map->map[i][j] == 'S'
				|| map->map[i][j] == 'E'
				|| map->map[i][j] == 'W')
			{
				position_init(map, i, j);
				direction_init(map, i, j);
				plane_init(map, k);
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

// void	texture_init(t_data *map)
// {
// 	map->tex.width = ;
// 	map->tex.height = ;

// }

void	cub_init(t_game *game, t_mlx *mlx, t_data *map)
{
	mlx->connection = mlx_init();
	if (mlx->connection == NULL)
		malloc_error();
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "the_game");
	if (mlx->window == NULL)
	{
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		malloc_error();
	}
	mlx->img.img = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	if (mlx->img.img == NULL)
	{
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		malloc_error();
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
		&mlx->img.bpp,
		&mlx->img.line_len,
		&mlx->img.endian);
	events_init(game);
	load_all_textures(mlx, map);
}
