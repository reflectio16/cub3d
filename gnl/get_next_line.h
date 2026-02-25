/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:30 by meelma            #+#    #+#             */
/*   Updated: 2026/02/25 16:54:22 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h> // malloc() free()
# include <unistd.h> // read()
# include <stdio.h> // printf() testing

// Core functions
char	*get_next_line(int fd);
char	*read_to_storage(int fd, char *storage);

// Utility functions
int		gnl_strlen(const char *str);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);

// Line handling
char	*extract_line(char *str);
char	*get_leftover(char	*storage);

#endif
