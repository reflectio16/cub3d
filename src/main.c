/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:58:41 by meelma            #+#    #+#             */
/*   Updated: 2026/03/10 14:22:32 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_args(int ac, char *filename)
{
	int	len;

	if (ac != 2)
		return (print_error("Wrong argument count"));
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
		return (print_error("Wrong file extension. Must be .cub"));
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*map_list;

	map_list = NULL;
	ft_memset(&data, 0, sizeof(t_data));
	data.colors.floor_color = -1;
	data.colors.ceiling_color = -1;
	if (check_args(ac, av[1]) == -1)
		return (1);
	if (parse_file(av[1], &data, &map_list) == -1)
	{
		free_data(&data);
		return (1);
	}
	if (setup_map(&data, map_list) == -1)
	{
		free_data(&data);
		return (1);
	}
        
    // Game starting code here
	
	free_data(&data);
	return (0);
}
