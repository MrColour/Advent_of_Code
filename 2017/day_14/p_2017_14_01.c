/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_14_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:27:59 by home              #+#    #+#             */
/*   Updated: 2020/10/03 20:30:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

char	*knot_hash(char *str);

int		ctob(char *str, int size)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] >> (7 - j)) & 1)
				result++;
			j++;
		}
		i += 4;
	}
	return (result);
}

int		main(void)
{
	int		i;
	int		result;
	char	*salt;
	char	*input;
	char	*output;

	salt = extract_file("input.txt");
	strchr(salt, '\n')[0] = '\0';

	i = 0;
	result = 0;
	while (i < 128)
	{
		asprintf(&input, "%s-%d", salt, i);

		output = knot_hash(input);
		result += ctob(output, 64);

		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}

