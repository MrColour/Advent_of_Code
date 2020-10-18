/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_06_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:03:29 by home              #+#    #+#             */
/*   Updated: 2020/10/18 02:27:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_coord
{
	int			count;
	int			x;
	int			y;
}				t_coord;

#define SIZE (400)

int	closest(t_coord *coords, int size, int x, int y)
{
	int	i;
	int	min;
	int	man_dis;
	int	result;

	i = 0;
	min = INT_MAX;
	result = -1;
	while (i < size)
	{
		man_dis = abs(coords[i].x - x) + abs(coords[i].y - y);
		if (man_dis == min) //More than one are close
			result = -1;
		if (man_dis < min)
		{
			min = man_dis;
			result = i;
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	t_coord	*coords;
	int		size;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file);

	coords = calloc(size, sizeof(*coords));
	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &coords[_i].x);
		_tok += fetch_int(_tok, &coords[_i].y);
	)

	int		y;
	int		x;
	int		close_coor;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			close_coor = closest(coords, size, x, y);
			if (close_coor != -1)
				coords[close_coor].count++;

			if ((y == 0 || x == 0 || y + 1 == SIZE || x + 1 == SIZE) && close_coor != -1)
				coords[close_coor].count = INT_MIN;

			x++;
		}
		y++;
	}

	int		*result;

	result = last(coords, size, sizeof(*coords), int_cmp_asc);
	answer(d, *result)
	return (0);
}