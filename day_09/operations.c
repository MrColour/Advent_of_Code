/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:49:32 by kmira             #+#    #+#             */
/*   Updated: 2019/12/09 14:49:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_09.h"

void	operation_01(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	process[process[*ptr + 3]] = reg[2] + reg[1];
	*ptr += 4;
}

void	operation_02(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	process[process[*ptr + 3]] = reg[2] * reg[1];
	*ptr += 4;
}

void	operation_05(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	if (reg[1] == 0)
		*ptr += 3;
	else
		*ptr = reg[2];
}

void	operation_06(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	if (reg[1] == 0)
		*ptr = reg[2];
	else
		*ptr += 3;
}

void	operation_07(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	reg[3] = process[*ptr + 3];
	if (reg[1] < reg[2])
		process[reg[3]] = 1;
	else
		process[reg[3]] = 0;
	*ptr += 4;
}

void	operation_08(long *process, long *reg, long *ptr, long relative_base)
{
	reg[1] = get_value(process, (process[*ptr] / 100) % 10, process[*ptr + 1], relative_base);
	reg[2] = get_value(process, (process[*ptr] / 1000) % 10, process[*ptr + 2], relative_base);
	reg[3] = process[*ptr + 3];
	if (reg[1] == reg[2])
		process[reg[3]] = 1;
	else
		process[reg[3]] = 0;
	*ptr += 4;
}
