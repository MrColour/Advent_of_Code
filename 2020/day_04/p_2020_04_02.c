/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_04_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/03 23:25:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool check_eye(char *str)
{
	bool res = false;

	if (strnstr(str, "amb", 3) != NULL)
		res = true;
	if (strnstr(str, "blu", 3) != NULL)
		res = true;
	if (strnstr(str, "brn", 3) != NULL)
		res = true;
	if (strnstr(str, "gry", 3) != NULL)
		res = true;
	if (strnstr(str, "grn", 3) != NULL)
		res = true;
	if (strnstr(str, "hzl", 3) != NULL)
		res = true;
	if (strnstr(str, "oth", 3) != NULL)
		res = true;

	return (res);
}

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

		int test;
		char *ptr;

		while (lines[i][0] != '\0')
		{
			if (strstr(lines[i], "byr") != NULL)
			{
				fetch_int(strstr(lines[i], "byr"), &test);
				if (bound(1920, test, 2002))
					byr = true;
			}
			if (strstr(lines[i], "iyr") != NULL)
			{
				fetch_int(strstr(lines[i], "iyr"), &test);
				if (bound(2010, test, 2020))
					iyr = true;
			}
			if (strstr(lines[i], "eyr") != NULL)
			{
				fetch_int(strstr(lines[i], "eyr"), &test);
				if (bound(2020, test, 2030))
					eyr = true;
			}
			if (strstr(lines[i], "hgt") != NULL)
			{
				ptr = strstr(lines[i], "hgt");
				ptr += fetch_int(ptr, &test);
				if (ptr[0] == 'c' && bound(150, test, 193))
					hgt = true;
				else if (ptr[0] == 'i' && bound(59, test, 76))
					hgt = true;
			}
			if (strstr(lines[i], "hcl") != NULL)
			{
				ptr = &strstr(lines[i], "hcl")[4];
				if (ptr[0] == '#' && strspn(&ptr[1], "0123456789abcdef") == 6)
					hcl = true;
			}
			if (strstr(lines[i], "ecl") != NULL)
			{
				if (check_eye(&strstr(lines[i], "ecl")[4]))
					ecl = true;
			}
			if (strstr(lines[i], "pid") != NULL)
			{
				ptr = &strstr(lines[i], "pid")[4];
				if (strspn(ptr, "0123456789") == 9)
					pid = true;
			}

			i++;
		}

		if (byr && iyr && eyr && hgt && hcl && ecl && pid)
			count++;

		i++;
	}

	answer(lld, count);
	return (0);
}
