/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_22_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:20:10 by home              #+#    #+#             */
/*   Updated: 2020/09/23 16:03:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		avail_sort(const void *a, const void *b)
{
	char	*str_a;
	char	*str_b;
	int		avail_a;
	int		avail_b;

	str_a = *(char **)a;
	str_b = *(char **)b;
	str_a = strstr(str_a, "T ");
	str_b = strstr(str_b, "T ");

	str_a += fetch_int(str_a, &avail_a);
	fetch_int(str_a, &avail_a);
	str_b += fetch_int(str_b, &avail_b);
	fetch_int(str_b, &avail_b);

	if (avail_a > avail_b)
		return (1);
	else
		return (-1);
}

int		main(void)
{
	int		i;
	int		newlines;
	char	*str_file;
	char	*s_tok;
	char	**disk;

	str_file = extract_file("input.txt");
	newlines = count_occur("\n", str_file);

	i = 0;
	s_tok = strtok(str_file, "\n");
	disk = calloc(newlines, sizeof(*disk));
	while (i < newlines)
	{
		disk[i] = s_tok;
		s_tok = strtok(NULL, "\n");
		i++;
	}
	disk = &(disk[2]);
	newlines -= 2;

	psort(disk, newlines, sizeof(*disk), avail_sort);

	int		j;
	int		used;
	int		avail;
	int		pairs;

	i = 0;
	pairs = 0;
	while (i < newlines)
	{
		j = i + 1;
		fetch_int(strstr(disk[i], "T "), &used);
		while (j < newlines)
		{
			fetch_int(strstr(strstr(disk[j], "T ") + 1, "T "), &avail);
			if (used <= avail)
			{
				printf("DISK: %d %d, %s and %s\n", used, avail, disk[i], disk[j]);
				break ;
			}
			j++;
		};

		if (used != 0)
			pairs += newlines - j;

		i++;
	}
	printf("RESULT: %d\n", pairs);
	return (0);
}
