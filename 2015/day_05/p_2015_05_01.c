/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/10/12 23:26:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	at_least_three_vowels(char *str_file)
{
	int		i;
	int		vowel_count;
	char	letters[256] =
	{
		['e'] = 1,
		['i'] = 1,
		['a'] = 1,
		['o'] = 1,
		['u'] = 1,
	};

	i = 0;
	vowel_count = 0;
	while (str_file[i] != '\0' && vowel_count < 3)
	{
		if (letters[(int)str_file[i]] == 1)
			vowel_count++;
		i++;
	}

	if (vowel_count >= 3)
		return (1);
	else
		return (0);
}

int	twice_in_a_row(char *str_file)
{
	int		i;
	bool	twice;

	i = 0;
	twice = false;
	while (str_file[i + 1] != '\0' && twice == false)
	{
		if (str_file[i] == str_file[i + 1])
			twice = true;
		i++;
	}

	if (twice == true)
		return (1);
	else
		return (0);
}

int	without_strings(char *str_file, int blacklist_count, char **blacklist)
{
	int	i;
	int	j;
	int	collisions;

	i = 0;
	collisions = 0;
	while (str_file[i] != '\0' && collisions == 0)
	{
		j = 0;
		while (j < blacklist_count)
		{
			if (strncmp(&(str_file[i]), blacklist[j], 2) == 0)
				collisions = 1;
			j++;
		}
		i++;
	}

	if (collisions == 0)
		return (1);
	else
		return (0);
}

int main(void)
{
	int		checksum;
	int		nice_strings;
	char	*str_file;
	char	*(blacklist[4]);

	nice_strings = 0;
	str_file = extract_file("input.txt");

	blacklist[0] = "ab";
	blacklist[1] = "cd";
	blacklist[2] = "pq";
	blacklist[3] = "xy";

	FOR_EACH_STRTOK(str_file, "\n",
		checksum = 0;
		checksum += at_least_three_vowels(_tok);
		checksum += twice_in_a_row(_tok);
		checksum += without_strings(_tok, 4, blacklist);

		if (checksum >= 3)
			nice_strings++;
	)

	answer(d, nice_strings);
	return (0);
}