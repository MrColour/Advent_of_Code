/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_16_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 23:03:23 by home              #+#    #+#             */
/*   Updated: 2020/10/13 03:38:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		i;
	bool	match;
	char	*s_tok;
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
	match = false; //Search until right aunt is found
	s_tok = extract_file("input.txt");
	s_tok = strtok(s_tok, "\n");
	while (s_tok != NULL && match == false)
	{
		match = true; //Assume this is the right aunt
		s_tok = strchr(s_tok, ':');
		while (s_tok != NULL && match == true)
		{
			s_tok++;

			match = false; //Search until attribute is found
			FOR_EACH(good_aunt_sue[_i] != NULL,
				if (strncmp(s_tok, good_aunt_sue[_i], strlen(good_aunt_sue[_i])) == 0)
				{
					match = true;
					break ;
				}
			)

			s_tok = strchr(s_tok, ',');
		}

		s_tok = strtok(NULL, "\n");
		i++;
	}
	answer(d, i);
	return (0);
}
