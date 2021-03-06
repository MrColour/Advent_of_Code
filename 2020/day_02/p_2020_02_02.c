/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:39:00 by home              #+#    #+#             */
/*   Updated: 2020/12/01 21:31:47 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool isValid(int min, int most, char letter, char *str)
{
	// printf("%d and %d, %c\n", min, most, letter);

	min--;
	most--;

	if ((str[min] == letter && str[most] != letter) || (str[min] != letter && str[most] == letter))
		return (true);
	else
		return (false);
}

int		main(void)
{
	int		len;
	char	*str_file;
	char	**lines;
	int		*nums;

	str_file = extract_file("input.txt");
	len = count_occur("\n", str_file);
	NEWLINE_SPLIT(lines, str_file, len)
	nums = calloc(len * 2 + 1, sizeof(*nums));

	int i;
	int min;
	int most;
	int count;
	char *letter;


	i = 0;
	count = 0;
	while (i < len)
	{
		// printf("%s\n", lines[i]);
		letter = &strchr(lines[i], ' ')[1];
		lines[i] += fetch_int(lines[i], &min);
		lines[i] += fetch_int(lines[i], &most);

		// printf("%d, %d %c, %s\n", min, most, *letter, &letter[3]);
		if (isValid(min, most, *letter, &letter[3]))
			count++;
		i++;
	}

	answer(d, count);
	return (0);
}
