/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:27:03 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/10 16:53:14 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("You can't enter less than 2 arguments (including the program file)");
		exit(EXIT_FAILURE);
	}
	else
	{
		// t_mlx	mlx;
		// t_map	map;
		t_game	game;
		int		fd;

		game.tile = 7;
		cub_init(&game, &game.mlx, &game.map);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error with the file descriptor");
			return (1);
		}
		map_alloc(&game.map, fd);
		close(fd);
		
		fd = open(argv[1], O_RDONLY);
		get_map(&game.map,fd);
		close(fd);
		
		player_init(&game.map);
		cub_render(&game.mlx, &game.map, game.tile);
		mlx_loop(game.mlx.mlx_connection);
	}
}