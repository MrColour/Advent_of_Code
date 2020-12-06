/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_06_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/05 21:40:22 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		hash_str(char *str, char *hash)
{
	to_hash(hash, str);

	int i = 0;
	i = 0;
	int add = 0;
	while (i < 255)
	{
		if (hash[i] >= 1)
			add++;
		i++;
	}
	return (add);
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
	while (i < len - 1)
	{
		// printf("%s\n", lines[i]);

		add = hash_str(lines[i], hash);

		if (lines[i][0] == '\0')
		{
			bzero(hash, sizeof(hash));
			count += add;
		}
		i++;
	}

	answer(lld, count);
	return (0);
}
