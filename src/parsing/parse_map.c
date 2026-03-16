/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:08:15 by meelma            #+#    #+#             */
/*   Updated: 2026/03/16 15:36:12 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_map_line(char *line, t_list **map_list)
{
	t_list	*node;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (-1);
	node = ft_lstnew(trimmed);
	if (!node)
	{
		free(trimmed);
		return (-1);
	}
	ft_lstadd_back(map_list, node);
	return (0);
}

char	**list_to_array(t_list *list, int *height)
{
	char	**arr;
	int		lst_size;
	int		i;

	lst_size = ft_lstsize(list);
	if (lst_size == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (lst_size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (list)
	{
		arr[i] = list->content;
		list = list->next;
		i++;
	}
	arr[i] = NULL;
	*height = lst_size;
	return (arr);
}

int	get_map_width(char **map)
{
	int	max_width;
	int	len;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

static void	set_player_dir(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	else if (c == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}

int	loop_map(t_data *data, int row, int col)
{
	if (data->map[row][col] == 'N' || data->map[row][col] == 'S'
		|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
	{
		data->player.x = col + 0.5;
		data->player.y = row + 0.5;
		set_player_dir(data, data->map[row][col]);
		return (0);
	}
	return (-1);
}
