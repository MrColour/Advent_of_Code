/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_20_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:59:43 by home              #+#    #+#             */
/*   Updated: 2020/10/14 03:21:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int	j;
	int	elf;
	int	stop;
	int	house;
	int	*presents;

	elf = 1;
	house = 0;
	stop = 33100000;
	presents = calloc(stop, sizeof(*presents));
	while (1)
	{
		j = 0;
		house = elf;
		if (presents[house] + (elf * 10) > stop)
			break ;
		while (j < (stop) && house < stop && presents[house] <= stop)
		{
			presents[house] += (elf * 10);
			// printf("House %d got %d presents.\n", house, presents[house]);
			house += elf;
			j++;
		}
		elf++;
	}
	printf("House %d got %d presents.\n", house, presents[house]);
	return (0);
}
