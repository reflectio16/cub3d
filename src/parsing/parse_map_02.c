/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:36:34 by meelma            #+#    #+#             */
/*   Updated: 2026/03/16 15:36:56 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (loop_map(data, row, col) == 0)
			{
				plane_init(data, 0.66);
				data->map[row][col] = '0';
				return (0);
			}
			col++;
		}
		row++;
	}
	return (-1);
}
