/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_07a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:01 by marvin            #+#    #+#             */
/*   Updated: 2019/12/07 14:45:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRTUAL_MEMORY_SIZE 10000

#define EXPECTED 19690720
#define STD_OUT 0
#define STD_IN 1

#define PHASE_A 0
#define PHASE_B 1
#define PHASE_C 2
#define PHASE_D 3
#define PHASE_E 4

#define READ 0
#define RESET 1

int		g_output[] = {0};

int		g_input_sequence[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0 ,0
};

int		g_phase_setting[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0 ,0
};

int		g_phase_setting_cpy[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0 ,0
};

int	set_stop(void)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (g_phase_setting[i] != 4)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid()
{
	int i;
	int	arr[5];

	i = 0;
	bzero(arr, sizeof(arr));
	while (i < 5)
	{
		if (arr[g_phase_setting[i]] == 1)
			return (0);
		arr[g_phase_setting[i]] += 1;
		i++;
	}
	return (1);
}

void	add_input(void)
{
	int	i;
	int	carry;

	i = 3;
	carry = 0;
	g_phase_setting[4] += 1;
	if (g_phase_setting[4] > 4)
	{
		carry = 1;
		g_phase_setting[4] = 0;
	}
	while (i >= 0 && carry == 1)
	{
		g_phase_setting[i] = (g_phase_setting[i] + carry);
		if (g_phase_setting[i] > 4)
			carry = 1;
		else
			carry = 0;
		g_phase_setting[i] = g_phase_setting[i] % 5;
		i--;
	}
}

int		get_input(int op)
{
	static int	at;
	int			input;

	input = 0;
	if (op == RESET)
		at = 0;
	else if (op == READ)
	{
		printf("INPUT: %d\n", g_input_sequence[at]);
		input = g_input_sequence[at];
		at++;
	}
	return (input);
}

void	clear_reg(int *registers, int size)
{
	int	i;

	i = 0;
	while (i < size)
		registers[i++] = 0;
}

int		get_value(int *memory, int mode, int value)
{
	int	result;

	if (mode == 0)
		result = memory[value];
	if (mode == 1)
		result = value;
	return (result);
}

void	intcode(int	*program)
{
	int	ptr;
	int	reg[4];
	int	stream[2];

	int	op;
	ptr = 0;
	op = program[ptr];
	clear_reg(reg, sizeof(reg) / sizeof(*reg));
	while (op != 99)
	{
		clear_reg(reg, sizeof(reg) / sizeof(*reg));
		if (op % 10 == 1)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program, (program[ptr] / 1000) % 10, program[ptr + 2]);
			program[program[ptr + 3]] = reg[2] + reg[1];
			ptr += 4;
		}
		else if (op % 10 == 2)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program ,(program[ptr] / 1000) % 10, program[ptr + 2]);
			program[program[ptr + 3]] = reg[2] * reg[1];
			ptr += 4;
		}
		else if (op % 10 == 3)
		{
			//Storing into value doesn't make sense. Storing into address does.
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			program[program[ptr + 1]] = get_input(READ);
			ptr += 2;
		}
		else if (op % 10 == 4)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			stream[STD_OUT] = reg[1];
			// printf("OUT: %d; error before %d\n", stream[STD_OUT], ptr);
			ptr += 2;
		}
		else if (op % 10 == 5)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program, (program[ptr] / 1000) % 10, program[ptr + 2]);
			if (reg[1] == 0)
				ptr += 3;
			else
				ptr = reg[2];
		}
		else if (op % 10 == 6)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program, (program[ptr] / 1000) % 10, program[ptr + 2]);
			if (reg[1] == 0)
				ptr = reg[2];
			else
				ptr += 3;
		}
		else if (op % 10 == 7)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program, (program[ptr] / 1000) % 10, program[ptr + 2]);
			reg[3] = program[ptr + 3];
			if (reg[1] < reg[2])
				program[reg[3]] = 1;
			else
				program[reg[3]] = 0;
			ptr += 4;

		}
		else if (op % 10 == 8)
		{
			reg[1] = get_value(program, (program[ptr] / 100) % 10, program[ptr + 1]);
			reg[2] = get_value(program, (program[ptr] / 1000) % 10, program[ptr + 2]);
			reg[3] = program[ptr + 3];
			if (reg[1] == reg[2])
				program[reg[3]] = 1;
			else
				program[reg[3]] = 0;
			ptr += 4;
		}
		else
		{
			printf("Wrong instruction: OP: %d\n", program[ptr]);
			break ;
		}

		op = program[ptr];
	}
	g_output[0] = stream[STD_OUT];
}

int		main(void)
{
	int		Amplifier_Controller_Software[] = {
		3,8,1001,8,10,8,105,1,0,0,21,46,55,72,85,110,191,272,353,434,99999,3,9,
		1002,9,5,9,1001,9,2,9,102,3,9,9,101,2,9,9,102,4,9,9,4,9,99,3,9,102,5,
		9,9,4,9,99,3,9,1002,9,2,9,101,2,9,9,1002,9,2,9,4,9,99,3,9,1002,9,4,9,
		101,3,9,9,4,9,99,3,9,1002,9,3,9,101,5,9,9,1002,9,3,9,101,3,9,9,1002,9
		,5,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,
		9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,
		9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,102,
		2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,
		1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,
		3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,1001,9,
		2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,
		9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,
		101,2,9,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,
		3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,
		4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,101,
		1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,
		9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,
		9,2,9,4,9,3,9,1001,9,2,9,4,9,99
	};

	int		attempt[VIRTUAL_MEMORY_SIZE];

	int		test_run[] =
	{
		3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0
	};

	bzero(attempt, sizeof(attempt));
	// memcpy(attempt, air_cond, sizeof(air_cond));
	int	max;
	max = 0;

	int stop;
	int d;
	int	stop_condition;

	max = 0;
	stop = 0;
	stop_condition = 0;
	while (stop_condition == 0)
	{
		d = 0;
		add_input();
		while (is_valid() == 0 && set_stop() == 0)
			add_input();
		if (set_stop() == 1)
			break ;
		while (d < 5)
		{
			printf("%d ", g_phase_setting[d]);
			d++;
		}

		get_input(RESET);
		memcpy(attempt, Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));
		g_input_sequence[0] = g_phase_setting[PHASE_A];
		g_input_sequence[1] = 0;
		intcode(attempt);

		get_input(RESET);
		memcpy(attempt, Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));
		g_input_sequence[0] = g_phase_setting[PHASE_B];
		g_input_sequence[1] = g_output[0];
		intcode(attempt);

		get_input(RESET);
		memcpy(attempt, Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));
		g_input_sequence[0] = g_phase_setting[PHASE_C];
		g_input_sequence[1] = g_output[0];
		intcode(attempt);

		get_input(RESET);
		memcpy(attempt, Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));
		g_input_sequence[0] = g_phase_setting[PHASE_D];
		g_input_sequence[1] = g_output[0];
		intcode(attempt);

		get_input(RESET);
		memcpy(attempt, Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));
		g_input_sequence[0] = g_phase_setting[PHASE_E];
		g_input_sequence[1] = g_output[0];
		intcode(attempt);

		printf(" with: %15d thrust\n", g_output[0]);

		if (max < g_output[0])
		{
			max = g_output[0];
			memcpy(g_phase_setting_cpy, g_phase_setting, sizeof(g_phase_setting));
		}
		stop_condition = set_stop();
		stop++;
	}

	printf("MAX THRUST: %d\n", max);
	(void)d;
	(void)Amplifier_Controller_Software;
	(void)test_run;
	return (0);
}
