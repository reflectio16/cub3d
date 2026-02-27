/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:51:25 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/27 16:52:07 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_alloc(t_map *map, int fd)
{
	char	*line;
	int len;

	len = 0;
	while ((line = get_next_line(fd)))
	{
		len++; 
	}
	map->map = malloc(sizeof(char*) * (len + 1));
	free(line);
}

void	get_map(t_map *map, int fd)
{
	char	*line;
	int	i;
	
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map->map[i] = line;
		i++; 
	}
	map->map[i] = NULL;
}