/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_04b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 07:51:31 by kmira             #+#    #+#             */
/*   Updated: 2019/12/04 08:26:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#define STOP 643603
#define START 171309

int	valid(int guess)
{
	int		doub;
	int		tmp;
	int		arr[10];

	doub = 0;
	tmp = guess;
	bzero(arr, sizeof(arr));
	while (tmp != 0)
	{
		arr[tmp % 10]++;
		tmp /= 10;
	}
	int k;

	k = 0;
	while (k <= 9)
	{
		if (arr[k] == 2)
			doub = 1;
		k++;
	}
	if (doub == 0)
		return (0);

	int prev;

	tmp = guess;
	while (tmp >= 9)
	{
		prev = tmp % 10;
		tmp /= 10;
		if (prev < tmp % 10)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	count;
	int	guess;

	count = 0;
	guess = START;
	while (guess <= STOP)
	{
		if (valid(guess))
		{
			printf("%d\n", guess);
			count++;
		}
		guess++;
	}
	printf("Finished with %d\n", count);
	return (0);
}
