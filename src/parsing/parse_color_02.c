/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:09:52 by meelma            #+#    #+#             */
/*   Updated: 2026/03/14 17:10:22 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(char *line, t_data *data)
{
	int	i;
	int	color;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	color = extract_rgb(&line[i]);
	if (color == -1)
		return (print_error("Invalid color format"));
	if (line[0] == 'F')
	{
		if (data->colors.floor != -1)
			return (print_error("Duplicate color path"));
		data->colors.floor = color;
	}
	else if (line[0] == 'C')
	{
		if (data->colors.ceiling != -1)
			return (print_error("Duplicate color path"));
		data->colors.ceiling = color;
	}
	return (0);
}