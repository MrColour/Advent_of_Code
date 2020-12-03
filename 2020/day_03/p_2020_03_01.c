/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_03_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:41:53 by home              #+#    #+#             */
/*   Updated: 2020/12/02 21:21:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

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

	int num;
	int x;
	int y;
	int trees;

	int width = strlen(lines[0]);

	i = 0;
	y = 0;
	x = 0;
	trees = 0;
	while (i < len)
	{

		// lines[i] += fetch_int(lines[i], &num);

		// printf("%d\n");

		if (lines[y][x] == '#')
			trees++;

		lines[y][x] = 'X';

		x += 3;
		y += 1;

		// printf("%s\n", lines[i]);
		x %= width;
		i++;
	}

	answer(d, trees);

	(void)j;
	return (0);
}
