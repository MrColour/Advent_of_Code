/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_07_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 02:46:26 by home              #+#    #+#             */
/*   Updated: 2020/10/18 03:23:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_instr
{
	bool		depend[256];
	bool		finished;
}				t_instr;

#define LIM ('Z' + 1)

bool	unlocked(t_instr *steps, char c)
{
	int		i;
	bool	result;

	i = 'A';
	result = true;
	while (result == true && i < LIM)
	{
		if (steps[c].depend[i] == true && steps[i].finished == false)
			result = false;
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	char	*letter;
	char	*depends;
	t_instr	steps[256] = { 0 };

	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, "\n",
		depends = strchr(_tok, 'p') + 2;
		letter = strchr(_tok + 4, 'p') + 2;

		steps[*letter].depend[*depends] = true;
	)

	bool	found;
	int		i;

	found = true;
	while (found)
	{
		i = 'A';
		found = false;
		while (i < LIM)
		{
			if (unlocked(steps, i) == true && steps[i].finished == false)
			{
				printf("%c", i);
				steps[i].finished = true;
				found = true;
				break;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
