/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:02:30 by home              #+#    #+#             */
/*   Updated: 2020/09/03 17:38:53 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE (1024)

char	*extract_file(char *file_name)
{
	int		fd;
	int		bytes_read;
	int		size;
	char	*result;

	size = 0;
	result = NULL;
	fd = open(file_name, O_RDONLY);

	bytes_read = 1;
	while (bytes_read != 0)
	{
		result = realloc(result, size + BUFF_SIZE + 1);
		bytes_read = read(fd, &result[size], BUFF_SIZE);
		size += bytes_read;
		result[size] = '\0';
	}
	return (result);
}

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