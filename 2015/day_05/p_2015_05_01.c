/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/09/28 17:19:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	at_least_three_vowels(char *str_file)
{
	int		i;
	int		vowel_count;
	char	letters[256] = { 0 };

	letters['a'] = 1;
	letters['e'] = 1;
	letters['i'] = 1;
	letters['o'] = 1;
	letters['u'] = 1;

	i = 0;
	vowel_count = 0;
	while (str_file[i] != '\0' && str_file[i] != '\n' && vowel_count < 3)
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
	while (str_file[i + 1] != '\0' && str_file[i + 1] != '\n' && twice == false)
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
	while (str_file[i] != '\0' && str_file[i] != '\n' && collisions == 0)
	{
		j = 0;
		while (j < blacklist_count)
		{
			if (strncmp(&(str_file[i]), blacklist[j], 2) == 0)
				collisions++;
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
	str_file = strtok(str_file, "\n");

	blacklist[0] = "ab";
	blacklist[1] = "cd";
	blacklist[2] = "pq";
	blacklist[3] = "xy";

	while (str_file != NULL)
	{
		checksum = 0;
		checksum += at_least_three_vowels(str_file);
		checksum += twice_in_a_row(str_file);
		checksum += without_strings(str_file, 4, blacklist);

		if (checksum >= 3)
			nice_strings++;
		str_file = strtok(NULL, "\n");
	}

	printf("Result: %d\n", nice_strings);
	return (0);
}