/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:25:30 by home              #+#    #+#             */
/*   Updated: 2020/10/09 16:36:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define OFFSET (25)

int		calc(int **grid, int row, int col)
{
	int	result;

	result = 0;
	result += grid[row - 1][col - 1] + grid[row - 1][col + 0] + grid[row - 1][col + 1];
	result += grid[row + 0][col - 1] + grid[row + 0][col + 0] + grid[row + 0][col + 1];
	result += grid[row + 1][col - 1] + grid[row + 1][col + 0] + grid[row + 1][col + 1];

	grid[row][col] = result;
	printf("INT: %d (%d, %d)\n", result, row - OFFSET, col - OFFSET); //Result is the last one printed.
	return (result);
}

int		main(void)
{
	int		i;
	int		row;
	int		col;
	int		size;
	int		**grid;
	int		finding;

	finding = atoi(extract_file("input.txt"));
	ALLOC_2D(grid, OFFSET * 2, OFFSET * 2, calloc_wrapper, NULL)

	size = 2;
	grid[OFFSET][OFFSET] = 1;
	row = OFFSET;
	col = OFFSET + 1;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (calc(grid, row, col) > finding)
				return (0);
			i++;
			row--;
		}
		row++;
		i = 0;
		while (i < size)
		{
			col--;
			if (calc(grid, row, col) > finding)
				return (0);
			i++;
		}
		i = 0;
		while (i < size)
		{
			row++;
			if (calc(grid, row, col) > finding)
				return (0);
			i++;
		}
		i = 0;
		while (i < size)
		{
			col++;
			if (calc(grid, row, col) > finding)
				return (0);
			i++;
		}
		col++;

		size += 2;
	}

	return (0);
}
