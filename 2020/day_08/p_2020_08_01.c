/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/07 21:29:43 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

int		main(void)
{
	int		i;
	int		jump;
	int		len;
	char	**lines;
	char	*str_file;
	int		*done;
	// char	**map;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)
	// ALLOC_2D(map, SIZE * 2, SIZE * 2, calloc_wrapper, NULL)
	done = calloc(len, sizeof(int));

	long long	count;
	long long	num;
	long long	accum = 0;

	i = 0;
	jump = 0;
	count = 0;
	int add;
	while (i < len)
	{
		printf("%s\n", lines[i]);

		// lines[i] += fetch_int(lines[i], &num);

		// printf("%lld\n", num);

		jump = 0;

		if (done[i] == 1)
			break ;

		if (strstr(lines[i], "acc") != NULL)
		{
			fetch_int(lines[i], &add);
			if (lines[i][5] == '-')
				accum -= add;
			else
				accum += add;
			jump = 1;
		}
		else if (strstr(lines[i], "jmp") != NULL)
		{
			fetch_int(lines[i], &add);
			printf("%d\n", add);
			if (lines[i][5] == '-')
				jump += (add);
			else
				jump += (add);
		}
		else
			jump = 1;

		done[i] = 1;

		i += jump;

	}

	printf("%lld\n", accum);
	return (0);
}
