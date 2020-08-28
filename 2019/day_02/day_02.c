/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:01 by marvin            #+#    #+#             */
/*   Updated: 2019/12/03 11:53:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED 19690720

void	intcode(int	*program)
{
	int	val;
	int	ptr;

	int	op;
	ptr = 0;
	op = program[ptr];
	while (op != 99)
	{
		if (program[ptr + 1] <= 112 && program[ptr + 2] <= 112 && program[ptr + 3] <= 112)
		{
			if (op == 1)
				program[program[ptr + 3]] = program[program[ptr + 1]] + program[program[ptr + 2]];
			else if (op == 2)
				program[program[ptr + 3]] = program[program[ptr + 1]] * program[program[ptr + 2]];
		}
		else
			printf("Out of bounds!\n");
		ptr += 4;
		if (ptr > 112)
		{
			printf("Instrution pointer overflow!\n");
			break ;
		}
		op = program[ptr];
	}
}

int		main(void)
{
	int		gravity_assit[113] = {
		1,0,0,3,1,1,2,3,1,3,
		4,3,1,5,0,3,2,1,6,19,
		1,9,19,23,2,23,10,27,
		1,27,5,31,1,31,6,35,1,
		6,35,39,2,39,13,43,1,9,
		43,47,2,9,47,51,1,51,6,
		55,2,55,10,59,1,59,5,63,
		2,10,63,67,2,9,67,71,1,
		71,5,75,2,10,75,79,1,79,
		6,83,2,10,83,87,1,5,87,
		91,2,9,91,95,1,95,5,99,
		1,99,2,103,1,103,13,0,99,
		2,14,0,0};

	int		attempt[113];

	int	param1;
	int	param2;

	param1 = 0;
	while (param1 <= 99)
	{
		param2 = 0;
		while (param2 <= 99)
		{
			printf("Trying %d and %d", param1, param2);
			memcpy(attempt, gravity_assit, sizeof(gravity_assit));
			attempt[1] = param1;
			attempt[2] = param2;
			intcode(attempt);
			if (attempt[0] == EXPECTED)
				break ;
			printf(" Out: %d\n", attempt[0]);
			param2++;
		}
		if (attempt[0] == EXPECTED)
		{
			printf("\nFound the right answer\n");
			break ;
		}
		param1++;
	}

	printf("RESULT: %d\n", attempt[0]);
	printf("ANS: %d\n", 100 * param1 + param2);
	return (0);
}
