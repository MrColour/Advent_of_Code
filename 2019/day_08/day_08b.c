/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_08b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:20:17 by kmira             #+#    #+#             */
/*   Updated: 2019/12/09 13:35:04 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.c"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
	int				j;
	char			finsihed;
	char			*at;
	char			image[25 * 6];
	char			gate[25 * 6];

	i = 0;
	at = &input[0];
	memset(image, '9', sizeof(image));
	memset(gate, '0', sizeof(gate));
	while (i < sizeof(input) - 1)
	{
		j = 0;
		finsihed = 1;
		printf("%c\n", at[0]);
		while (j < (25 * 6))
		{
			if (gate[j] == '0')
			{
				if (at[j] == '0')
				{
					image[j] = '.';
					gate[j] = '1';
				}
				else if (at[j] == '1')
				{
					image[j] = '1';
					gate[j] = '1';
				}
				finsihed = 0;
			}
			j++;
		}
		if (finsihed == 1)
			break ;
		i += 25 * 6;
		at = &input[i];
	}

	i = 0;
	while (i < 6)
	{
		write(1, &image[i * 25], 25);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
