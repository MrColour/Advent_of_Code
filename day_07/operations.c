/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:32:19 by kmira             #+#    #+#             */
/*   Updated: 2019/12/07 16:14:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_07.h"

void	operation_01(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	reg[3] = process[*ptr + 3];
	if (reg[1] < reg[2])
		process[reg[3]] = 1;
	else
		process[reg[3]] = 0;
	*ptr = *ptr + 4;
}

void	operation_02(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	process[process[*ptr + 3]] = reg[2] * reg[1];
	*ptr += 4;
}

void	operation_05(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	if (reg[1] == 0)
		*ptr += 3;
	else
		*ptr = reg[2];
}

void	operation_06(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	if (reg[1] == 0)
		*ptr = reg[2];
	else
		*ptr += 3;
}

void	operation_07(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	reg[3] = process[*ptr + 3];
	if (reg[1] < reg[2])
		process[reg[3]] = 1;
	else
		process[reg[3]] = 0;
	*ptr += 4;
}

void	operation_08(int *process, int *reg, int *ptr)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1]);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2]);
	reg[3] = process[*ptr + 3];
	if (reg[1] == reg[2])
		process[reg[3]] = 1;
	else
		process[reg[3]] = 0;
	*ptr += 4;
}
