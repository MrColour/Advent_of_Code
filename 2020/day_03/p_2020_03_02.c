/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:41:53 by home              #+#    #+#             */
/*   Updated: 2020/12/02 21:22:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

int		tree_count(int size, int width, char **map, int dx, int dy)
{
	int i;
	int num;
	int x;
	int y;
	int trees;

	i = 0;
	y = 0;
	x = 0;
	trees = 0;
	while (i < size && y < size)
	{

		// lines[i] += fetch_int(lines[i], &num);

		// printf("%d\n");

		if (map[y][x] == '#')
			trees++;

		// map[y][x] = 'X';

		x += dx;
		y += dy;

		// printf("%s\n", map[i]);
		x %= width;
		i++;
	}
	return (trees);
}

int		main(void)
{
	int		i;
	int		j;
	char	*str_file;
	char	**lines;
	// char	**map;
	int		len;

	str_file = extract_file("input.txt");
	len = count_occur("\n", str_file);
	NEWLINE_SPLIT(lines, str_file, len);
	// ALLOC_2D(map, SIZE * 2, SIZE * 2, calloc_wrapper, NULL)

	int width = strlen(lines[0]);


	long trees1;
	long trees2;
	long trees3;
	long trees4;
	long trees5;

	trees1 = tree_count(len, width, lines, 1, 1);
	trees2 = tree_count(len, width, lines, 3, 1);
	trees3 = tree_count(len, width, lines, 5, 1);
	trees4 = tree_count(len, width, lines, 7, 1);
	trees5 = tree_count(len, width, lines, 1, 2);

	// printf("%ld %ld %ld %ld %ld\n", trees1 , trees2 , trees3 , trees4 , trees5);
	answer(ld, trees1 * trees2 * trees3 * trees4 * trees5);

	(void)j;
	return (0);
}
