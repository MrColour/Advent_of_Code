/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:01 by marvin            #+#    #+#             */
/*   Updated: 2019/12/09 12:17:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_07.h"

int		g_output[] = {0};

int		g_halts[] = {0, 0, 0, 0, 0};
int		g_first[] = {0, 0, 0, 0, 0};

int		g_ptr[] = {0, 0, 0, 0, 0};

int		g_phase_setting[] = {
	5, 5, 5, 5, 5
};

void	intcode(int	*program, int amp)
{
	int	reg[4];

	int	op;
	op = program[g_ptr[amp]];
	clear_reg(reg, sizeof(reg) / sizeof(*reg));
	while (op != 99)
	{
		clear_reg(reg, sizeof(reg) / sizeof(*reg));
		if (op % 10 == 1)
			operation_01(program, reg, &g_ptr[amp]);
		else if (op % 10 == 2)
			operation_02(program, reg, &g_ptr[amp]);
		else if (op % 10 == 3)
		{
			//Storing into value doesn't make sense. Storing into address does.
			reg[1] = get_value(program, (program[g_ptr[amp]] / 100) % 10, program[g_ptr[amp] + 1]);
			if (g_first[amp] == 1)
				program[program[g_ptr[amp] + 1]] = get_input(READ, amp);
			else
				program[program[g_ptr[amp] + 1]] = get_input(PHASE, amp);
			g_first[amp] = 1;
			g_ptr[amp] += 2;
		}
		else if (op % 10 == 4)
		{
			reg[1] = get_value(program, (program[g_ptr[amp]] / 100) % 10, program[g_ptr[amp] + 1]);
			g_output[0] = reg[1];
			printf("OUT: %d; at %d\n", g_output[0], g_ptr[amp]);
			g_ptr[amp] += 2;
			return ;
		}
		else if (op % 10 == 5)
			operation_05(program, reg, &g_ptr[amp]);
		else if (op % 10 == 6)
			operation_06(program, reg, &g_ptr[amp]);
		else if (op % 10 == 7)
			operation_07(program, reg, &g_ptr[amp]);
		else if (op % 10 == 8)
			operation_08(program, reg, &g_ptr[amp]);
		else
		{
			printf("Wrong instruction: OP: %d\n", program[g_ptr[amp]]);
			break ;
		}

		op = program[g_ptr[amp]];
	}
	if (op == 99)
	{
		printf("AMP %d HALTED!\n", amp);
		g_halts[amp] = 1;
	}
}

void	feedback_loop(int *program, int size)
{
	int	amp_A[VIRTUAL_MEMORY_SIZE];
	int	amp_B[VIRTUAL_MEMORY_SIZE];
	int	amp_C[VIRTUAL_MEMORY_SIZE];
	int	amp_D[VIRTUAL_MEMORY_SIZE];
	int	amp_E[VIRTUAL_MEMORY_SIZE];

	bzero(amp_A, sizeof(amp_A));
	bzero(amp_B, sizeof(amp_B));
	bzero(amp_C, sizeof(amp_C));
	bzero(amp_D, sizeof(amp_D));
	bzero(amp_E, sizeof(amp_E));

	memcpy(amp_A, program, size);
	memcpy(amp_B, program, size);
	memcpy(amp_C, program, size);
	memcpy(amp_D, program, size);
	memcpy(amp_E, program, size);

	while (g_halts[PHASE_E] != 1)
	{
		printf("AMP A\n");
		intcode(amp_A, PHASE_A);
		printf("AMP B\n");
		intcode(amp_B, PHASE_B);
		printf("AMP C\n");
		intcode(amp_C, PHASE_C);
		printf("AMP D\n");
		intcode(amp_D, PHASE_D);
		printf("AMP E\n");
		intcode(amp_E, PHASE_E);
	}
}

int	set_stop(void)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (g_phase_setting[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid()
{
	int i;
	int	arr[20];

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
	if (g_phase_setting[4] > 9)
	{
		carry = 1;
		g_phase_setting[4] = 5;
	}
	while (i >= 0 && carry == 1)
	{
		g_phase_setting[i] = (g_phase_setting[i] + carry);
		if (g_phase_setting[i] > 9)
			carry = 1;
		else
			carry = 0;
		g_phase_setting[i] = 5 + (g_phase_setting[i] % 5);
		i--;
	}
}

void	reset(void)
{
	int i;

	g_output[0] = 0;
	i = 0;
	while (i < 5)
	{
		g_halts[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		g_first[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		g_ptr[i] = 0;
		i++;
	}
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

	int	d;
	int	max;
	int stop_cond;

	max = 0;
	stop_cond = 0;
	while (stop_cond == 0)
	{
		add_input();
		while (is_valid() == 0 && set_stop() == 0)
			add_input();
		if (set_stop() == 1)
			break ;
		d = 0;
		while (d < 5)
		{
			printf("%d ", g_phase_setting[d]);
			d++;
		}
		feedback_loop(Amplifier_Controller_Software, sizeof(Amplifier_Controller_Software));

		printf(" with: %15d thrust\n", g_output[0]);

		if (max < g_output[0])
			max = g_output[0];
		reset();
		stop_cond = set_stop();
	}


	printf("RESULT: %d\n", max);
	return (0);
}
