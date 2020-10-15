/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_07_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:54:34 by home              #+#    #+#             */
/*   Updated: 2020/10/14 22:15:55 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		is_SSL(char *line)
{
	int		i;
	bool	hash_aba[256 * 256] = { 0 };
	bool	hash_bab[256 * 256] = { 0 };

	bool	in_supernet;

	i = 0;
	in_supernet = true;
	while (line[i] != '\0')
	{
		if (line[i] == '[')
			in_supernet = false;
		if (line[i] == ']')
			in_supernet = true;

		if (line[i] == line[i + 2])
		{
			if (in_supernet)
				hash_aba[line[i] * 255 + line[i + 1]] = 1;
			else
				hash_bab[line[i + 1] * 255 + line[i]] = 1; // Data must be hashed in reversed for the compare below.
		}
		i++;
	}

	i = 0;
	while (i < 256 * 256)
	{
		if (hash_aba[i] == 1 && hash_bab[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int		main(void)
{
	int		result;
	char	*str_file;

	str_file = extract_file("input.txt");

	result = 0;
	FOR_EACH_STRTOK(str_file, "\n",
		result += is_SSL(_tok);
	)
	answer(d, result);
	return (0);
}
