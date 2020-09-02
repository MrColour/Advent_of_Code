/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_01_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:44:17 by home              #+#    #+#             */
/*   Updated: 2020/08/31 23:55:03 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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

int		main(void)
{
	size_t	i;
	int		level;
	char	*file;

	i = 0;
	level = 0;
	file = extract_file("input.txt");
	while (file[i] != '\0' && level >= 0)
	{
		if (file[i] == '(')
			level++;
		else
			level--;
		i++;
	}
	printf("Result: %zu\n", i);
	return (0);
}
