/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_09_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 01:20:31 by home              #+#    #+#             */
/*   Updated: 2020/10/02 01:33:18 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	collect_garbage(char *garb, int *i)
{
	while (garb[*i] != '>')
	{
		if (garb[*i] == '!')
			(*i)++;
		(*i)++;
	}
}

int		main(void)
{
	char	*str_file;
	int		nest_level;
	int		score;
	int		i;

	str_file = extract_file("input.txt");

	i = 0;
	score = 0;
	nest_level = 0;
	while (str_file[i] != '\0')
	{
		if (str_file[i] == '{')
			nest_level++;
		if (str_file[i] == '}')
		{
			score += nest_level;
			nest_level--;
		}
		if (str_file[i] == '<')
			collect_garbage(str_file, &i);
		i++;
	}

	printf("RESULT: %d\n", score);
	return (0);
}
