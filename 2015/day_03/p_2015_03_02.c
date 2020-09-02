/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_03_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:01:35 by home              #+#    #+#             */
/*   Updated: 2020/09/01 03:34:17 by home             ###   ########.fr       */
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
	int		s_x, s_y;
	int		r_x, r_y;
	int		*c_x, *c_y;

	i = 0;

	s_x = 0;
	s_y = 0;
	r_x = 0;
	r_y = 0;

	while (str_file[i] != '\0')
	{
		if (i % 2 == 0)
		{
			c_x = &s_x;
			c_y = &s_y;
		}
		else
		{
			c_x = &r_x;
			c_y = &r_y;
		}

		if (str_file[i] == '^')
			(*c_y)++;
		else if (str_file[i] == 'v')
			(*c_y)--;
		else if (str_file[i] == '<')
			(*c_x)--;
		else
			(*c_x)++;

		dest[i].x = *c_x;
		dest[i].y = *c_y;

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

		// printf("(%d, %d)\n", positions[i].x, positions[i].y);
		i++;
	}

	printf("Result: %d\n", unique);
	return (0);
}
