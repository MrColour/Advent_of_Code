/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_17_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:55:43 by home              #+#    #+#             */
/*   Updated: 2020/10/05 18:40:54 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int	round;
	int	steps;
	int	zero;
	int	front;
	int	curr_pos;

	steps = atoi(extract_file("input.txt"));

	zero = 0;
	round = 0;
	front = 0;
	curr_pos = 0;
	while (round < 50000000)
	{
		curr_pos += steps;
		curr_pos %= (round + 1);
		if (curr_pos == zero) //Not sure why zero is always in the zero spot. In theory it could move?
			front = round + 1;
		// printf("POS: %d, length %d, F: %d\n", zero, round, front);
		curr_pos++;
		round++;
	}
	printf("Front: %d\n", front);
	return (0);
}
