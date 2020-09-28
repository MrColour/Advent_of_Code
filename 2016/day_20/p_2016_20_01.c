/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_20_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 23:02:31 by home              #+#    #+#             */
/*   Updated: 2020/09/28 03:47:35 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		ip_cmp(const void *a, const void *b)
{
	long	a_n;
	long	b_n;

	a_n = atol((*(char **)a));
	b_n = atol((*(char **)b));

	if (a_n > b_n)
		return (1);
	else
		return (-1);
}

int		main(void)
{
	int		i;
	int		newlines;
	char	*str_file;
	char	**split;

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(split, str_file, newlines)

	psort(split, newlines, sizeof(*split), ip_cmp);

	long	result;
	long	temp;

	i = 0;
	result = 0;
	while (i < newlines)
	{
		if (result < atol(split[i]))
			break ;

		temp = atol(&(strchr(split[i], '-')[1]));

		if (result < temp)
			result = temp + 1;

		i++;
	}
	printf("RESULT: %ld\n", result);
	return (0);
}
