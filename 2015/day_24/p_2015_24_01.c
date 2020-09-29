/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_24_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 05:19:02 by home              #+#    #+#             */
/*   Updated: 2020/09/28 23:30:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	depth_search(int *min, long *qe, int *packages, int p_size, int added, int remaining, long curr_qe)
{
	int		i;

	if (added > *min || curr_qe > *qe)
		return ;

	if (remaining == 0)
	{
		if (*qe > curr_qe)
		{
			*min = added;
			*qe = curr_qe;
		}
		return ;
	}

	i = 0;
	while (i < p_size)
	{
		if (remaining - packages[i] >= 0)
			depth_search(min, qe, &packages[i + 1], p_size - i - 1, added + 1, remaining - packages[i], curr_qe * packages[i]);
		i++;
	}
}

void	*newline_atoi_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{
	char	*s_tok;
	int		*num;

	num = malloc(sizeof(num));
	s_tok = *(char **)(alloc_info->iter_addr);
	*num = atoi(s_tok);

	*alloc_info->index += *num;
	*(alloc_info->iter_addr) = strtok(NULL, alloc_info->e_delim);
	return (num);
}

int		main(void)
{
	int		i;
	int		total_weight;
	int		package_amount;
	int		*packages;
	char	*str_file;

	str_file = extract_file("input.txt");

	package_amount = count_occur("\n", str_file);

	total_weight = 0;

	strtok(str_file, "\n");
	g_ameta.e_delim = "\n";
	g_ameta.iter_addr = (void **)&str_file;
	g_ameta.index = &total_weight;
	ALLOC_1D(packages, package_amount, newline_atoi_alloc, &g_ameta)

	qsort(packages, package_amount, sizeof(*packages), int_cmp_des);

	long	QE;
	int		min;

	min = package_amount;
	QE = INT64_MAX;

	depth_search(&min, &QE, packages, package_amount, 0, total_weight / 3, 1);

	printf("%ld, and %d\n", QE, min);
	return (0);
}