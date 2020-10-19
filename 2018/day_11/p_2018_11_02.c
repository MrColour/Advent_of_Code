/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_11_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 04:25:35 by home              #+#    #+#             */
/*   Updated: 2020/10/19 05:14:32 by home             ###   ########.fr       */
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

int		fuel_grid(int **grid, int row, int col, int size)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	result = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result += grid[row + i][col + j];
			j++;
		}
		i++;
	}
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
	int		m_s;
	int		tmp;
	int		size;

	size = 1;
	max = INT_MIN;
	while (size < 300)
	{
		row = 0;
		while (row < 300 - size)
		{
			col = 0;
			while (col < 300 - size)
			{
				tmp = fuel_grid(grid, row, col, size);
				if (max < tmp)
				{
					max = tmp;
					m_x = col;
					m_y = row;
					m_s = size;
				}
				col++;
			}
			row++;
		}
		size++;
	}
	printf("%d,%d,%d\n", m_x, m_y, m_s);
	return (0);
}
