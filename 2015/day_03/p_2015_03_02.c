/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:01:35 by home              #+#    #+#             */
/*   Updated: 2020/10/12 22:39:27 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct	pos2i
{
	int		x;
	int		y;
}				pos2i;

void	process_str_file(pos2i *dest, char *str_file)
{
	size_t i;
	int		s_x, s_y;
	int		r_x, r_y;
	int		*c_x, *c_y;

	i = 0;

	s_x = 0;
	s_y = 0;
	r_x = 0;
	r_y = 0;

	c_x = &s_x;
	c_y = &s_y;
	while (str_file[i] != '\0')
	{
		direction("^v<>", str_file[i], c_x, c_y);

		dest[i].x = *c_x;
		dest[i].y = *c_y;

		c_x = (int *)((uintptr_t)c_x ^ (((uintptr_t)&r_x ^ (uintptr_t)&s_x)));
		c_y = (int *)((uintptr_t)c_y ^ (((uintptr_t)&r_y ^ (uintptr_t)&s_y)));
		i++;
	}
	dest[i].x = 0;
	dest[i].y = 0;
}

int		quad_cmp(const void *ptr_a, const void *ptr_b)
{
	const pos2i *a;
	const pos2i *b;

	a = ptr_a;
	b = ptr_b;
	if (a->x < b->x)
		return (1);
	else if (a->x == b->x && a->y > b->y)
		return (1);
	else
		return (-1);
}

int		main(void)
{
	char	*str_file;
	int		i;
	int		visits;
	int		unique;
	pos2i	*positions;

	str_file = extract_file("input.txt");
	visits = strlen(str_file) + 1;
	positions = calloc(visits, sizeof(*positions));

	process_str_file(positions, str_file);
	qsort(positions, visits, sizeof(*positions), quad_cmp);

	i = 1;
	unique = 1;
	while (i < visits)
	{
		if (positions[i - 1].x != positions[i].x || positions[i - 1].y != positions[i].y)
			unique++;

		// printf("(%d, %d)\n", positions[i].x, positions[i].y);
		i++;
	}

	answer(d, unique);
	return (0);
}
