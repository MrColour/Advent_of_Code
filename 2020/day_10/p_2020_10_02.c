/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_10_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/09 22:11:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		len;
	char	**lines;
	char	*str_file;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)

	int nums[len];

	i = 0;
	while (i < len)
	{
		lines[i] += fetch_int(lines[i], &nums[i]);
		i++;
	}

	psort(nums, len, sizeof(int), int_cmp_asc);

	int		j;
	long long *amount;

	amount = calloc(len, sizeof(*amount));

	i = len - 2;
	amount[len - 1] = 1;

	while (i >= 0)
	{
		long long sum = 0;
		j = i;
		while (j < len)
		{
			if (bound(nums[i], nums[j], nums[i] + 3))
				sum += amount[j];
			j++;
		}

		amount[i] = sum;
		i--;
	}
	answer(lld, amount[0] + amount[1] + amount[2]);
	return (0);
}
