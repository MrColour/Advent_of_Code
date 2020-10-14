/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_16_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 23:03:23 by home              #+#    #+#             */
/*   Updated: 2020/10/13 03:43:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		i;
	int		j;
	bool	match;
	int		spec;
	char	*s_tok;
	char	*(good_aunt_sue[11]);

	good_aunt_sue[0] = " children: 3";
	good_aunt_sue[1] = " cats: b";
	good_aunt_sue[2] = " samoyeds: 2";
	good_aunt_sue[3] = " pomeranians: b";
	good_aunt_sue[4] = " akitas: 0";
	good_aunt_sue[5] = " vizslas: 0";
	good_aunt_sue[6] = " goldfish: b";
	good_aunt_sue[7] = " trees: b";
	good_aunt_sue[8] = " cars: 2";
	good_aunt_sue[9] = " perfumes: 1";
	good_aunt_sue[10] = NULL;

	i = 0;
	match = false;
	s_tok = extract_file("input.txt");
	s_tok = strtok(s_tok, "\n");
	while (s_tok != NULL && match == false)
	{
		match = true;
		s_tok = strchr(s_tok, ':');
		while (s_tok != NULL && match == true)
		{
			s_tok++;

			j = 0;
			while (good_aunt_sue[j] != NULL)
			{
				if (strncmp(s_tok, good_aunt_sue[j], strlen(good_aunt_sue[j])) == 0)
					break ;

				spec = atoi(strpbrk(s_tok, "1234567890-"));
				if (strncmp(s_tok, " cats", strlen(" cats")) == 0 && spec > 7)
					break ;
				if (strncmp(s_tok, " trees", strlen(" trees")) == 0 && spec > 3)
					break ;

				if (strncmp(s_tok, " pomeranians", strlen(" pomeranians")) == 0 && spec < 3)
					break ;
				if (strncmp(s_tok, " goldfish", strlen(" goldfish")) == 0 && spec < 5)
					break ;
				j++;
			}

			if (good_aunt_sue[j] == NULL)
				match = false;

			s_tok = strchr(s_tok, ',');
		}

		s_tok = strtok(NULL, "\n");
		i++;
	}
	answer(d, i);
	return (0);
}
