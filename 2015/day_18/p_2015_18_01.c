/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_18_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:39:47 by home              #+#    #+#             */
/*   Updated: 2020/09/08 20:07:26 by home             ###   ########.fr       */
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

bool	stay_on(char **grid, int row, int col)
{
	bool	result;
	int		checksum;

	int		stop_row;
	int		stop_col;

	int		start_col;

	result = false;
	checksum = 0;

	stop_col = col + 2;
	stop_row = row + 2;

	row--;
	start_col = col - 1;
	while (row < stop_row)
	{
		col =  start_col;
		while (col < stop_col && row >= 0)
		{
			if (col >= 0 && grid[row][col] == '#')
				checksum++;
			col++;
			if (grid[row][col] == '\0')
				break ;
		}
		row++;
		if (grid[row] == NULL)
			break ;
	}

	checksum--;
	if (checksum == 2 || checksum == 3)
		result = true;
	return (result);
}

bool	stay_off(char **grid, int row, int col)
{
	bool	result;
	int		checksum;

	int		stop_row;
	int		stop_col;

	int		start_col;

	result = false;
	checksum = 0;

	stop_col = col + 2;
	stop_row = row + 2;

	row--;
	start_col = col - 1;
	while (row < stop_row)
	{
		col =  start_col;
		while (col < stop_col && row >= 0)
		{
			if (col >= 0 && grid[row][col] == '#')
				checksum++;
			col++;
			if (grid[row][col] == '\0')
				break ;
		}
		row++;
		if (grid[row] == NULL)
			break ;
	}

	if (checksum == 3)
		result = true;
	return (result);
}

void	animate_lights(char **grid, char **grid_buff)
{
	int	row;
	int	col;

	row = 0;
	while (grid[row] != NULL)
	{
		col= 0;
		while (grid[row][col] != '\0')
		{
			if (grid[row][col] == '#')
				grid_buff[row][col] = (stay_on(grid, row, col) ? '#' : '.');
			else if (grid[row][col] == '.')
				grid_buff[row][col] = (stay_off(grid, row, col) ? '#' : '.');
			col++;
		}
		row++;
	}

	row = 0;
	while (grid[row] != NULL)
	{
		strcpy(grid[row], grid_buff[row]);
		row++;
	}
}

int		main(void)
{
	int		i;
	int		j;
	int		size;
	int		step_limit;
	char	*str_file;
	char	*s_tok;
	char	**grid;
	char	**grid_buf;

	size = 0;
	str_file = extract_file("input.txt");
	s_tok = str_file - 1;
	while (s_tok != NULL)
	{
		s_tok++;
		s_tok = strchr(s_tok, '\n');
		size++;
	}

	i = 0;
	grid = calloc(size, sizeof(*grid));
	grid_buf = calloc(size, sizeof(*grid_buf));
	s_tok = str_file;
	while (s_tok != NULL && s_tok[0] != '\0')
	{
		grid_buf[i] = calloc(size + 1, sizeof(**grid_buf));
		grid[i] = strsep(&s_tok, "\n");
		i++;
	}

	i = 0;
	step_limit = 100;
	while (i < step_limit)
	{
		animate_lights(grid, grid_buf);
		i++;
	}

	int		result;

	i = 0;
	result = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == '#')
				result++;
			j++;
		}
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}