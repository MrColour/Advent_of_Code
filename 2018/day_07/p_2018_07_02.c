/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_07_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 02:46:26 by home              #+#    #+#             */
/*   Updated: 2020/10/18 21:21:48 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_instr
{
	bool		depend[256];
	bool		finished;
	bool		picked;
}				t_instr;

typedef struct	s_workers
{
	int		finish_time;
	char	id;
	bool	active;
}				t_workers;

#define LIM ('Z' + 1)
#define WORKERS (5)
#define DUR (60)

bool	unlocked(t_instr *steps, char c)
{
	int		i;
	bool	result;

	i = 'A';
	result = true;
	while (result == true && i < LIM)
	{
		if (steps[c].depend[i] == true && steps[i].finished == false)
			result = false;
		i++;
	}
	return (result);
}

// void	print_up_to(t_workers *workers, int stop, int at)
// {
// 	while (at < stop)
// 	{
// 		printf("%8d\t%c\t%c\t%c\t%c\t%c\n", at, workers[0].id, workers[1].id, workers[2].id, workers[3].id, workers[4].id);
// 		at++;
// 	}
// }

int		next_instr(t_instr *steps)
{
	int	i;

	i = 'A';
	while (i < LIM)
	{
		if (unlocked(steps, i) == true && steps[i].finished == false && steps[i].picked == false)
		{
			return (i);
		}
		i++;
	}
	return ('\0');
}

int		main(void)
{
	char	*str_file;
	char	*letter;
	char	*depends;
	t_instr	steps[256] = { 0 };

	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, "\n",
		depends = strchr(_tok, 'p') + 2;
		letter = strchr(_tok + 4, 'p') + 2;

		steps[*letter].depend[*depends] = true;
	)

	t_workers	workers[WORKERS] = { 0 };
	int		completed;
	int		i;
	int		min;
	int		sec;

	completed = 0;
	while (completed < LIM - 'A')
	{
		i = 0;
		while (i < WORKERS)
		{
			if (workers[i].active == false && next_instr(steps) != '\0')
			{
				workers[i].active = true;
				workers[i].id = next_instr(steps);
				steps[workers[i].id].picked = true;
				// printf("%c will finish at t = %d + %d %d\n", workers[i].id, workers[i].finish_time, DUR + (workers[i].id - 'A'), i);
				workers[i].finish_time += DUR + (workers[i].id - 'A' + 1);
				// printf("%c", workers[i].id);
			}
			i++;
		}

		i = 0;
		min = INT_MAX;
		while (i < WORKERS)
		{
			if (workers[i].active == true)
				min = MIN(min, workers[i].finish_time);
			i++;
		}

		i = 0;
		while (i < WORKERS)
		{
			if (workers[i].finish_time == min)
			{
				workers[i].active = false;
				steps[workers[i].id].finished = true;
				// print_up_to(workers, workers[i].finish_time, sec);
				sec = workers[i].finish_time;
				completed++;
			}

			if (workers[i].active == false)
				workers[i].finish_time = min;

			i++;
		}

	}

	answer(d, workers[0].finish_time) // Any of the workers will give the right answer.
	return (0);
}

