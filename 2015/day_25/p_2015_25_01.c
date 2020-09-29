/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_25_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:53:13 by home              #+#    #+#             */
/*   Updated: 2020/09/28 22:34:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	int		t_row, t_col;

	int			row, col;
	int			s_row;
	long long	result;

	str_file = extract_file("input.txt");
	t_row = atoi(&strstr(str_file, "row")[3]);
	t_col = atoi(&strstr(str_file, "column")[6]);

	col = 0;
	s_row = 2;
	row = s_row;
	result = 20151125;
	while (!(col == t_col && row == t_row))
	{

		col = 1;
		row = s_row;
		while (row > 0)
		{
			result *= 252533;
			result %= 33554393;

			if (col == t_col && row == t_row)
				break;

			row--;
			col++;
		}

		s_row++;
	}
	printf("RESULT: %lld\n", result);
	return (0);
}