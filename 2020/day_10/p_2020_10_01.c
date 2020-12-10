/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_10_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/09 22:08:49 by home             ###   ########.fr       */
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

	long long	count = 0;
	int nums[len];

	i = 0;
	while (i < len)
	{
		fetch_int(lines[i], &nums[i]);
		i++;
	}

	psort(nums, len, sizeof(int), int_cmp_asc);

	int prev = 0;

	i = 0;
	int	one = 0;
	int	three = 0;
	while (i <= len)
	{
		if (nums[i] - prev == 1)
			one++;
		else
			three++;
		prev = nums[i];
		i++;
	}
	printf("%d\n", one * three);
	return (0);
}
