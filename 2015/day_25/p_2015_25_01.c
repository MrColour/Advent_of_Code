/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_25_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:53:13 by home              #+#    #+#             */
/*   Updated: 2020/09/10 08:36:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE (1024)

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

int		main(void)
{
	char	*str_file;
	int		t_row, t_col;

	int			row, col;
	int			s_row;
	long long	result;

	str_file = extract_file("input.txt");
	t_row = atoi(&strstr(str_file, "row")[3]);
	t_col = atoi(&strstr(str_file, "column")[6]);

	col = 0;
	s_row = 2;
	row = s_row;
	result = 20151125;
	while (!(col == t_col && row == t_row))
	{

		col = 1;
		row = s_row;
		while (row > 0)
		{
			result *= 252533;
			result %= 33554393;

			if (col == t_col && row == t_row)
				break;

			row--;
			col++;
		}

		s_row++;
	}
	printf("RESULT: %lld\n", result);
	return (0);
}