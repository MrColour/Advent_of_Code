/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_08_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:02:30 by home              #+#    #+#             */
/*   Updated: 2020/09/28 20:01:08 by home             ###   ########.fr       */
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
		if (str[i] == '"')
			quotes++;
		if (str[i] == '\\')
			backslash++;
		i++;
	}
	*code_chars = i + 2 + quotes + backslash;
	*str_chars = i;
}

int		main(void)
{
	char	*str_file;
	int		code_chars;
	int		str_chars;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		process_string(&code_chars, &str_chars, str_file);
		printf("String: %2d, %2d [%s]\n", code_chars, str_chars, str_file);
		result += (code_chars - str_chars);
		str_file = strtok(NULL, "\n");
	}
	printf("Result: %d\n", result);
	return (0);
}