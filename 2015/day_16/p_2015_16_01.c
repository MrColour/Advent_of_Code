/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_16_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 23:03:23 by home              #+#    #+#             */
/*   Updated: 2020/09/28 21:11:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		i;
	int		j;
	bool	match;
	char	*ptr;
	char	*s_tok;
	char	*str_file;
	char	*(good_aunt_sue[11]);

	good_aunt_sue[0] = " children: 3";
	good_aunt_sue[1] = " cats: 7";
	good_aunt_sue[2] = " samoyeds: 2";
	good_aunt_sue[3] = " pomeranians: 3";
	good_aunt_sue[4] = " akitas: 0";
	good_aunt_sue[5] = " vizslas: 0";
	good_aunt_sue[6] = " goldfish: 5";
	good_aunt_sue[7] = " trees: 3";
	good_aunt_sue[8] = " cars: 2";
	good_aunt_sue[9] = " perfumes: 1";
	good_aunt_sue[10] = NULL;

	i = 0;
	match = false;
	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL && match == false)
	{
		match = true;
		ptr = strchr(s_tok, ':');
		while (ptr != NULL && match == true)
		{
			ptr++;

			j = 0;
			while (good_aunt_sue[j] != NULL)
			{
				if (strncmp(ptr, good_aunt_sue[j], strlen(good_aunt_sue[j])) == 0)
					break ;
				j++;
			}

			if (good_aunt_sue[j] == NULL)
				match = false;

			ptr = strchr(ptr, ',');
		}

		s_tok = strtok(NULL, "\n");
		i++;
	}
	printf("RESULT: %d\n", i);
	return (0);
}
