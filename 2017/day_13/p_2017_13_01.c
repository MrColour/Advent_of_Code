/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_13_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:51:38 by home              #+#    #+#             */
/*   Updated: 2020/11/25 21:08:19 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	char	*s_tok;

	int		range;
	int		second;
	int		total_severity;

	str_file = extract_file("input.txt");

	second = 0;
	total_severity = 0;
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		s_tok += fetch_int(s_tok, &second);
		s_tok += fetch_int(s_tok, &range);
		if (second % ((range * 2 - 2)) == 0)
		{
		printf("ADD: %d with %d and %d\n", (second * range), second, range);
			total_severity += (second * range);
		}
		s_tok = strtok(NULL, "\n");
	}
	printf("RESULT: %d\n", total_severity);
	return (0);
}