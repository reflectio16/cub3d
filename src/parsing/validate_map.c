/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:33:30 by meelma            #+#    #+#             */
/*   Updated: 2026/03/30 13:25:34 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	space_touches_walkable(char **map, int row, int col, int height)
{
	if (row > 0 && col < (int)ft_strlen(map[row - 1])
		&& ft_strchr("0NSEW", map[row - 1][col]))
		return (1);
	if (row + 1 < height && col < (int)ft_strlen(map[row + 1])
		&& ft_strchr("0NSEW", map[row + 1][col]))
		return (1);
	if (col > 0 && ft_strchr("0NSEW", map[row][col - 1]))
		return (1);
	if (map[row][col + 1] && ft_strchr("0NSEW", map[row][col + 1]))
		return (1);
	return (0);
}

static int	validate_map_chars(char **map, int height)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] != '0' && map[row][col] != '1'
				&& map[row][col] != ' ' && map[row][col] != 'N'
					&& map[row][col] != 'S' && map[row][col] != 'E'
						&& map[row][col] != 'W')
				return (-1);
			if (map[row][col] == ' '
				&& space_touches_walkable(map, row, col, height))
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}

static int	count_players(char **map)
{
	int	row;
	int	col;
	int	count;

	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'N' || map[row][col] == 'S'
				|| map[row][col] == 'E' || map[row][col] == 'W')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

int	validate_map(t_data *data)
{
	int	player_count;

	if (validate_map_chars(data->map, data->map_height) == -1)
		return (print_error("Invalid character in map"));
	player_count = count_players(data->map);
	if (player_count == 0)
		return (print_error("No player found"));
	else if (player_count > 1)
		return (print_error("Multiple players in map"));
	if (check_map_closed(data) == -1)
		return (print_error("Map is not closed by walls"));
	return (0);
}
