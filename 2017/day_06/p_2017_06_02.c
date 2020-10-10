/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_06_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:39:45 by home              #+#    #+#             */
/*   Updated: 2020/10/10 05:34:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	next_cycle(int *mem_banks, int size)
{
	int	i;
	int	most_i;
	int	most_v;

	i = 0;
	most_v = INT_MIN;
	while (i < size)
	{
		if (mem_banks[i] > most_v)
		{
			most_v = mem_banks[i];
			most_i = i;
		}
		i++;
	}

	mem_banks[most_i] = 0;

	most_i++;
	while (most_v > 0)
	{
		most_i %= size;

		mem_banks[most_i]++;

		most_i++;
		most_v--;
	}

	// i = 0;
	// while (i < size)
	// {
	// 	printf("%d ", mem_banks[i]);
	// 	i++;
	// }
	// printf("\n");
}

int	in_past(int **past_states, int cycle, int *search, int size)
{
	int	i;
	int	cmp;
	int	result;

	i = 0;
	result = 0;
	while (i < cycle - 1)
	{
		cmp = memcmp(past_states[i], search, size * sizeof(*search));
		if (cmp == 0)
		{
			result = i;
			break ;
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	int		*mem_banks;
	int		size;
	int		i;

	str_file = extract_file("input.txt");
	size = count_occur("\t", str_file) + 1; //Last number has a newline not a tab

	i = 0;
	mem_banks = calloc(size, sizeof(*mem_banks));
	while (i < size)
	{
		str_file += fetch_int(str_file, &(mem_banks[i]));
		i++;
	}

	int	cycles;
	int	*new_mem;
	int	**past_states;

	cycles = 0;
	past_states = calloc(100000, sizeof(*past_states));
	past_states[0] = mem_banks;
	while (in_past(past_states, cycles, past_states[cycles], size) == 0)
	{
		new_mem = calloc(size, sizeof(*new_mem));
		memcpy(new_mem, past_states[cycles], sizeof(*new_mem) * size);
		next_cycle(new_mem, size);
		cycles++;
		past_states[cycles] = new_mem;

	}

	int		loop_cycle;

	loop_cycle = cycles - in_past(past_states, cycles, past_states[cycles], size);
	printf("RESULT: %d\n", loop_cycle);
	return (0);
}
