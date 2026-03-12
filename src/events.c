/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:22:41 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/12 18:51:52 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void rotation_handler(int keysym, t_game *game)
{
	if (keysym == XK_Left)
	{
		rotate_player(&game->data, -0.05);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
	if (keysym == XK_Right)
	{
		rotate_player(&game->data, 0.05);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
}

static void	move_handler(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		move_forward(&game->data);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
	if (keysym == XK_s)
	{
		move_backward(&game->data);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
	if (keysym == XK_d)
	{
		move_right(&game->data);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
	if (keysym == XK_a)
	{
		move_left(&game->data);
		cub_render(&game->mlx, &game->data, game->data.tile);
	}
}

int	close_handler(t_mlx *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->img.img);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_handler(&game->mlx);

	rotation_handler(keysym, game);
	move_handler(keysym, game);
	return (0);
}
