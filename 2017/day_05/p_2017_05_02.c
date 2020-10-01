/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_05_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 01:43:20 by home              #+#    #+#             */
/*   Updated: 2020/10/01 02:16:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	*newline_atoi_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{
	char	*s_tok; int		*num;

	num = malloc(sizeof(num));
	s_tok = *(char **)(alloc_info->iter_addr);
	*num = atoi(s_tok);

	*alloc_info->index += *num;
	*(alloc_info->iter_addr) = strtok(NULL, alloc_info->e_delim);
	return (num);
}

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

		if (jump >= 3)
			jumps[ptr]--;
		else
			jumps[ptr]++;
		steps++;
		ptr += jump;
	}

	printf("RESULT: %d\n", steps);
	return (0);
}
