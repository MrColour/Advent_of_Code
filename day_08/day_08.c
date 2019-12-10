/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_08.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:20:17 by kmira             #+#    #+#             */
/*   Updated: 2019/12/09 12:50:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.c"
#include <stdio.h>

int		count_n(char *str, char key)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < (25 * 6))
	{
		if (str[i] == key)
			result++;
		i++;
	}
	return (result);
}

int		main(void)
{
	unsigned long	i;
	int				min;
	int				curr;
	char			*at;
	char			*largest;

	i = 0;
	largest = &input[0];
	min = count_n(&input[0], '0');
	while (i < sizeof(input) - 1)
	{
		at = &input[i];
		curr = count_n(at, '0');
		if (curr < min)
		{
			largest = &input[i];
			min = curr;
		}
		printf("MIN: %d\n", min);
		i += (25 * 6);
	}

	int	amount_1;
	int	amount_2;

	amount_1 = count_n(largest, '1');
	amount_2 = count_n(largest, '2');
	printf("%d x %d is %d\n", amount_1, amount_2, amount_1 * amount_2);
	return (0);
}
