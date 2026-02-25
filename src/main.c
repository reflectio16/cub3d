/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:58:41 by meelma            #+#    #+#             */
/*   Updated: 2026/02/25 16:56:03 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char** av)
{
    int     fd;
    int     filenamelen;
    char    *line;
    
    if (ac != 2)
    {
        printf("Wrong argument count!");
        return (1);
    }
    filenamelen = ft_strlen(av[1]);
    if (filenamelen < 4 || (ft_strncmp(&av[1][filenamelen - 4], ".cub", 4) != 0))
    {
        printf("Wrong file extention! Must be .cub");
        return (1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
       printf("Cannot open the file!");
       return (1);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
        
    }
    close(fd);
    return (0);
}