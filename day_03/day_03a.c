/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_03a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:40:00 by marvin            #+#    #+#             */
/*   Updated: 2019/12/04 04:22:56 by kmira            ###   ########.fr       */
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

typedef struct	s_queue
{
	int				x;
	int				y;
	struct s_queue	*next;
}				t_queue;

void		find_nearest_intersection(char **grid, int start_x, int start_y)
{
	t_queue	*head;
	t_queue	*last;
	t_queue	*tmp;
	int		tmp_x;
	int		tmp_y;

	tmp_x = start_x;
	tmp_y = start_y;

	head = malloc(sizeof(*head));
	head->x = start_x;
	head->y = start_y;
	grid[start_y][start_x] = 'C';
	head->next = NULL;
	last = head;

	while (head)
	{
		if (grid[head->y + 1][head->x] != 'X' && grid[head->y + 1][head->x] != 'C')
		{
			grid[head->y + 1][head->x] = 'C';
			last->next = malloc(sizeof(*last));
			last = last->next;
			last->x = head->x;
			last->y = head->y + 1;
		}
		else if (grid[head->y + 1][head->x] == 'X')
		{
			start_x = head->x;
			start_y = head->y + 1;
			break ;
		}
		if (grid[head->y - 1][head->x] != 'X' && grid[head->y - 1][head->x] != 'C')
		{
			grid[head->y - 1][head->x] = 'C';
			last->next = malloc(sizeof(*last));
			last = last->next;
			last->x = head->x;
			last->y = head->y - 1;
		}
		else if (grid[head->y - 1][head->x] == 'X')
		{
			start_x = head->x;
			start_y = head->y - 1;
			break ;
		}
		if (grid[head->y][head->x + 1] != 'X' && grid[head->y][head->x + 1] != 'C')
		{
			grid[head->y][head->x + 1] = 'C';
			last->next = malloc(sizeof(*last));
			last = last->next;
			last->x = head->x + 1;
			last->y = head->y;
		}
		else if (grid[head->y][head->x + 1] == 'X')
		{
			start_x = head->x + 1;
			start_y = head->y;
			break ;
		}
		if (grid[head->y][head->x - 1] != 'X' && grid[head->y][head->x - 1] != 'C')
		{
			grid[head->y][head->x - 1] = 'C';
			last->next = malloc(sizeof(*last));
			last = last->next;
			last->x = head->x - 1;
			last->y = head->y;
		}
		else if (grid[head->y][head->x - 1] == 'X')
		{
			start_x = head->x - 1;
			start_y = head->y;
			break ;
		}
		tmp = head;
		head = head->next;
		free(tmp);
	}
	printf("(%4d, %4d) and %c\n", start_x, start_y, grid[start_y][start_x]);

	int	x_delta = start_x - tmp_x;
	int	y_delta = start_y - tmp_y;

	if (x_delta < 0)
		x_delta *= -1;
	if (y_delta < 0)
		y_delta *= -1;

	printf("ANS: %d\n", y_delta + x_delta);
}

#define SIZE 10000

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

		j = -1;
		if (type == 'U')
			while (++j < curr)
			{
				y--;
				grid[y][x] = '1';
			}
		if (type == 'D')
			while (++j < curr)
			{
				y++;
				grid[y][x] = '1';
			}
		if (type == 'R')
			while (++j < curr)
			{
				x++;
				grid[y][x] = '1';
			}
		if (type == 'L')
			while (++j < curr)
			{
				x--;
				grid[y][x] = '1';
			}
	}

	i = 0;
	x = grid_size / 2;
	y = grid_size / 2;
	while (wire_02[i] != '\0')
	{
		type = wire_02[i++];
		curr = atoi(&wire_02[i]);
		while (isdigit(wire_02[i]))
			i++;
		if (wire_02[i] == ',')
			i++;

		j = -1;
		if (type == 'U')
		{
			while (++j < curr)
			{
				y--;
				if (grid[y][x] == '1')
					grid[y][x] = 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
			}
		}
		if (type == 'D')
		{
			while (++j < curr)
			{
				y++;
				if (grid[y][x] == '1')
					grid[y][x] = 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
			}
		}
		if (type == 'R')
		{
			while (++j < curr)
			{
				x++;
				if (grid[y][x] == '1')
					grid[y][x] = 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
			}
		}
		if (type == 'L')
		{
			while (++j < curr)
			{
				x--;
				if (grid[y][x] == '1')
					grid[y][x] = 'X';
				else if (grid[y][x] != 'X')
					grid[y][x] = '2';
			}
		}
	}

	x = grid_size / 2;
	y = grid_size / 2;
	find_nearest_intersection(grid, x, y);

	return (0);
}
