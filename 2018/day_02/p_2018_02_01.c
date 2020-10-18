/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:04:51 by home              #+#    #+#             */
/*   Updated: 2020/10/17 18:15:38 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	process_line(char *line, int *twos, int *threes)
{
	bool	two;
	bool	three;
	char	hash[256] = { 0 };

	FOR_EACH(line[_i] != '\0',
		hash[line[_i]]++;
	)

	two = false;
	three = false;
	FOR_EACH(_i < 256,
		if (hash[_i] == 2)
			two = true;
		if (hash[_i] == 3)
			three = true;
	)
	if (two == true)
		(*twos)++;
	if (three == true)
		(*threes)++;
}

int		main(void)
{
	char	*str_file;
	int		twos;
	int		threes;

	str_file = extract_file("input.txt");

	twos = 0;
	threes = 0;
	FOR_EACH_STRTOK(str_file, "\n",
		process_line(_tok, &twos, &threes)
	)
	answer(d, twos * threes);
	return (0);
}
