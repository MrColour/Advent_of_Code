/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_14_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:27:59 by home              #+#    #+#             */
/*   Updated: 2020/10/11 22:23:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

char	*knot_hash(char *str);

void		ctob(char *out, char *dst)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < 32)
	{
		j = 0;
		index = strchr(HEX, out[i]) - HEX;
		while (j < 4)
		{
			if ((index >> (3 - j)) & 1)
				dst[i * 4 + j] = '1';
			else
				dst[i * 4 + j] = '0';
			j++;
		}
		i++;
	}
}

void	flood_fill(char **grid, int x, int y, int size)
{
	grid[y][x] = '2';
	if (x - 1 >= 0 && grid[y][x - 1] == '1')
		flood_fill(grid, x - 1, y, size);

	if (x + 1 < size && grid[y][x + 1] == '1')
		flood_fill(grid, x + 1, y, size);

	if (y - 1 >= 0 && grid[y - 1][x] == '1')
		flood_fill(grid, x, y - 1, size);

	if (y + 1 < size && grid[y + 1][x] == '1')
		flood_fill(grid, x, y + 1, size);
}

int		main(void)
{
	int		i;
	char	*salt;
	char	*input;
	char	*output;

	char	**grid;

	salt = extract_file("input.txt");
	strchr(salt, '\n')[0] = '\0';

	ALLOC_2D(grid, 128, 129, calloc_wrapper, &g_ameta)

	i = 0;
	while (i < 128)
	{
		asprintf(&input, "%s-%d", salt, i);

		output = knot_hash(input);
		ctob(output, grid[i]);

		i++;
	}

	int	result;
	int	j;

	i = 0;
	result = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			if (grid[i][j] == '1')
			{
				flood_fill(grid, j, i, 128);
				result++;
			}
			j++;
		}
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}

