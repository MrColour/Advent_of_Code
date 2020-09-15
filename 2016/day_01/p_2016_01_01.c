/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:19:56 by home              #+#    #+#             */
/*   Updated: 2020/09/14 19:33:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		dir;
	int		x;
	int		y;
	int		steps;

	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, " ");

	dir = 0;
	x = 0;
	y = 0;
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

		printf("%s with %d\n", s_tok, steps);
		s_tok = strtok(NULL, " ");
	}
	if (x <= 0)
		x *= -1;
	if (y <= 0)
		y *= -1;
	printf("%d\n", (y + x));
	return (0);
}
