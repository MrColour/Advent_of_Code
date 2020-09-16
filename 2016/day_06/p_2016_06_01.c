/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_06_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 01:13:40 by home              #+#    #+#             */
/*   Updated: 2020/09/16 01:26:12 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		occur[8][250] = { 0 };

	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		occur[0][(int)s_tok[0]]++;
		occur[1][(int)s_tok[1]]++;
		occur[2][(int)s_tok[2]]++;
		occur[3][(int)s_tok[3]]++;
		occur[4][(int)s_tok[4]]++;
		occur[5][(int)s_tok[5]]++;
		occur[6][(int)s_tok[6]]++;
		occur[7][(int)s_tok[7]]++;

		s_tok = strtok(NULL, "\n");
	}

	int		i;
	int		j;
	int		most;

	i = 0;
	while (i < 8)
	{
		j = 0;
		most = 0;
		while (j < 250)
		{
			if (occur[i][j] > occur[i][most])
				most = j;
			j++;
		}
		printf("%c", most);
		i++;
	}
	printf("\n");
	return (0);
}
