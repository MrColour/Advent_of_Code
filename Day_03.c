/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:40:00 by marvin            #+#    #+#             */
/*   Updated: 2019/12/02 22:40:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 10000

void	flood_find(char **grid, int x, int y)
{

}

int	main(void)
{
	int		fd;
	int		ret;
	char	*str_file;

	printf("Testing\n");
	str_file = malloc(sizeof(*str_file) * (SIZE + 1));
	fd = open("day_03.txt", O_RDONLY);
	ret = read(fd, str_file, SIZE);
	str_file[ret] = '\0';

	char	*wire_01;
	char	*wire_02;

	wire_01 = str_file;
	wire_02 = strchr(str_file, '\n');
	wire_02[0] = '\0';
	wire_02 = &wire_02[1];
	strchr(wire_02, '\n')[0] = '\0';
	printf("WIRE1: %s\n", wire_01);
	printf("WIRE2: %s\n", wire_02);

	int	min_h;
	int	max_h;
	int	min_v;
	int	max_v;
	int	curr_v;
	int	curr_h;
	int	curr;
	char	type;
	int	i;

	i = 0;
	min_h = 0;
	max_h = 0;
	min_v = 0;
	max_v = 0;
	curr_v = 0;
	curr_h = 0;
	while (wire_01[i] != '\0')
	{
		type = wire_01[i];
		i++;						//type
		curr = atoi(&wire_01[i]);
		while (isdigit(wire_01[i]))	//number
			i++;
		if (type == 'R')
			curr_h += curr;
		else if (type == 'L')
			curr_h += -curr;
		else if (type == 'U')
			curr_v += -curr;
		else if (type == 'D')
			curr_v += curr;

		if (min_h > curr_h)
			min_h = curr_h;
		if (max_h < curr_h)
			max_h = curr_h;

		if (min_v > curr_v)
			min_v = curr_v;
		if (max_v < curr_v)
			max_v = curr_v;
		i++;						//comma
	}


	i = 0;
	curr_h = 0;
	curr_v = 0;
	while (wire_02[i] != '\0')
	{
		type = wire_02[i];
		i++;						//type
		curr = atoi(&wire_02[i]);
		while (isdigit(wire_02[i]))	//number
			i++;
		if (type == 'R')
			curr_h += curr;
		else if (type == 'L')
			curr_h += -curr;
		else if (type == 'U')
			curr_v += -curr;
		else if (type == 'D')
			curr_v += curr;

		if (min_h > curr_h)
			min_h = curr_h;
		if (max_h < curr_h)
			max_h = curr_h;

		if (min_v > curr_v)
			min_v = curr_v;
		if (max_v < curr_v)
			max_v = curr_v;
		i++;						//comma
	}


	int grid_size;

	grid_size = 0;
	if (grid_size < max_h - min_h)
		grid_size = max_h - min_h;
	if (grid_size < max_v - min_v)
		grid_size = max_v - min_v;

	char **grid;
	grid_size = grid_size * 2 + 10;
	grid = malloc(sizeof(*grid ) * (grid_size + 1));
	i = 0;
	while (i < (grid_size))
	{
		grid[i] = malloc(sizeof(**grid) * (grid_size + 1));
		if (grid[i] == NULL)
		{
			printf("Out %d!\n", i);
			break ;
		}
		memset(grid[i], '.', (grid_size));
		grid[i][(grid_size)] = '\0';
		i++;
	}
	grid[i] = NULL;

	i = 0;
	int	j;
	int	x;
	int	y;
	x = grid_size / 2;
	y = grid_size / 2;
	grid[y][x] = 'o';
	while (wire_01[i] != '\0')
	{
		type = wire_01[i];
		i++;
		curr = atoi(&wire_01[i]);
		while (isdigit(wire_01[i]))	//number
			i++;
		i++;

		if (type == 'U')
		{
			j = 0;
			while (j < curr)
			{
				y--;
				grid[y][x] = '1';
				j++;
			}
		}
		if (type == 'D')
		{
			j = 0;
			while (j < curr)
			{
				y++;
				grid[y][x] = '1';
				j++;
			}
		}
		if (type == 'R')
		{
			j = 0;
			while (j < curr)
			{
				x++;
				grid[y][x] = '1';
				j++;
			}
		}
		if (type == 'L')
		{
			j = 0;
			while (j < curr)
			{
				x--;
				grid[y][x] = '1';
				j++;
			}
		}
	}


	i = 0;
	x = grid_size / 2;
	y = grid_size / 2;
	while (wire_02[i] != '\0')
	{
		type = wire_02[i];
		i++;
		curr = atoi(&wire_02[i]);
		while (isdigit(wire_02[i]))	//number
			i++;
		i++;

		if (type == 'U')
		{
			j = 0;
			while (j < curr)
			{
				y--;
				if (grid[y][x] == '1')
					grid[y][x] == 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
				j++;
			}
		}
		if (type == 'D')
		{
			j = 0;
			while (j < curr)
			{
				y++;
				if (grid[y][x] == '1')
					grid[y][x] == 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
				j++;
			}
		}
		if (type == 'R')
		{
			j = 0;
			while (j < curr)
			{
				x++;
				if (grid[y][x] == '1')
					grid[y][x] == 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
				j++;
			}
		}
		if (type == 'L')
		{
			j = 0;
			while (j < curr)
			{
				x--;
				if (grid[y][x] == '1')
					grid[y][x] == 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
				j++;
			}
		}
	}

	x = grid_size / 2;
	y = grid_size / 2;
	flood_find(grid, x, y);
	return (0);
}
