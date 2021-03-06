/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_04_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:26:19 by home              #+#    #+#             */
/*   Updated: 2020/10/17 22:30:22 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_guard
{
	int			total_min;
	int			sleep[60];
}				t_guard;

int		get_time_asleep(char **schedule, int at, t_guard *guard)
{
	int		start_min;
	int		end_min;
	char	*ptr;
	int		hour;
	int		min;
	int		i;

	ptr = strchr(schedule[at], ' ');
	ptr += fetch_int(ptr, &hour);
	ptr += fetch_int(ptr, &min);

	start_min = hour * 60 + min;

	ptr = strchr(schedule[at + 1], ' ');
	ptr += fetch_int(ptr, &hour);
	ptr += fetch_int(ptr, &min);

	end_min = hour * 60 + min;

	i = start_min;
	while (i < end_min)
	{
		guard->sleep[i]++;
		i++;
	}

	return (end_min - start_min);
}

int		main(void)
{
	int		size;
	char	*str_file;
	char	**schedule;
	t_guard	guards[5000] = { 0 };

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(schedule, str_file, size)

	psort(schedule, size, sizeof(schedule), str_cmp);

	int i;
	int	guard_id;

	int	min;

	i = 0;
	guard_id = 0;
	while (i < size)
	{
		// printf("S; %s\n", schedule[i]);
		if (strstr(schedule[i], "begins shift"))
			guard_id = atoi(strchr(schedule[i], '#') + 1);

		if (strstr(schedule[i], "falls asleep"))
			guards[guard_id].total_min += get_time_asleep(schedule, i, &guards[guard_id]);

		i++;
	}

	t_guard	*m_guard;
	int		*most_spent;

	m_guard = last(guards, 5000, sizeof(*guards), int_cmp_asc); // Only works if the first elem of struct is total min.
	most_spent = last(m_guard->sleep, 60, sizeof(int), int_cmp_asc);
	answer(lu, (m_guard - guards) * (most_spent - m_guard->sleep));
	return (0);
}
