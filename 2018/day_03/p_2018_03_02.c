/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:44:19 by home              #+#    #+#             */
/*   Updated: 2020/10/17 19:24:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	fill_rect(int **grid, int x, int y, int width, int height, bool *overlap, int id)
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
			if (grid[y][x] != 0)
			{
				overlap[grid[y][x]] = true;
				overlap[id] = true;
			}
			grid[y][x] = id;
			x++;
		}
		y++;
	}
}

int		main(void)
{
	char	*str_file;
	int		id;
	int		sx;
	int		sy;
	int		height;
	int		width;
	bool	*overlap;
	int		**grid;

	str_file = extract_file("input.txt");
	overlap = calloc(count_occur("\n", str_file), sizeof(*overlap));
	ALLOC_2D(grid, 1000, 1000, calloc_wrapper, NULL)
	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &id);
		_tok += fetch_int(_tok, &sx);
		_tok += fetch_int(_tok, &sy);
		_tok += fetch_int(_tok, &width);
		_tok += fetch_int(_tok, &height);

		fill_rect(grid, sx, sy, width, height, overlap, id);
	)

	size_t	i;

	i = 1; //No zero id.
	while (1)
	{
		if (overlap[i] == false)
			break;
		i++;
	}
	answer(ld, i);
	return (0);
}
