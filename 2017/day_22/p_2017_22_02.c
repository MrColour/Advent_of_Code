// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   p_2017_22_02.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/10/06 21:06:44 by home              #+#    #+#             */
// /*   Updated: 2020/10/06 22:42:38 by home             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../aoc++.h"

# define OFFSET (10001) //This makes an assumption about the path the virus will travel.

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
		map[*y][*x] = 'F';
		(*dir)++;
	}
	else if (map[*y][*x] == '.' || map[*y][*x] == '\0')
	{
		map[*y][*x] = 'W';
		(*dir)--;
	}
	else if (map[*y][*x] == 'W')
	{
		map[*y][*x] = '#';
		result = 1;
	}
	else
	{
		map[*y][*x] = '.';
		*dir += 2;
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

	ALLOC_2D(map, (OFFSET * 2), (OFFSET * 2), calloc_wrapper, NULL)

	int		i;

	i = 0;
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		memcpy(&(map[i + OFFSET][OFFSET]), str_file, strlen(str_file));
		str_file = strtok(NULL, "\n");
		i++;
	}

	int	burst;
	int	infected_burst;

	burst = 0;
	infected_burst = 0;

	dir = 1;
	v_x = OFFSET + 12;
	v_y = OFFSET + 12;
	while (burst < 10000000)
	{
		infected_burst += virus_step(map, &v_x, &v_y, &dir);
		burst++;
	}
	printf("RESULT: %d\n", infected_burst);
	return (0);
}
