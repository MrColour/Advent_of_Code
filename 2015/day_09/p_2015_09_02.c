/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_09_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:17:22 by home              #+#    #+#             */
/*   Updated: 2020/09/28 20:12:14 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		calc_dis(int *visit_order, int size, int seek)
{
	int	i;
	int	from, to;
	int	result;

	if (seek == 0)
		return (0);

	i = 0;
	while (i < size)
	{
		if (visit_order[i] == seek)
			from = i + 1;
		if (visit_order[i] == seek + 1)
			to = i + 1;
		i++;
	}

	if (from > to)
		SWAP(from, to, int)

	result = 0;
	result = ((from == 1 && to == 2) ? 66 : result);
	result = ((from == 1 && to == 3) ? 28 : result);
	result = ((from == 1 && to == 4) ? 60 : result);
	result = ((from == 1 && to == 5) ? 34 : result);
	result = ((from == 1 && to == 6) ? 34 : result);
	result = ((from == 1 && to == 7) ? 3 : result);
	result = ((from == 1 && to == 8) ? 108 : result);

	result = ((from == 2 && to == 3) ? 22 : result);
	result = ((from == 2 && to == 4) ? 12 : result);
	result = ((from == 2 && to == 5) ? 91 : result);
	result = ((from == 2 && to == 6) ? 121 : result);
	result = ((from == 2 && to == 7) ? 111 : result);
	result = ((from == 2 && to == 8) ? 71 : result);

	result = ((from == 3 && to == 4) ? 39 : result);
	result = ((from == 3 && to == 5) ? 113 : result);
	result = ((from == 3 && to == 6) ? 130 : result);
	result = ((from == 3 && to == 7) ? 35 : result);
	result = ((from == 3 && to == 8) ? 40 : result);

	result = ((from == 4 && to == 5) ? 63 : result);
	result = ((from == 4 && to == 6) ? 21 : result);
	result = ((from == 4 && to == 7) ? 57 : result);
	result = ((from == 4 && to == 8) ? 83 : result);

	result = ((from == 5 && to == 6) ? 9 : result);
	result = ((from == 5 && to == 7) ? 50 : result);
	result = ((from == 5 && to == 8) ? 60 : result);

	result = ((from == 6 && to == 7) ? 27 : result);
	result = ((from == 6 && to == 8) ? 81 : result);

	result = ((from == 7 && to == 8) ? 90 : result);

	return (result);
}

void	depth_first_permute(int visited, int limit, bool *visited_list, int *visit_order, int curr_dis, int *max_dis)
{
	int		i;
	int		new_dis;

	if (visited == limit)
	{
		*max_dis = MAX(*max_dis, curr_dis);
		return ; // Possible route, and update to max_dis.
	}

	i = 0;
	while (i < limit)
	{
		if (visited_list[i] == false)
		{
			visited_list[i] = true;
			visit_order[i] = visited + 1;

			new_dis = calc_dis(visit_order, limit, visited) + curr_dis;
			depth_first_permute(visited + 1, limit, visited_list, visit_order, new_dis, max_dis);

			visited_list[i] = false;
			visit_order[i] = 0;
		}
		i++;
	}
}

int		main(void)
{
	int		max_dis;
	int		cities;
	int		*visit_order;
	bool	*visited_list;

	cities = 8;
	max_dis = INT_MIN;
	visit_order = calloc(cities, sizeof(*visit_order));
	visited_list = calloc(cities, sizeof(*visited_list));

	depth_first_permute(0, cities, visited_list, visit_order, 0, &max_dis);

	printf("RESULT: %d\n", max_dis);
	return (0);
}