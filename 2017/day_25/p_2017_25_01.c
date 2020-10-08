/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_25_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 02:46:39 by home              #+#    #+#             */
/*   Updated: 2020/10/08 03:03:08 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define OFFSET (12425)

int		main(void)
{
	int		pos;
	int		step;
	int		result;
	char	state;
	bool	tape[OFFSET * 2] = { 0 };

	step = 0;
	result = 0;
	pos = OFFSET;
	state = 'A';
	while (step < 12425180)
	{ //Most of this was done through text manipulation.
		if (state == 'A')
		{
			if (tape[pos] == false)
			{
				tape[pos] = true;
				result++;
				pos++;
				state = 'B';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = false;
				result--;
				pos++;
				state = 'F';
			}
		}
		else if (state == 'B')
		{
			if (tape[pos] == false)
			{
				tape[pos] = false;
				pos--;
				state = 'B';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = true;
				pos--;
				state = 'C';
			}
		}
		else if (state == 'C')
		{
			if (tape[pos] == false)
			{
				tape[pos] = true;
				result++;
				pos--;
				state = 'D';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = false;
				result--;
				pos++;
				state = 'C';
			}
		}
		else if (state == 'D')
		{
			if (tape[pos] == false)
			{
				tape[pos] = true;
				result++;
				pos--;
				state = 'E';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = true;
				pos++;
				state = 'A';
			}
		}
		else if (state == 'E')
		{
			if (tape[pos] == false)
			{
				tape[pos] = true;
				result++;
				pos--;
				state = 'F';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = false;
				result--;
				pos--;
				state = 'D';
			}
		}
		else if (state == 'F')
		{
			if (tape[pos] == false)
			{
				tape[pos] = true;
				result++;
				pos++;
				state = 'A';
			}
			else if (tape[pos] == true)
			{
				tape[pos] = false;
				result--;
				pos--;
				state = 'E';
			}
		}

		step++;
	}
	printf("RESULT: %d\n", result);
}
