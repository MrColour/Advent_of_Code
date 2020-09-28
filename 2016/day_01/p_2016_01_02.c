/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_01_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:35:28 by home              #+#    #+#             */
/*   Updated: 2020/09/28 03:40:49 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct s_location
{
	int		x;
	int		y;

	int		p_x;
	int		p_y;
}		t_location;

bool	intersect(t_location a, t_location b)
{
	bool	result;
	int		temp;

	result = false;
	if (a.p_x > a.x)
	{
		temp = a.x;
		a.x = a.p_x;
		a.p_x = temp;
	}

	if (a.p_y > a.y)
	{
		temp = a.y;
		a.y = a.p_y;
		a.p_y = temp;
	}

	if (b.p_x > b.x)
	{
		temp = b.x;
		b.x = b.p_x;
		b.p_x = temp;
	}

	if (b.p_y > b.y)
	{
		temp = b.y;
		b.y = b.p_y;
		b.p_y = temp;
	}

	if (a.p_y == a.y)
	{
		//NOTE: bound was modified for working program
		if (bound(b.p_y, a.y, b.y) && bound(a.p_x, b.x, a.x))
		{
			printf("here\n");
			result = true;
		}
		// if (b.y == b.p_y && (bound(a.p_x, b.x, a.x) || bound(a.p_x, b.p_x, a.x)))
		// 	result = true;
	}

	if (a.p_x == a.x)
	{
		if (bound(b.p_x, a.x, b.x) && bound(a.p_y, b.y, a.y))
		{
			printf("her\n");
			result = true;
		}
		// if (b.x == b.p_x && (bound(a.p_y, b.y, a.y) || bound(a.p_y, b.p_y, a.y)))
		// 	result = true;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		i;
	int		dir;
	int		steps;
	int		x;
	int		y;
	int		locations;
	t_location	*visit;

	str_file = extract_file("input.txt");

	i = 0;
	x = 0;
	y = 0;
	dir = 0;
	locations = count_occur(" ", str_file);
	s_tok = strtok(str_file, " ");
	visit = calloc(locations + 1, sizeof(*visit));
	visit[0].p_x = 0;
	visit[0].p_y = 0;
	while (s_tok != NULL)
	{
		steps = atoi(&(s_tok[1]));

		if (s_tok[0] == 'R')
			dir++;
		else
			dir--;


		if (dir == -1)
			dir = 3;

		if (dir == 4)
			dir = 0;


		if (dir == 0)
			y += steps;
		if (dir == 2)
			y -= steps;

		if (dir == 1)
			x += steps;
		if (dir == 3)
			x -= steps;

		visit[i].x = x;
		visit[i].y = y;

		visit[i + 1].p_x = x;
		visit[i + 1].p_y = y;

		// printf("(%d, %d) %d\n", visit[i].x, visit[i].y, i);
		// printf("%s with %d\n", s_tok, steps);
		s_tok = strtok(NULL, " ");
		i++;
	}
	printf("SIZE: %d\n", i);

	int	size;
	int	j;

	size = i;
	i = 0;
	while (i < size)
	{
		j = 0;
		x = visit[i].x;
		y = visit[i].y;
		printf("(%d, %d) %d\n", visit[i].x, visit[i].y, i);
		while (j < i)
		{
			if (intersect(visit[i], visit[j]) == true)
				break ;
			j++;
		}
		if (i != j)
			break ;
		i++;
	}
	printf("(%d, %d) to (%d, %d) intersect (%d, %d) to (%d, %d)\n",
		visit[i].p_x, visit[i].p_y, visit[i].x, visit[i].y,
		visit[j].p_x, visit[j].p_y, visit[j].x, visit[j].y);

	printf("%d\n", (119 + 14));
	return (0);
}
