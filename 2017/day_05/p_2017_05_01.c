/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 01:43:20 by home              #+#    #+#             */
/*   Updated: 2020/10/10 04:03:14 by home             ###   ########.fr       */
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

	len = 0;
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		fetch_int(str_file, &jumps[len]);
		str_file = strtok(NULL, "\n");
		len++;
	}

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

	printf("RESULT: %d\n", steps);
	return (0);
}