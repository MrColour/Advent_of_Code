/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/04 21:49:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

int		seat_no(char *str)
{
	int bottom = 0;
	int top = 127;
	int mid;

	int i = 0;
	while (i < 7)
	{
		mid = (top - bottom) / 2;

		if (str[i] == 'F')
			top -= mid + 1;
		if (str[i] == 'B')
			bottom += mid + 1;

		// printf("%d %d\n", bottom, top);
		i++;
	}

	return (top);
}

int		seat_col(char *str)
{
	int bottom = 0;
	int top = 7;
	int mid;

	int i = 7;
	while (i < 10)
	{
		mid = (top - bottom) / 2;

		if (str[i] == 'L')
			top -= mid + 1;
		if (str[i] == 'R')
			bottom += mid + 1;

		// printf("%d %d\n", bottom, top);
		i++;
	}

	return (top);
}

int		main(void)
{
	int		i;
	int		len;
	char	**lines;
	char	*str_file;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)

	long long	num;
	long long	num1;
	long long	max;

	i = 0;
	max = 0;
	while (i < len - 1)
	{
		// printf("%s\n", lines[i]);

		num = seat_no(lines[i]);
		num1 = seat_col(lines[i]);

		// printf("%lld\n", num1);

		max = MAX(max, num * 8  + num1);

		i++;
	}

	answer(lld, max);
	return (0);
}
