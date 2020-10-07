/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_22_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:06:44 by home              #+#    #+#             */
/*   Updated: 2020/10/06 23:05:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

# define OFFSET (20000)

int		virus_step(char **map, int *x, int *y, char *dir)
{
	char	keypad[] = { 3, 1, 0, 2}; //Up and down are reversed because it is an array
	//  1
	//0   2
	//  3

	int result;

	result = 0;
	if (map[*y][*x] == '#')
	{
		map[*y][*x] = '.';
		(*dir)++;
	}
	else
	{
		map[*y][*x] = '#';
		result = 1;
		(*dir)--;
	}

	*dir = ((*dir + 4) % 4);
	direction(keypad, *dir, x, y);
	return (result);
}

int		main(void)
{
	char	*str_file;
	char	**map;

	int		v_x;
	int		v_y;
	char	dir;

	str_file = extract_file("input.txt");

	ALLOC_2D(map, (50000 * 2), (50000 * 2), calloc_wrapper, NULL)

	int		i;

	i = 0;
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		// printf("S: %s\n", str_file);
		memcpy(&(map[i + OFFSET][OFFSET]), str_file, strlen(str_file));
		str_file = strtok(NULL, "\n");
		i++;
	}

	int	burst;
	int	infected_burst;

	burst = 0;
	infected_burst = 0;

	v_x = OFFSET + 12;
	v_y = OFFSET + 12;
	dir = 1;
	while (burst < 10000)
	{
		infected_burst += virus_step(map, &v_x, &v_y, &dir);
		burst++;
	}

	printf("RESULT: %d\n", infected_burst);
	return (0);
}
