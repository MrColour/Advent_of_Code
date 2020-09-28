/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_24_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 01:26:05 by home              #+#    #+#             */
/*   Updated: 2020/09/27 23:42:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct s_queue t_queue;

struct s_queue
{
	int		x;
	int		y;

	int		steps;

	t_queue	*next;
};

void	reset_map(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'S')
				map[row][col] = '.';
			col++;
		}
		row++;
	}
}

void	add_node(int y, int x, int steps, t_queue **last, char **map)
{
	t_queue *new_elem;

	new_elem = calloc(1, sizeof(*new_elem));
	new_elem->x = x;
	new_elem->y = y;
	new_elem->steps = steps;
	new_elem->next = NULL;

	if (map[y][x] == '.')
		map[y][x] = 'S';

	(*last)->next = new_elem;
	*last = new_elem;
}

void	bfs_fill(int **dis, char **map, int x, int y)
{
	t_queue	*queue;
	t_queue	*last;
	int		init_no;

	init_no = map[y][x] - '0';
	queue = &((t_queue){x, y, 0, NULL});
	last = queue;

	while (1 && queue != NULL)
	{
		if ( map[queue->y + 1][queue->x + 0] == '.' || isdigit(map[queue->y + 1][queue->x + 0]))
		add_node(queue->y + 1, queue->x + 0, queue->steps + 1, &last, map);
		if ( map[queue->y - 1][queue->x + 0] == '.' || isdigit(map[queue->y - 1][queue->x + 0]))
		add_node(queue->y - 1, queue->x + 0, queue->steps + 1, &last, map);
		if ( map[queue->y + 0][queue->x + 1] == '.' || isdigit(map[queue->y + 0][queue->x + 1]))
		add_node(queue->y + 0, queue->x + 1, queue->steps + 1, &last, map);
		if ( map[queue->y + 0][queue->x - 1] == '.' || isdigit(map[queue->y + 0][queue->x - 1]))
		add_node(queue->y + 0, queue->x - 1, queue->steps + 1, &last, map);

		if (isdigit(map[queue->y][queue->x]) && dis[init_no][map[queue->y][queue->x] - '0'] == 0)
			dis[init_no][map[queue->y][queue->x] - '0'] = queue->steps;

		queue = queue->next;
	}
	reset_map(map);
}

void	fill_dis_table(int **dis, char **map)
{
	int	row;
	int	col;
	int	num;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] != '.' && map[row][col] != '#')
			{
				num = map[row][col];
				bfs_fill(dis, map, col, row);
				map[row][col] = num;
			}
			col++;
		}
		row++;
	}
}

void	dfs_permute(int *choosen, int curr, int *min, int **dis_table, int from, int steps)
{
	int		i;
	int		add;
	bool	leaf;

	if (curr > *min)
		return ;

	i = 0;
	leaf = true;
	while (i <= 7)
	{
		if (choosen[i] == 0)
		{
			choosen[i] = steps + 1;
			add = dis_table[from][i];
			leaf = false;
			dfs_permute(choosen, curr + add, min, dis_table, i, steps + 1);
			choosen[i] = 0;
		}
		i++;
	}

	if (leaf == true && curr < *min)
		*min = curr;
}

int		main(void)
{
	char	*str_file;
	// char	*s_tok;
	char	**map;

	int		i;
	int		newlines;
	int		**dis;

	// i = 0;
	// dis = calloc(11, sizeof(*dis));
	// while (i < 10)
	// {
	// 	dis[i] = calloc(10, sizeof(**dis));
	// 	i++;
	// }

	ALLOC_2D(dis, 11, 10, calloc_wrapper, NULL)

	dis = &(dis[1]);

	str_file = extract_file("input.txt");
	newlines = count_occur("\n", str_file);

	// i = 0;
	// map = calloc(newlines, sizeof(*map));
	// s_tok = strtok(str_file, "\n");
	// while (s_tok != NULL)
	// {
	// 	map[i] = s_tok;
	// 	s_tok = strtok(NULL, "\n");
	// 	i++;
	// }

	NEWLINE_SPLIT(map, str_file, newlines)

	fill_dis_table(dis, map);

	int		min;
	int		choosen[10] = { 0 };

	min = INT_MAX;
	choosen[0] = 1;
	dfs_permute(choosen, 0, &min, dis, 0, 0);
	printf("RESULT: %d\n", min);
	return (0);
}
