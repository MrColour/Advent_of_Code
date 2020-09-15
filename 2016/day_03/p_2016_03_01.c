/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_03_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:41:41 by home              #+#    #+#             */
/*   Updated: 2020/09/14 22:49:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		process_line(char *str)
{
	int		checksum;
	int		a;
	int		b;
	int		c;

	checksum = 0;

	str += fetch_int(str, &a);
	str += fetch_int(str, &b);
	str += fetch_int(str, &c);

	if (a + b > c)
		checksum++;
	if (a + c > b)
		checksum++;
	if (b + c > a)
		checksum++;

	if (checksum == 3)
		return (1);
	else
		return (0);
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
