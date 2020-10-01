/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:53:29 by home              #+#    #+#             */
/*   Updated: 2020/09/30 23:04:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		process_line(char *line)
{
	int	min;
	int	max;
	int	new_no;

	max = INT_MIN;
	min = INT_MAX;
	while (line[0] != '\0')
	{
		line += fetch_int(line, &new_no);
		min = MIN(min, new_no);
		max = MAX(max, new_no);
	}
	return (max - min);
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		result += process_line(s_tok);
		s_tok = strtok(NULL, "\n");
	}
	printf("RESULT: %d\n", result);
	return (0);
}
