/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_03_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:44:19 by home              #+#    #+#             */
/*   Updated: 2020/10/17 19:15:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	fill_rect(int **grid, int x, int y, int width, int height)
{
	int	x_start;

	x_start = x;
	height += y;
	width += x;
	while (y < height)
	{
		x = x_start;
		while (x < width)
		{
			grid[y][x]++;
			x++;
		}
		y++;
	}
}

int		main(void)
{
	char	*str_file;
	int		sx;
	int		sy;
	int		height;
	int		width;
	int		**grid;

	str_file = extract_file("input.txt");
	ALLOC_2D(grid, 1000, 1000, calloc_wrapper, NULL)
	FOR_EACH_STRTOK(str_file, "\n",
		_tok += strspn(_tok, DIGITS"#");
		_tok += fetch_int(_tok, &sx);
		_tok += fetch_int(_tok, &sy);
		_tok += fetch_int(_tok, &width);
		_tok += fetch_int(_tok, &height);

		fill_rect(grid, sx, sy, width, height);
	)

	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			if (grid[i][j] > 1)
				result++;
			j++;
		}
		i++;
	}
	answer(d, result);
	return (0);
}
