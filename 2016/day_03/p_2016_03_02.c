/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:50:28 by home              #+#    #+#             */
/*   Updated: 2020/09/14 23:06:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		triangle(int a, int b, int c)
{
	int		checksum;

	checksum = 0;

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
	char	*s_tok1;
	char	*s_tok2;
	char	*s_tok3;
	int		result;

	int		a1, b1, c1;
	int		a2, b2, c2;
	int		a3, b3, c3;

	result = 0;
	str_file = extract_file("input.txt");
	s_tok1 = strtok(str_file, "\n");
	while (s_tok1 != NULL)
	{
		s_tok1 += fetch_int(s_tok1, &a1);
		s_tok1 += fetch_int(s_tok1, &a2);
		s_tok1 += fetch_int(s_tok1, &a3);

		s_tok2 = strtok(NULL, "\n");

		s_tok2 += fetch_int(s_tok2, &b1);
		s_tok2 += fetch_int(s_tok2, &b2);
		s_tok2 += fetch_int(s_tok2, &b3);

		s_tok3 = strtok(NULL, "\n");

		s_tok3 += fetch_int(s_tok3, &c1);
		s_tok3 += fetch_int(s_tok3, &c2);
		s_tok3 += fetch_int(s_tok3, &c3);

		s_tok1 = strtok(NULL, "\n");

		result += triangle(a1, b1, c1);
		result += triangle(a2, b2, c2);
		result += triangle(a3, b3, c3);
	}
	printf("RESULT: %d\n", result);
	return (0);
}
