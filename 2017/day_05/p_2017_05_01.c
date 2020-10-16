/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 01:43:20 by home              #+#    #+#             */
/*   Updated: 2020/10/16 06:23:14 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	int		*jumps;
	int		len;

	str_file = extract_file("input.txt");
	len = count_occur("\n", str_file);
	jumps = calloc(len, sizeof(*jumps));

	FOR_EACH_STRTOK(str_file, "\n",
		fetch_int(_tok, &jumps[_i]);
	)

	int		steps;
	int		ptr;
	int		jump;

	ptr = 0;
	steps = 0;
	while (bound(0, ptr, len - 1) == true)
	{
		jump = jumps[ptr];

		jumps[ptr]++;
		steps++;
		ptr += jump;
	}

	answer(d, steps);
	return (0);
}