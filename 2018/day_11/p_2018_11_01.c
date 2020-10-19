/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_11_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 04:25:35 by home              #+#    #+#             */
/*   Updated: 2020/10/19 05:14:30 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		power_level(int row, int col, int serial_no)
{
	int		rack_id;
	int		result;

	rack_id = col + 10;
	result = rack_id * row;
	result += serial_no;
	result *= rack_id;
	result = ((result % 1000) / 100);
	result -= 5;
	return (result);
}

int		fuel_grid(int **grid, int row, int col)
{
	int		result;

	result = 0;
	result += grid[row - 1][col - 1] + grid[row - 1][col + 0] + grid[row - 1][col + 1];
	result += grid[row + 0][col - 1] + grid[row + 0][col + 0] + grid[row + 0][col + 1];
	result += grid[row + 1][col - 1] + grid[row + 1][col + 0] + grid[row + 1][col + 1];
	return (result);
}

int		main(void)
{
	int		row;
	int		col;
	int		**grid;
	int		serial_no;

	serial_no = atoi( extract_file("input.txt"));
	ALLOC_2D(grid, 300, 300, calloc_wrapper, NULL)

	row = 0;
	while (row < 300)
	{
		col = 0;
		while (col < 300)
		{
			grid[row][col] = power_level(row, col, serial_no);
			col++;
		}
		row++;
	}

	int		max;
	int		m_x;
	int		m_y;

	row = 0;
	max = INT_MIN;
	while (row < 300)
	{
		col = 0;
		while (col < 300)
		{
			if (bound_box(1, col, 298, 1, row, 298) == true)
			{
				if (max < fuel_grid(grid, row, col))
				{
					max = fuel_grid(grid, row, col);
					m_x = col - 1;
					m_y = row - 1;
				}
			}
			col++;
		}
		row++;
	}
	printf("%d,%d\n", m_x, m_y);
	return (0);
}
