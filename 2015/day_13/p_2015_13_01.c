/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_13_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 00:00:35 by home              #+#    #+#             */
/*   Updated: 2020/10/13 02:39:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		print_seats(int	*seat_order, int size, int **happiness, int s)
{
	int i;
	int n;

	int fi;
	int ti;

	int total;

	i = 0;
	total = 0;
	while (i < size)
	{
		n = i + 1;
		if (i + 1 == size)
			n = 0;

		int a;
		int b;

		fi = seat_order[i] - 1;
		ti = seat_order[n] - 1;

		a = 0;
		b = 0;

		a = happiness[fi][ti];
		b = happiness[ti][fi - 1];
		if (fi < ti)
		{
			a = happiness[fi][ti - 1];
			b = happiness[ti][fi];
		}

		if (fi + 1 == size)
		{
			b = happiness[ti][fi - 1];
		}

		total += (a + b);
		i++;
	}
	return (total);
}

void	depth_first_permute(int seated, int limit, bool *seated_list, int *seat_order, int *max_hap, int **happiness, int *dst)
{
	int		i;
	int		new_hap;

	if (seated == limit)
	{
		new_hap = print_seats(seat_order, limit, happiness, 0);
		*max_hap = MAX(new_hap, *max_hap);
		return ; // Possible route, and update to max_hap.
	}

	i = 0;
	while (i < limit)
	{
		if (seated_list[i] == false)
		{
			seated_list[i] = true;
			seat_order[i] = seated + 1;

			depth_first_permute(seated + 1, limit, seated_list, seat_order, max_hap, happiness, dst);

			seated_list[i] = false;
			seat_order[i] = 0;
		}
		i++;
	}
}

int		main(void)
{
	int		row;
	int		col;
	int		attendees;
	char	*s_tok;
	int		**happiness;

	s_tok = extract_file("input.txt");

	row = 0;
	attendees = 8;
	happiness = calloc(attendees, sizeof(*happiness));
	while (row < attendees)
	{
		col = 0;
		happiness[row] = calloc(attendees, sizeof(**happiness));
		while (col < attendees - 1)
		{
			s_tok = strpbrk(s_tok, DIGITS);
			happiness[row][col] = atoi(s_tok);

			if (s_tok[-2] == 'e')
				happiness[row][col] *= -1;

			s_tok += strspn(s_tok, DIGITS);
			col++;
		}
		row++;
	}

	int		max_happiness;
	int		*visit_order;
	int		*optimal_order;
	bool	*visited_list;

	max_happiness = INT32_MIN;
	visit_order = calloc(attendees, sizeof(*visit_order));
	visited_list = calloc(attendees, sizeof(*visited_list));
	optimal_order = calloc(attendees, sizeof(*optimal_order));
	depth_first_permute(0, attendees, visited_list, visit_order, &max_happiness, happiness, optimal_order);

	printf("RESULT: %d\n", max_happiness);

	return (0);
}