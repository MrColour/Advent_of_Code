/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_03_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:01:35 by home              #+#    #+#             */
/*   Updated: 2020/09/01 03:34:49 by home             ###   ########.fr       */
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

typedef	struct	pos2i
{
	int		x;
	int		y;
}				pos2i;

void	process_str_file(pos2i *dest, char *str_file)
{
	size_t i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;

	while (str_file[i] != '\0')
	{
		if (str_file[i] == '^')
			y++;
		else if (str_file[i] == 'v')
			y--;
		else if (str_file[i] == '<')
			x--;
		else
			x++;

		dest[i].x = x;
		dest[i].y = y;
		i++;
	}
	dest[i].x = 0;
	dest[i].y = 0;
}

int		quad_cmp(const void *ptr_a, const void *ptr_b)
{
	const pos2i *a;
	const pos2i *b;

	a = ptr_a;
	b = ptr_b;
	if (a->x < b->x)
		return (1);
	else if (a->x == b->x && a->y > b->y)
		return (1);
	else
		return (-1);
}

int		main(void)
{
	char	*str_file;
	int		i;
	int		visits;
	int		unique;
	pos2i	*positions;

	str_file = extract_file("input.txt");
	visits = strlen(str_file) + 1;
	positions = calloc(visits, sizeof(*positions));

	process_str_file(positions, str_file);
	qsort(positions, visits, sizeof(*positions), quad_cmp);

	i = 1;
	unique = 1;
	while (i < visits)
	{
		if (positions[i - 1].x != positions[i].x || positions[i - 1].y != positions[i].y)
			unique++;
		// else
		// 	printf("Not unique\n");

		printf("(%d, %d)\n", positions[i].x, positions[i].y);
		i++;
	}

	printf("Result: %d\n", unique);
	return (0);
}
