/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_09_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:24:35 by home              #+#    #+#             */
/*   Updated: 2020/09/17 21:48:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

long long	decompress(char *str, long long len)
{
	long long	i;
	long long	result;
	int			delim;
	int			times;

	i = 0;
	result = 0;
	while (i < len && str[i] != '\n')
	{
		if (str[i] == '(')
		{
			i += fetch_int(&str[i], &delim);
			i += fetch_int(&str[i], &times);
			i++;

			result += (decompress(&str[i], delim) * times);
			i += delim - 1;
			// printf("RES: %lld %c\n", result, str[i]);
		}
		else
			result++;
		i++;
	}

	return (result);
}

int		main(void)
{
	char		*str_file;
	long long	len;

	str_file = extract_file("input.txt");
	len = decompress(str_file, strlen(str_file) - 1); //For the newline

	printf("RESULT: %lld\n", len);
	return (0);
}
