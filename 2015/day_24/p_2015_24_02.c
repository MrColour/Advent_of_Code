/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_24_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 05:19:02 by home              #+#    #+#             */
/*   Updated: 2020/09/28 22:46:23 by home             ###   ########.fr       */
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

int		main(void)
{
	int		i;
	int		total_weight;
	int		package_amount;
	int		*packages;
	char	*str_file;
	char	*s_tok;

	str_file = extract_file("input.txt");

	package_amount = count_occur("\n", str_file);

	i = 0;
	total_weight = 0;
	s_tok = str_file;
	strtok(s_tok, "\n");
	packages = calloc(package_amount, sizeof(*packages));
	while (i < package_amount)
	{
		packages[i] = atoi(s_tok);
		total_weight += packages[i];
		s_tok = strtok(NULL, "\n");
		i++;
	}

	qsort(packages, package_amount, sizeof(*packages), int_cmp_des);

	long	QE;
	int		min;

	min = package_amount;
	QE = INT64_MAX;

	depth_search(&min, &QE, packages, package_amount, 0, total_weight / 4, 1);

	printf("%ld, and %d\n", QE, min);
	return (0);
}