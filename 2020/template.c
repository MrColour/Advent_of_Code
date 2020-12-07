/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/06 20:51:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

int		main(void)
{
	int		i;
	int		j;
	int		len;
	char	**lines;
	char	*str_file;
	// char	**map;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)
	// ALLOC_2D(map, SIZE * 2, SIZE * 2, calloc_wrapper, NULL)

	long long	count;
	long long	num;

	i = 0;
	j = 0;
	count = 0;
	while (i < len)
	{
		printf("%s\n", lines[i]);

		// lines[i] += fetch_int(lines[i], &num);

		// printf("%lld\n", num);


		i++;
	}

	printf("%lld\n", count);
	return (0);
}
