/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:27:03 by kmira             #+#    #+#             */
/*   Updated: 2019/12/09 15:26:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_09.h"

void	clear_reg(long *registers, long size)
{
	long	i;

	i = 0;
	while (i < size)
		registers[i++] = 0;
}

long		get_value(long *memory, long mode, long value, long relative_base)
{
	long	result;

	if (mode == 0)
		result = memory[value];
	if (mode == 1)
		result = value;
	if (mode == 2)
		result = memory[value + relative_base];
	return (result);
}

void	reset(void)
{
	long i;

	g_output[0] = 0;
	i = 0;
	while (i < 5)
		g_halts[i++] = 0;
	i = 0;
	while (i < 5)
		g_first[i++] = 0;
	i = 0;
	while (i < 5)
		g_ptr[i++] = 0;
}
