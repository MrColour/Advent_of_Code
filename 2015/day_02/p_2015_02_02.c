/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:52:51 by home              #+#    #+#             */
/*   Updated: 2020/09/01 01:41:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

int		min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	main(void)
{
	int		l, w, h;
	int		total_ribbon;
	char	*str_file;

	total_ribbon = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "x\n");
	while (str_file != NULL)
	{
		l = atoi(str_file);
		str_file = strtok(NULL, "x\n");
		w = atoi(str_file);
		str_file = strtok(NULL, "x\n");
		h = atoi(str_file);
		str_file = strtok(NULL, "x\n");

		// printf("%d, %d, %d\n", l, w, h);

		total_ribbon += (l * w * h);
		total_ribbon += (min(min((l + w), (w + h)), (h + l))) * 2;
	}

	printf("Result: %d\n", total_ribbon);
	return (0);
}
