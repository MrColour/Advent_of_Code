/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_04_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 01:06:41 by home              #+#    #+#             */
/*   Updated: 2020/10/16 06:18:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool	isValid(char *passphrase)
{
	char	**words;
	int		len;
	int		i;
	int		j;
	bool	result;

	STR_SPLIT(words, passphrase, NULL, " ", len)
	psort(words, len, sizeof(*words), str_cmp);

	i = 0;
	result = true;
	while (words[i + 1] != NULL && result == true)
	{
		if (strcmp(words[i], words[i + 1]) == 0)
			result = false;
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	int		result;

	str_file = extract_file("input.txt");

	result = 0;
	FOR_EACH_STRTOK(str_file, "\n",
		if (isValid(_tok) == true)
			result++;
	)
	answer(d, result);
	return (0);
}
