/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_07_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 01:29:09 by home              #+#    #+#             */
/*   Updated: 2020/09/06 18:08:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

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

typedef	struct	s_hash_elem
{
	bool		solved;
	int			value;
}				t_hash_elem;

int		fetch_signal(char *needle, char **wires, t_hash_elem *memo_table);

int		wiretoi(char **wires, t_hash_elem *memo_table, char *check)
{
	int		result;

	if (isdigit(check[0]) == 1)
		result = (atoi(check));
	else
		result = (fetch_signal(check, wires, memo_table));
	return (result);
}

int		resolve_operation(char **wires, t_hash_elem *memo_table, int id)
{
	unsigned short	result;
	unsigned short	left;
	unsigned short	right;
	char			*ptr;

	if (strstr(wires[id], "NOT") != NULL)
	{
		ptr = &(wires[id][4]);
		result = ~(wiretoi(wires, memo_table, ptr));
	}
	else if (strstr(wires[id], "AND") != NULL)
	{
		left = wiretoi(wires, memo_table, &wires[id][0]);
		ptr = strstr(wires[id], "D ") + 2;
		right = wiretoi(wires, memo_table, ptr);

		result = left & right;
	}
	else if (strstr(wires[id], "OR") != NULL)
	{
		left = wiretoi(wires, memo_table, &wires[id][0]);
		ptr = strstr(wires[id], "R ") + 2;
		right = wiretoi(wires, memo_table, ptr);

		result = left | right;
	}
	else if (strstr(wires[id], "LSHIFT") != NULL)
	{
		left = wiretoi(wires, memo_table, &wires[id][0]);
		ptr = strstr(wires[id], "T ") + 2;
		right = wiretoi(wires, memo_table, ptr);

		result = left << right;
	}
	else if (strstr(wires[id], "RSHIFT") != NULL)
	{
		left = wiretoi(wires, memo_table, &wires[id][0]);
		ptr = strstr(wires[id], "T ") + 2;
		right = wiretoi(wires, memo_table, ptr);

		result = left >> right;
	}
	else
		result = wiretoi(wires, memo_table, &wires[id][0]);

	return (result);
}

int		fetch_signal(char *needle, char **wires, t_hash_elem *memo_table)
{
	int		i;
	char	*ptr;

	i = 0;
	while (wires[i] != NULL)
	{
		ptr = strstr(wires[i], "-> ");
		if (ptr != NULL)
		{
			ptr += 3;
			if (strncmp(needle, ptr, strchr(needle, ' ') - needle) == 0 &&
				strncmp(needle, ptr, strlen(ptr)) == 0)
				break ;
		}
		i++;
	}
	// printf("WIRE: %s\n", wires[i]);
	assert(wires[i] != NULL);

	if (memo_table[i].solved == true)
		return (memo_table[i].value);

	int	result;

	result = resolve_operation(wires, memo_table, i);

	memo_table[i].solved = true;
	memo_table[i].value = result;
	return (result);
}

int		main(void)
{
	int		i;
	int		result;
	char	*str_file;
	char	*ptr;

	str_file = extract_file("input.txt");

	i = 0;
	ptr = strchr(str_file, '\n');
	while (ptr != NULL)
	{
		i++;
		ptr++;
		ptr = strchr(ptr, '\n');
	}

	char		**wires;
	t_hash_elem	*memo_table;

	wires = calloc(i, sizeof(*wires));
	memo_table = calloc(i, sizeof(*memo_table));

	i = 0;
	wires[0] = str_file;
	while (wires[i] != NULL)
	{
		wires[i + 1] = wires[i];
		strsep(&(wires[i + 1]), "\n");
		i++;
	}

	result = fetch_signal("a", wires, memo_table);
	printf("RESULT: %d\n", result);

	return (0);
}