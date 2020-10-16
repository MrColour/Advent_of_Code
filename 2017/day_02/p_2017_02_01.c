/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:53:29 by home              #+#    #+#             */
/*   Updated: 2020/10/16 05:54:47 by home             ###   ########.fr       */
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
	char	*s_tok;
	int		result;

	result = 0;
	s_tok = extract_file("input.txt");
	FOR_EACH_STRTOK(s_tok, "\n",
		result += process_line(_tok);
	)
	answer(d, result);
	return (0);
}
