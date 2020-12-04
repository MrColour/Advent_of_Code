/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_04_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/03 23:24:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		len;
	char	**lines;
	char	*str_file;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)

	long long	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		// printf("%s\n", lines[i]);

		bool byr = false;
		bool iyr = false;
		bool eyr = false;
		bool hgt = false;
		bool hcl = false;
		bool ecl = false;
		bool pid = false;

		while (lines[i][0] != '\0')
		{
			if (strstr(lines[i], "byr") != NULL)
				byr = true;
			if (strstr(lines[i], "iyr") != NULL)
				iyr = true;
			if (strstr(lines[i], "eyr") != NULL)
				eyr = true;
			if (strstr(lines[i], "hgt") != NULL)
				hgt = true;
			if (strstr(lines[i], "hcl") != NULL)
				hcl = true;
			if (strstr(lines[i], "ecl") != NULL)
				ecl = true;
			if (strstr(lines[i], "pid") != NULL)
				pid = true;

			i++;
		}

		if (byr && iyr && eyr && hgt && hcl && ecl && pid)
			count++;

		i++;
	}

	answer(lld, count);
	return (0);
}
