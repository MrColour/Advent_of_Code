/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_09_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 01:20:31 by home              #+#    #+#             */
/*   Updated: 2020/10/02 01:38:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	collect_garbage(char *garb, int *i, int *result)
{
	(*i)++;
	while (garb[*i] != '>')
	{
		if (garb[*i] == '!')
		{
			(*i)++;
			(*result)--;
		}
		(*i)++;
		(*result)++;

	}
}

int		main(void)
{
	char	*str_file;
	int		nest_level;
	int		score;
	int		i;
	int		result;

	str_file = extract_file("input.txt");

	i = 0;
	score = 0;
	result = 0;
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
			collect_garbage(str_file, &i, &result);
		i++;
	}

	printf("RESULT: %d\n", result);
	return (0);
}
