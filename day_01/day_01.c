/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:08:11 by marvin            #+#    #+#             */
/*   Updated: 2019/12/16 00:13:59 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 10000

int	main(void)
{
	int		fd;
	int		ret;
	char	test[SIZE + 1];
	char	*at;
	int		fuel;
	int		result;
	int		sum;

	fd = open("day_01.txt", O_RDONLY);
	ret = read(fd, test, SIZE);
	test[ret] = '\0';

	result = 0;
	at = test;
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
		at = strchr(at, '\n') + 1;
	}
	printf("RESULT: %d\n", result);
	system("leaks a.out");

	return (0);
}
