/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:02:30 by home              #+#    #+#             */
/*   Updated: 2020/10/12 23:40:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	process_string(int *code_chars, int *str_chars, char *str)
{
	int	i;
	int	hex;
	int	quotes;
	int	backslash;

	i = 0;
	hex = 0;
	quotes = 0;
	backslash = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\\')
		{
			if (str[i + 1] == 'x')
				hex++;
			if (str[i + 1] == '"')
				quotes++;
			if (str[i + 1] == '\\')
			{
				backslash++;
				i++;
			}
		}
		i++;
	}

	*code_chars = i;
	*str_chars = i - ((hex * 3) + quotes + backslash + 2);
}

int		main(void)
{
	char	*str_file;
	int		code_chars;
	int		str_chars;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, "\n",
		process_string(&code_chars, &str_chars, _tok);
		// printf("String: %2d, %2d [%s]\n", code_chars, str_chars, _tok);
		result += (code_chars - str_chars);
	)
	answer(d, result);
	return (0);
}