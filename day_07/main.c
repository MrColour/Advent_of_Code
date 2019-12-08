/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:01 by marvin            #+#    #+#             */
/*   Updated: 2019/12/07 16:25:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_07.h"

void	intcode(int	*process, int amp)
{
	int	op;
	int	reg[4];

	op = process[g_ptr[amp]];
	clear_reg(reg, sizeof(reg) / sizeof(*reg));
	printf("OP %d at AMP %d\n", op, amp);
	while (op != 99)
	{
		clear_reg(reg, sizeof(reg) / sizeof(*reg));
		if (op % 10 == 1)
			operation_01(process, reg, &g_ptr[amp]);
		else if (op % 10 == 2)
			operation_02(process, reg, &g_ptr[amp]);
		else if (op % 10 == 3)
		{
			reg[1] = get_value(process, (process[g_ptr[amp]] / 100) % 10, process[g_ptr[amp] + 1]);
			if (g_first[amp] == 1)
				process[process[g_ptr[amp] + 1]] = get_input(READ, amp);
			else
				process[process[g_ptr[amp] + 1]] = get_input(PHASE, amp);
			g_first[amp] = 1;
			g_ptr[amp] += 2;
		}
		else if (op % 10 == 4)
		{
			reg[1] = get_value(process, (process[g_ptr[amp]] / 100) % 10, process[g_ptr[amp] + 1]);
			printf("OUT: %d; error before %d\n", reg[1] , g_ptr[amp]);
			g_ptr[amp] += 2;
			// return ;
		}
		else if (op % 10 == 5)
			operation_05(process, reg, &g_ptr[amp]);
		else if (op % 10 == 6)
			operation_06(process, reg, &g_ptr[amp]);
		else if (op % 10 == 7)
			operation_07(process, reg, &g_ptr[amp]);
		else if (op % 10 == 8)
			operation_08(process, reg, &g_ptr[amp]);
		else
		{
			printf("Wrong instruction: OP: %d\n", process[g_ptr[amp]]);
			break ;
		}

		op = process[g_ptr[amp]];
		printf("NEW OP %d\n", op);
	}
	printf("HALT %d\n", amp);
	if (op == 99)
		g_halts[amp] = 1;
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
	printf("OUTPUT: %d\n", g_output[0]);
}

int		main(void)
{
	int		test_example[] =
	{
		3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,
		27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5
	};

	// feedback_loop(test_example, sizeof(test_example));

	intcode(test_example, 0);

	return (0);
}
