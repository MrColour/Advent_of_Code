/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_06_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:03:29 by home              #+#    #+#             */
/*   Updated: 2020/10/18 02:34:08 by home             ###   ########.fr       */
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
#define WITHIN (10000)

int	valid(t_coord *coords, int size, int x, int y)
{
	int		i;
	int		man_dis;
	int		total_dis;

	i = 0;
	total_dis = 0;
	while (i < size)
	{
		man_dis = abs(coords[i].x - x) + abs(coords[i].y - y);
		total_dis += man_dis;
		i++;
	}
	if (total_dis < WITHIN)
		return (true);
	else
		return (false);
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
	int		result;

	y = 0;
	result = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			if (valid(coords, size, x, y) == true)
				result++;

			x++;
		}
		y++;
	}

	answer(d, result)
	return (0);
}
