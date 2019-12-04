/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_03b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:40:00 by marvin            #+#    #+#             */
/*   Updated: 2019/12/04 05:23:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#define SIZE 10000

typedef	struct	s_inter
{
	int				x_loc;
	int				y_loc;

	int				wire_01;
	int				wire_02;

	struct s_inter	*next;
}				t_inter;

void	find_inter(t_inter *head, int key_x, int key_y, int moves)
{
	head = head->next; //The first node is a dummy head;

	while (head)
	{
		if (head->x_loc == key_x && head->y_loc == key_y)
		{
			head->wire_01 = moves;
			break ;
		}
		head = head->next;
	}
}

int		get_line_size(char *wire)
{
	int		min_h;
	int		max_h;
	int		min_v;
	int		max_v;
	int		curr_v;
	int		curr_h;
	char	type;
	int		i;

	i = 0;
	min_h = 0;
	max_h = 0;
	min_v = 0;
	max_v = 0;
	curr_v = 0;
	curr_h = 0;
	while (wire[i] != '\0')
	{
		if (wire[i] == 'R')
			curr_h += atoi(&wire[++i]);
		else if (wire[i] == 'L')
			curr_h += -atoi(&wire[++i]);
		else if (wire[i] == 'U')
			curr_v += -atoi(&wire[++i]);
		else if (wire[i] == 'D')
			curr_v += atoi(&wire[++i]);

		if (min_h > curr_h)
			min_h = curr_h;
		if (max_h < curr_h)
			max_h = curr_h;

		if (min_v > curr_v)
			min_v = curr_v;
		if (max_v < curr_v)
			max_v = curr_v;
		while (isdigit(wire[i]))	//number
			i++;
		i++;						//comma
	}
	if (max_h - min_h > max_v - min_v)
		return (max_h - min_h);
	else
		return (max_v - min_v);
}

int	main(void)
{
	int		fd;
	int		ret;
	char	*str_file;

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

	int		i;
	int grid_size;

	i = get_line_size(wire_01);
	grid_size = get_line_size(wire_02);
	if (grid_size < i)
		grid_size = i;

	// the grid is at least twice as big. Meaning we dont have to offset the start, just start at middle
	char **grid;
	grid_size = grid_size * 2 + 10;
	grid = malloc(sizeof(*grid ) * (grid_size + 1));

	i = 0;
	while (i < (grid_size))
	{
		grid[i] = malloc(sizeof(**grid) * (grid_size + 1));
		memset(grid[i], '.', (grid_size));
		grid[i][(grid_size)] = '\0';
		i++;
	}
	grid[i] = NULL;
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;

	i = 0;
	int		j;
	int		curr;
	char	type;
	x = grid_size / 2;
	y = grid_size / 2;
	grid[y][x] = 'o';
	while (wire_01[i] != '\0')
	{
		type = wire_01[i++];
		curr = atoi(&wire_01[i]);
		while (isdigit(wire_01[i]))
			i++;
		if (wire_01[i] == ',')
			i++;

		delta_x = 0;
		delta_y = 0;
		if (type == 'U')
			delta_y = -1;
		if (type == 'D')
			delta_y = 1;
		if (type == 'R')
			delta_x = 1;
		if (type == 'L')
			delta_x = -1;
		j = -1;
		while (++j < curr)
		{
			x = x + delta_x;
			y = y + delta_y;
			grid[y][x] = '1';
		}
	}

	i = 0;
	x = grid_size / 2;
	y = grid_size / 2;

	t_inter	*head;
	t_inter	*last;
	int		moves;

	moves = 0;
	head = malloc(sizeof(*head));
	last = head;

	while (wire_02[i] != '\0')
	{
		type = wire_02[i++];
		curr = atoi(&wire_02[i]);
		while (isdigit(wire_02[i]))
			i++;
		if (wire_02[i] == ',')
			i++;

		delta_x = 0;
		delta_y = 0;
		if (type == 'U')
			delta_y = -1;
		if (type == 'D')
			delta_y = 1;
		if (type == 'R')
			delta_x = 1;
		if (type == 'L')
			delta_x = -1;
		j = -1;
		while (++j < curr && ++moves)
		{
			x = x + delta_x;
			y = y + delta_y;
			if (grid[y][x] == '1')
			{
				grid[y][x] = 'X';
				last->next = malloc(sizeof(*head));
				last = last->next;
				last->y_loc = y;
				last->x_loc = x;
				last->wire_02 = moves;
				last->wire_01 = 0;
				last->next = NULL;
			}
			else if (grid[y][x] != 'X')
				grid[y][x] = '2';
		}
	}

	i = 0;
	moves = 0;
	x = grid_size / 2;
	y = grid_size / 2;
	grid[y][x] = 'o';
	while (wire_01[i] != '\0')
	{
		type = wire_01[i++];
		curr = atoi(&wire_01[i]);
		while (isdigit(wire_01[i]))
			i++;
		if (wire_01[i] == ',')
			i++;

		delta_x = 0;
		delta_y = 0;
		if (type == 'U')
			delta_y = -1;
		if (type == 'D')
			delta_y = 1;
		if (type == 'R')
			delta_x = 1;
		if (type == 'L')
			delta_x = -1;
		j = -1;
		while (++j < curr)
		{
			x = x + delta_x;
			y = y + delta_y;
			moves++;
			if (grid[y][x] == 'X')
			{
				find_inter(head, x, y, moves);
				printf("HIS %c\n", grid[y][x]);
			}
		}
	}

	int	min;

	head = head->next;
	min = head->wire_01 + head->wire_02;
	while (head)
	{
		if (min > head->wire_01 + head->wire_02)
			min = head->wire_01 + head->wire_02;
		head = head->next;
	}
	printf("ANS: %d\n", min);
	return (0);
}
