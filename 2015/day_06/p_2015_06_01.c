/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_06_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/09/13 22:08:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define LIT (42)
#define OFF (~42)

#define SIZE (1000)

void	process_file(char grid[SIZE][SIZE], char *file_name)
{
	char	*str_file;
	int		x1, y1, x2, y2;

	int		row, col;
	char	op;

	str_file = extract_file(file_name);
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		//notice that this character is different in the three different cases.
		// "toggle " <- ' '
		// "turn of" <- 'f'
		// "turn on" <- 'n'
		op = str_file[6];

		str_file += fetch_int(str_file, &x1);
		str_file += fetch_int(str_file, &y1);
		str_file += fetch_int(str_file, &x2);
		str_file += fetch_int(str_file, &y2);

		row = 0;
		while (row <= y2 - y1)
		{
			col = 0;
			while (col <= x2 - x1)
			{
				if (op == ' ')
				{
					if (grid[y1 + row][x1 + col] == LIT)
						grid[y1 + row][x1 + col] = OFF;
					else
						grid[y1 + row][x1 + col] = LIT;
				}
				else if (op == 'f')
					grid[y1 + row][x1 + col] = OFF;
				else if (op == 'n')
					grid[y1 + row][x1 + col] = LIT;
				col++;
			}
			row++;
		}
		str_file = strtok(NULL, "\n");
	}
}

int		main(void)
{
	int		lit_count;
	int		row, col;
	char	grid[SIZE][SIZE];

	lit_count = 0;
	bzero(grid, sizeof(grid));

	process_file(grid, "input.txt");

	row = 0;
	while (row < 1000)
	{
		col = 0;
		while (col < 1000)
		{
			if (grid[row][col] == LIT)
				lit_count++;
			col++;
		}
		row++;
	}
	printf("Result: %d\n", lit_count);
	return (0);
}