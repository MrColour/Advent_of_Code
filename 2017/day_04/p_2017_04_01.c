/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_04_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 01:06:41 by home              #+#    #+#             */
/*   Updated: 2020/10/09 18:30:42 by home             ###   ########.fr       */
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

	i = 0;
	result = true;
	while (words[i] != NULL)
	{
		j = i + 1;
		while (words[j] != NULL)
		{
			if (strcmp(words[i], words[j]) == 0)
				result = false;
			j++;
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*s_tok;
	int		result;

	s_tok = extract_file("input.txt");

	result = 0;
	s_tok = strtok(s_tok, "\n");
	while (s_tok != NULL)
	{
		if (isValid(s_tok) == true)
			result++;
		s_tok = strtok(NULL, "\n");
	}
	printf("RESULT: %d\n", result);
	return (0);
}
