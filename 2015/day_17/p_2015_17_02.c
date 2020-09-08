/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_17_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:00:54 by home              #+#    #+#             */
/*   Updated: 2020/09/07 23:48:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdbool.h>

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

int		int_cmp(const void *ptr_a, const void *ptr_b)
{
	int		a;
	int		b;

	a = *(int *)ptr_a;
	b = *(int *)ptr_b;

	if (a > b)
		return (-1);
	else
		return (1);
}

void	exact_fill(int remaining, int at, int *cont_list, int list_size, int *result, int *min, int cont_amount)
{
	if (remaining == 0)
	{
		if (cont_amount == *min)
			(*result)++;
		if (cont_amount < *min)
		{
			*min = cont_amount;
			*result = 1;
		}
	}

	while (at < list_size)
	{
		if (remaining - cont_list[at] >= 0)
			exact_fill(remaining - cont_list[at], at + 1, cont_list, list_size, result, min, cont_amount + 1);
		at++;
	}
}

int		main(void)
{
	int		i;
	int		size;
	char	*str_file;
	char	*s_tok;
	int		*cont_sizes;

	size = 0;
	str_file = extract_file("input.txt");
	s_tok = strchr(str_file, '\n');
	while (s_tok != NULL)
	{
		size++;
		s_tok++;
		s_tok = strchr(s_tok, '\n');
	}
	cont_sizes = calloc(size, sizeof(*cont_sizes));


	i = 0;
	s_tok = str_file;
	while (s_tok[0] != '\0')
	{
		cont_sizes[i] = atoi(s_tok);

		i++;
		s_tok = strchr(s_tok, '\n');
		s_tok++;
	}

	qsort(cont_sizes, i, sizeof(*cont_sizes), int_cmp);

	int		result;
	int		min;

	min = size;
	exact_fill(150, 0, cont_sizes, size, &result, &min, 0);
	printf("RESULT: %d\n", result);

	return (0);
}