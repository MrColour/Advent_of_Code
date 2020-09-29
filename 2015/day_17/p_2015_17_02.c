/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_17_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:00:54 by home              #+#    #+#             */
/*   Updated: 2020/09/28 21:19:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	exact_fill(int remaining, int at, int *cont_list, int list_size, int *result, int *min, int cont_amount)
{
	if (remaining == 0)
	{
		if (cont_amount == *min)
			(*result)++;
		if (cont_amount < *min)
		{
			*min = cont_amount;
			*result = 1;
		}
	}

	while (at < list_size)
	{
		if (remaining - cont_list[at] >= 0)
			exact_fill(remaining - cont_list[at], at + 1, cont_list, list_size, result, min, cont_amount + 1);
		at++;
	}
}

int		main(void)
{
	int		i;
	int		size;
	char	*str_file;
	char	*s_tok;
	int		*cont_sizes;

	str_file = extract_file("input.txt");

	i = 0;
	s_tok = str_file;
	size = count_occur("\n", str_file);
	cont_sizes = calloc(size, sizeof(*cont_sizes));
	while (s_tok[0] != '\0')
	{
		cont_sizes[i] = atoi(s_tok);

		i++;
		s_tok = strchr(s_tok, '\n');
		s_tok++;
	}

	qsort(cont_sizes, i, sizeof(*cont_sizes), int_cmp_asc);

	int		result;
	int		min;

	min = size;
	exact_fill(150, 0, cont_sizes, size, &result, &min, 0);
	printf("RESULT: %d\n", result);

	return (0);
}