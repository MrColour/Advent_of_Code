/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_19_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 01:30:48 by home              #+#    #+#             */
/*   Updated: 2020/10/06 02:47:24 by home             ###   ########.fr       */
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

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(map, str_file, len)
	map[len - 1] = NULL;

	row = 0;
	col = strchr(map[0], '|') - map[0];
	dir = 'D';
	printf("RESULT: ");
	while (1)
	{
		if (map[row][col] == '+')
			dir = new_dir(map, col, row, dir);
		if (isalpha(map[row][col]))
			printf("%c", map[row][col]);

		if (dir == -1 || map[row][col] == ' ')
		{

			break ;
		}
		direction("DULR", dir, &col, &row); //inverse because of array
	}
	printf("\n");
	return (0);
}
