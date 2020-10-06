/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_19_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:30:48 by home              #+#    #+#             */
/*   Updated: 2020/10/06 02:41:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

char	new_dir(char **map, int x, int y, char from)
{
	char	result;

	result = -1;
	if (y - 1 > 0 && map[y - 1][x] == '|' && from != 'D')
		result = 'U';

	if (map[y + 1] != NULL && map[y + 1][x] == '|' && from != 'U')
		result = 'D';

	if (x - 1 > 0 && map[y][x - 1] == '-' && from != 'R')
		result = 'L';

	if (map[y][x + 1] != '\0' && map[y][x + 1] == '-' && from != 'L')
		result = 'R';

	return (result);
}

int		main(void)
{
	char	*str_file;
	char	**map;
	int		len;
	char	dir;
	int		row;
	int		col;
	int		steps;

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(map, str_file, len)
	map[len - 1] = NULL;

	row = 0;
	col = strchr(map[0], '|') - map[0];
	dir = 'D';
	steps = 0;
	while (1)
	{
		if (map[row][col] == '+')
			dir = new_dir(map, col, row, dir);

		if (dir == -1 || map[row][col] == ' ')
		{

			break ;
		}
		direction("DULR", dir, &col, &row); //inverse because of array
		steps++;
	}
	printf("RESULT: %d\n", steps);
	return (0);
}
