/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:22:41 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/10 21:38:43 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_handler(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_connection, mlx->img.img);
	mlx_destroy_window(mlx->mlx_connection, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_connection);
	free(mlx->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_handler(&game->mlx);

	// manage left and right arrow keys
	if (keysym == XK_Left)
	{
		rotate_player(&game->map, -0.05);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	if (keysym == XK_Right)
	{
		rotate_player(&game->map, 0.05);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	if (keysym == XK_w)
	{
		move_forward(&game->map);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	if (keysym == XK_s)
	{
		move_backward(&game->map);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	if (keysym == XK_d)
	{
		move_right(&game->map);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	if (keysym == XK_a)
	{
		move_left(&game->map);
		cub_render(&game->mlx, &game->map, game->tile);
	}
	// manage W, A, S, and D keys 
	
	// cub_render(map);

	return (0);
}