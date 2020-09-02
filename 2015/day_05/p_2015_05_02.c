/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_05_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:37:35 by home              #+#    #+#             */
/*   Updated: 2020/09/01 22:42:21 by home             ###   ########.fr       */
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

int		twice_pair(char *str_file)
{
	int	i;
	int	j;
	bool twice_pair;

	i = 0;
	twice_pair = false;
	while (str_file[i] != '\0' && str_file[i] != '\n' && twice_pair == false)
	{
		j = i + 2;
		while (str_file[j] != '\0' && str_file[j] != '\n' &&
				str_file[j + 1] != '\0' && str_file[j + 1] != '\n')
		{
			if (strncmp(&(str_file[i]), &(str_file[j]), 2) == 0)
			{
				printf("%.2s and %.2s\n", &(str_file[i]), &(str_file[j]));
				twice_pair = true;
			}
			j++;
		}
		i++;
	}

	if (twice_pair == true)
		return (1);
	else
		return (0);
}

int	repeat_with_between(char *str_file)
{
	int	i;
	bool	result;

	i = 0;
	result = false;
	while (str_file[i + 2] != '\0' && str_file[i + 2] != '\n' && result == false)
	{
		if (str_file[i] == str_file[i + 2])
			result = true;
		i++;
	}

	if (result == true)
		return (1);
	else
		return (0);
}

int main(void)
{
	int		checksum;
	int		nice_strings;
	char	*str_file;

	nice_strings = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");

	while (str_file != NULL)
	{
		checksum = 0;
		checksum += twice_pair(str_file);
		checksum += repeat_with_between(str_file);

		if (checksum >= 2)
		{
			nice_strings++;
			printf("String: %.16s\n", str_file);
		}
		str_file = strtok(NULL, "\n");
	}

	printf("Result: %d\n", nice_strings);
	return (0);
}