/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_17_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 01:08:18 by home              #+#    #+#             */
/*   Updated: 2020/10/04 01:32:18 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		steps;
	int		rounds;

	steps = atoi(extract_file("input.txt"));

	int		i;
	int		curr;
	int		last_insert;

	rounds = 0;
	last_insert = 0;
	while (rounds < 50000000)
	{
		if (rounds % curr)

		curr += steps;
		curr %= rounds;
		rounds++;
	}
	printf("RESULT: %d\n", last_insert);
	return (0);
}
