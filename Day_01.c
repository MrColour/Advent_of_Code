/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Day_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:08:11 by marvin            #+#    #+#             */
/*   Updated: 2019/12/02 12:08:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define SIZE 10000

int	main(void)
{
	int		fd;
	int		ret;
	char	test[SIZE + 1];
	char	*at;
	int		fuel;
	int		i;
	int		result;
	int		sum;

	fd = open("input.txt", O_RDONLY);
	ret = read(fd, test, SIZE);
	test[ret] = '\0';

	i = 0;
	result = 0;
	at = test;
	// while (i < 20)
	while (at - test < ret)
	{
		fuel = atoi(at);
		sum = (fuel / 3) - 2;
		if (sum > 0)
			result += sum;
		while (sum > 0)
		{
			sum = (sum / 3) - 2;
			if (sum > 0)
				result += sum;
		}
		printf("FUEL %3i: %d\n", i, fuel);
		at = strchr(at, '\n') + 1;
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}
