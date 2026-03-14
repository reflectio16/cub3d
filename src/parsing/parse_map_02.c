/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:24:36 by meelma            #+#    #+#             */
/*   Updated: 2026/03/14 17:24:53 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pad_map_rows(t_data *data)
{
	int		i;
	int		len;
	char	*padded;

	i = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len < data->map_width)
		{
			padded = malloc(data->map_width + 1);
			if (!padded)
				return (-1);
			ft_memcpy(padded, data->map[i], len);
			ft_memset(padded + len, ' ', data->map_width - len);
			padded[data->map_width] = '\0';
			free(data->map[i]);
			data->map[i] = padded;
		}
		i++;
	}
	return (0);
}