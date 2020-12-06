/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_06_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/05 21:40:12 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		count_no(int people, char *hash)
{
	int i = 0;
	int res = 0;;

	while (i < 256)
	{
		if (hash[i] == people - 1)
			res++;
		i++;
	}
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

	char	hash[256] = { 0 };

	i = 0;
	int add = 0;
	count = 0;
	int people = 0;
	while (i < len - 1)
	{
		// printf("%s\n", lines[i]);

		to_hash(hash, lines[i]);
		people++;

		if (lines[i][0] == '\0')
		{
			add = count_no(people, hash);
			count += add;

			people = 0;
			bzero(hash, sizeof(hash));
		}

		i++;
	}
	answer(lld, count);
	return (0);
}
