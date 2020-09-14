/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_17_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:00:54 by home              #+#    #+#             */
/*   Updated: 2020/09/13 21:36:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		exact_fill(int remaining, int at, int *cont_list, int list_size)
{
	int	result;

	if (remaining == 0)
		return (1);

	result = 0;
	while (at < list_size)
	{
		if (remaining - cont_list[at] >= 0)
			result += exact_fill(remaining - cont_list[at], at + 1, cont_list, list_size);
		at++;
	}
	return (result);
}

int		main(void)
{
	int		i;
	int		size;
	char	*str_file;
	char	*s_tok;
	int		*cont_sizes;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file);

	cont_sizes = calloc(size, sizeof(*cont_sizes));

	i = 0;
	s_tok = str_file;
	while (s_tok[0] != '\0')
	{
		cont_sizes[i] = atoi(s_tok);

		i++;
		s_tok = strchr(s_tok, '\n');
		s_tok++;
	}

	qsort(cont_sizes, size, sizeof(*cont_sizes), int_cmp_asc);

	int		result;

	result = exact_fill(150, 0, cont_sizes, size);
	printf("RESULT: %d\n", result);

	return (0);
}