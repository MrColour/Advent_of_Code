/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_01_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:45:11 by home              #+#    #+#             */
/*   Updated: 2020/10/17 18:03:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

# define SIZE (1000000)
# define OFFSET (SIZE / 2)

int		main(void)
{
	char	*str_file;
	char	**freq_delta;
	int		size;
	int		i;
	int		curr_freq;
	int		past[SIZE] = { 0 };

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(freq_delta, str_file, size);

	i = 0;
	curr_freq = 0;
	past[curr_freq + OFFSET] = 1;
	while (1)
	{
		curr_freq += atoi(freq_delta[i]);
		if (past[curr_freq + OFFSET] == 0)
			past[curr_freq + OFFSET] = 1;
		else
			break ;
		i++;
		if (i > size - 2)
			i = 0;
	}
	answer(d, curr_freq);
	return (0);
}
