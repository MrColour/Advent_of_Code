/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_13_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:58:36 by home              #+#    #+#             */
/*   Updated: 2020/09/25 23:17:26 by home             ###   ########.fr       */
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

bool	is_open(int fav_no, int x, int y)
{
	int	calc;
	int	bits;

	if (x < 0 || y < 0)
		return (false);

	calc = (x * x) + (3 * x) + (2 * x * y) + y + (y * y);
	calc += fav_no;

	bits = 0;
	while (calc != 0)
	{
		bits += (calc & 1);
		calc = calc >> 1;
	}

	if (bits % 2 == 0)
		return (true);
	else
		return (false);
}

void	add_node(t_queue **last, int x, int y, int steps, char (*seen)[1000][1000])
{
	t_queue *new_elem;

	if ((*seen)[y][x] == 1 || steps > 50)
		return ;

	new_elem = calloc(1, sizeof(*new_elem));
	new_elem->x = x;
	new_elem->y = y;
	new_elem->steps = steps;
	new_elem->next = NULL;

	(*seen)[new_elem->y][new_elem->x] = 1;

	(*last)->next = new_elem;
	*last = new_elem;
}

int		main(void)
{
	int		fav_no;
	int		unique;
	char	seen[1000][1000];
	t_queue	*queue;
	t_queue	*last;

	bzero(seen, sizeof(seen));
	queue = &((t_queue){1, 1, 0, NULL});
	last = queue;

	unique = 0;
	seen[1][1] = 1;
	fav_no = atoi(extract_file("input.txt"));
	while (queue != NULL)
	{
		if (is_open(fav_no, queue->x + 0, queue->y + 1))
			add_node(&last, queue->x + 0, queue->y + 1, queue->steps + 1, &seen);
		if (is_open(fav_no, queue->x + 0, queue->y - 1))
			add_node(&last, queue->x + 0, queue->y - 1, queue->steps + 1, &seen);
		if (is_open(fav_no, queue->x + 1, queue->y + 0))
			add_node(&last, queue->x + 1, queue->y + 0, queue->steps + 1, &seen);
		if (is_open(fav_no, queue->x - 1, queue->y + 0))
			add_node(&last, queue->x - 1, queue->y + 0, queue->steps + 1, &seen);

		queue = queue->next;
		unique++;
	}
	printf("RESULT: %d\n", unique);
	return (0);
}
