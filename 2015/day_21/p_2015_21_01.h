/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_21_01.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:09:12 by home              #+#    #+#             */
/*   Updated: 2020/09/10 03:15:12 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_2015_21_01_H
# define P_2015_21_01_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE (1024)

typedef	struct	s_item
{
	int			cost;
	int			stat;
	bool		valid;
}				t_item;

typedef	struct	s_boss
{
	int			hp;
	int			att;
	int			def;
}				t_boss;

// Code should usually not be in header files, but making
// an entire file and compiling it would have been too much of a hassle,
// given the task and typical structure of puzzles.

char	*extract_file(char *file_name)
{
	int		fd;
	int		bytes_read;
	int		size;
	char	*result;

	size = 0;
	result = NULL;
	fd = open(file_name, O_RDONLY);

	bytes_read = 1;
	while (bytes_read != 0)
	{
		result = realloc(result, size + BUFF_SIZE + 1);
		bytes_read = read(fd, &result[size], BUFF_SIZE);
		size += bytes_read;
		result[size] = '\0';
	}
	return (result);
}

#endif