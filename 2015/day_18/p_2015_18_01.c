/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_18_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:39:47 by home              #+#    #+#             */
/*   Updated: 2020/10/14 02:02:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		on_neighbors(char **grid, int row, int col, int size)
{
	int		on;

	int		stop_row;
	int		stop_col;

	stop_col = col + 2;
	stop_row = row + 2;

	row--;
	on = 0;
	while (row < stop_row)
	{
		col =  stop_col - 3;
		while (col < stop_col)
		{
			if (bound_box(0, row, size, 0, col, size) && grid[row][col] == '#')
				on++;
			col++;
		}
		row++;
	}
	return (on);
}

bool	stay_on(char **grid, int row, int col, int size)
{
	int		checksum;

	checksum = on_neighbors(grid, row, col, size);
	checksum--;
	if (checksum == 2 || checksum == 3)
		return (true);
	else
		return (false);
}

bool	stay_off(char **grid, int row, int col, int size)
{
	int		checksum;

	checksum = on_neighbors(grid, row, col, size);
	if (checksum == 3)
		return (true);
	else
		return (false);
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
				grid_buff[row][col] = (stay_on(grid, row, col, size) ? '#' : '.');
			else if (grid[row][col] == '.')
				grid_buff[row][col] = (stay_off(grid, row, col, size) ? '#' : '.');
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
	int		size;
	int		step_limit;
	char	*str_file;
	char	**grid;
	char	**grid_buf;

	str_file = extract_file("input.txt");
	strrchr(str_file, '\n')[0] = '\0';

	size = count_occur("\n", str_file) + 2;
	ALLOC_2D(grid_buf, size, size, calloc_wrapper, NULL)
	NEWLINE_SPLIT(grid, str_file, size)

	step_limit = 100;
	FOR_EACH(_i < step_limit,
		animate_lights(grid, grid_buf, size - 1);
	)

	int		result;

	result = 0;
	FOR_EACH(grid[_i] != NULL,
		result += count_occur("#", grid[_i]);
	)
	answer(d, result);
	return (0);
}