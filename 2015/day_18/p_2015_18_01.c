/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_18_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:39:47 by home              #+#    #+#             */
/*   Updated: 2020/09/13 21:32:25 by home             ###   ########.fr       */
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
	int		size;
	int		step_limit;
	char	*str_file;
	char	*s_tok;
	char	**grid;
	char	**grid_buf;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file) + 1;

	i = 0;
	s_tok = str_file;
	grid = calloc(size, sizeof(*grid));
	grid_buf = calloc(size, sizeof(*grid_buf));
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
		result += count_occur("#", grid[i]);
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}