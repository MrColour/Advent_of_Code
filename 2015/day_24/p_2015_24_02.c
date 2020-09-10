/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_24_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 05:19:02 by home              #+#    #+#             */
/*   Updated: 2020/09/10 07:55:29 by home             ###   ########.fr       */
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

void	depth_search(int *min, long *qe, int *packages, int p_size, int added, int remaining, long curr_qe)
{
	int		i;

	if (added > *min || curr_qe > *qe)
		return ;

	if (remaining == 0)
	{
		if (*qe > curr_qe)
		{
			*min = added;
			*qe = curr_qe;
		}
		return ;
	}

	i = 0;
	while (i < p_size)
	{
		if (remaining - packages[i] >= 0)
			depth_search(min, qe, &packages[i + 1], p_size - i - 1, added + 1, remaining - packages[i], curr_qe * packages[i]);
		i++;
	}
}

int		int_cmp(const void *ptr_a, const void *ptr_b)
{
	int	a;
	int	b;

	a = *(int *)ptr_a;
	b = *(int *)ptr_b;

	if (a > b)
		return (-1);
	else
		return (1);
}

int		main(void)
{
	int		i;
	int		total_weight;
	int		package_amount;
	int		*packages;
	char	*str_file;
	char	*s_tok;

	str_file = extract_file("input.txt");

	total_weight = 0;
	package_amount = 0;
	s_tok = strpbrk(str_file, "1234567890-");
	while (s_tok != NULL)
	{
		total_weight += atoi(s_tok);
		s_tok += strspn(s_tok, "1234567890-");
		s_tok = strpbrk(s_tok, "1234567890-");
		package_amount++;
	}

	i = 0;
	s_tok = str_file;
	packages = calloc(package_amount, sizeof(*packages));
	strtok(s_tok, "\n");
	while (i < package_amount)
	{
		packages[i] = atoi(s_tok);
		s_tok = strtok(NULL, "\n");
		i++;
	}

	qsort(packages, package_amount, sizeof(*packages), int_cmp);

	long	QE;
	int		min;

	min = package_amount;
	QE = INT64_MAX;

	depth_search(&min, &QE, packages, package_amount, 0, total_weight / 4, 1);

	printf("%ld, and %d\n", QE, min);
	return (0);
}