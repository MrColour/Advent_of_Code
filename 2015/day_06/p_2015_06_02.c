/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_06_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/09/28 17:21:43 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (1000)

void	process_file(char grid[SIZE][SIZE], char *file_name)
{
	char	*str_file;
	int		x1, y1, x2, y2;
	char	*s_x1, *s_y1, *s_x2, *s_y2;

	int		row, col;
	char	op;

	str_file = extract_file(file_name);
	str_file = strtok(str_file, "\n,");
	while (str_file != NULL)
	{
		//notice that this character is different in the three different cases.
		// "toggle " <- ' '
		// "turn of" <- 'f'
		// "turn on" <- 'n'
		op = str_file[6];

		s_x1 = strpbrk(str_file, "0123456789");
		str_file = strtok(NULL, "\n,");
		s_y1 = strpbrk(str_file, "0123456789");

		s_x2 = strpbrk(&str_file[4], "0123456789");
		str_file = strtok(NULL, "\n,");
		s_y2 = strpbrk(str_file, "0123456789");

		x1 = atoi(s_x1);
		y1 = atoi(s_y1);
		x2 = atoi(s_x2);
		y2 = atoi(s_y2);

		row = 0;
		while (row <= y2 - y1)
		{
			col = 0;
			while (col <= x2 - x1)
			{
				if (op == ' ')
					grid[y1 + row][x1 + col] += 2;
				else if (op == 'f')
					grid[y1 + row][x1 + col] += -1;
				else if (op == 'n')
					grid[y1 + row][x1 + col] += 1;

				if (grid[y1 + row][x1 + col] <= 0)
					grid[y1 + row][x1 + col] = 0;
				col++;
			}
			row++;
		}
		str_file = strtok(NULL, "\n,");
	}
}

int		main(void)
{
	long long int	lit_count;
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
			lit_count += grid[row][col];
			col++;
		}
		row++;
	}
	printf("Result: %lld\n", lit_count);
	return (0);
}