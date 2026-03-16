/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:06:07 by meelma            #+#    #+#             */
/*   Updated: 2026/03/16 15:47:16 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_top_bottom(char **map, int height)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (is_walkable(map[0][i]))
			return (-1);
		i++;
	}
	i = 0;
	while (map[height - 1][i] && map[height - 1][i] != '\n')
	{
		if (is_walkable(map[height - 1][i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	check_sides(char **map, int height)
{
	int	i;
	int	len;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			len--;
		if (is_walkable(map[i][0]))
			return (-1);
		if (len > 0 && is_walkable(map[i][len -1]))
			return (-1);
		i++;
	}
	return (0);
}

static int	flood_all_walkable(char **map, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (flood_fill(map, j, i, height) == -1)
					return (-1);
			}
		}
	}
	return (0);
}

int	check_map_closed(t_data *data)
{
	char	**map_copy;
	int		result;

	if (check_top_bottom(data->map, data->map_height) == -1)
		return (-1);
	if (check_sides(data->map, data->map_height) == -1)
		return (-1);
	map_copy = copy_map(data->map, data->map_height);
	if (!map_copy)
		return (-1);
	result = flood_all_walkable(map_copy, data->map_height);
	free_split(map_copy);
	return (result);
}
