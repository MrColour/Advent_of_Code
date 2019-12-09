/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:27:03 by kmira             #+#    #+#             */
/*   Updated: 2019/12/07 16:36:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "day_07.h"

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

int		get_input(int op, int amp)
{
	int			input;

	input = g_output[0];
	if (op == PHASE)
		input = g_phase_setting[amp];
	printf("INPUT: %d\n", input);
	return (input);
}
