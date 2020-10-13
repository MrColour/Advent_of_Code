/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_05_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/10/12 23:30:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		twice_pair(char *str_file)
{
	int	i;
	int	j;
	bool twice_pair;

	i = 0;
	twice_pair = false;
	while (str_file[i] != '\0' && twice_pair == false)
	{
		j = i + 2;
		while (str_file[j] != '\0' && str_file[j + 1] != '\0')
		{
			if (strncmp(&(str_file[i]), &(str_file[j]), 2) == 0)
				twice_pair = true;
			j++;
		}
		i++;
	}

	if (twice_pair == true)
		return (1);
	else
		return (0);
}

int	repeat_with_between(char *str_file)
{
	int		i;
	bool	result;

	i = 0;
	result = false;
	while (str_file[i + 2] != '\0' && result == false)
	{
		if (str_file[i] == str_file[i + 2])
			result = true;
		i++;
	}

	if (result == true)
		return (1);
	else
		return (0);
}

int main(void)
{
	int		checksum;
	int		nice_strings;
	char	*str_file;

	nice_strings = 0;
	str_file = extract_file("input.txt");

	FOR_EACH_STRTOK(str_file, "\n",
		checksum = 0;
		checksum += twice_pair(_tok);
		checksum += repeat_with_between(_tok);

		if (checksum >= 2)
		{
			nice_strings++;
			// printf("String: %.16s\n", _tok);
		}
	)

	answer(d, nice_strings);
	return (0);
}