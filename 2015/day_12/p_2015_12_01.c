/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_12_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:15:06 by home              #+#    #+#             */
/*   Updated: 2020/09/04 23:21:05 by home             ###   ########.fr       */
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

int	main(void)
{
	int		result;
	char	*str_file;
	char	num_set[] = "1234567890-";

	result = 0;
	str_file = extract_file("input.txt");
	while (str_file != NULL && str_file[0] != '\0')
	{
		result += atoi(str_file);
		str_file += strspn(str_file, num_set);
		str_file = strpbrk(str_file, num_set);
		printf("STR: [ %.5s ]\n", str_file);
	}
	printf("Result: %d\n", result);
	return (0);
}