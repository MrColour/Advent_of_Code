/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_11_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:08:21 by home              #+#    #+#             */
/*   Updated: 2020/09/04 17:43:47 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char	*next_inc(char *str)
{
	int	i;

	i = strlen(str) - 1;
	while (i >= 0 && str[i] == 'z')
	{
		str[i] = 'a';
		i--;
	}
	str[i]++;

	return (str);
}

bool	three_letters(char *pass)
{
	int		i;
	bool	result;

	i = 0;
	result = false;
	while (pass[i + 2] != '\0' && result == false)
	{
		if (pass[i] + 1 == pass[i + 1] && pass[i + 1] + 1 == pass[i + 2])
			result = true;
		i++;
	}
	return (result);
}

bool	two_pairs(char *pass)
{
	int		i;
	int		pair;
	char	hash[250];
	bool	result;

	i = 0;
	pair = 0;
	result = false;
	bzero(hash, sizeof(hash));
	while (pass[i + 1] != '\0' && pair < 2)
	{
		if (hash[(int)pass[i]] == 0 && pass[i] == pass[i + 1])
		{
			hash[(int)pass[i]]++;
			pair++;
		}
		i++;
	}
	if (pair >= 2)
		result = true;
	return (result);
}

int		main(void)
{
	int		checksum;
	bool	valid;
	char	*input;

	input = strdup("hepxirrq");

	valid = false;
	while (valid == false)
	{
		input = next_inc(input);
		// printf("STR: [ %s ]\n", input);

		checksum = 0;

		checksum += three_letters(input);
		checksum += (strpbrk(input, "iol") == NULL ? 1 : 0);
		checksum += two_pairs(input);

		if (checksum >= 3)
			valid = true;
	}
	printf("Result: %s\n", input);
	return (0);
}