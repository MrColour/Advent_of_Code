/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_18_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:39:47 by home              #+#    #+#             */
/*   Updated: 2020/09/28 21:33:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

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

void	animate_lights(char **grid, char **grid_buff, int size)
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

	grid[0][0] = '#';
	grid[0][size] = '#';
	grid[size][0] = '#';
	grid[size][size] = '#';
}

int		main(void)
{
	int		size;
	int		step_limit;
	char	*str_file;
	char	**grid;
	char	**grid_buf;

	str_file = extract_file("input.txt");

	size = count_occur("\n", str_file) + 1;
	ALLOC_2D(grid_buf, size, size, calloc_wrapper, NULL)
	NEWLINE_SPLIT(grid, str_file, size)

	grid[0][0] = '#';
	grid[0][99] = '#';
	grid[99][0] = '#';
	grid[99][99] = '#';

	int		i;
	int		j;

	i = 0;
	step_limit = 100;
	while (i < step_limit)
	{
		animate_lights(grid, grid_buf, 100 - 1);
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