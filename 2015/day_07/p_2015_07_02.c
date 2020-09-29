/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_07_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 01:29:09 by home              #+#    #+#             */
/*   Updated: 2020/09/28 19:58:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#include <assert.h>

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
		right = wiretoi(wires, memo_table, ptr);

		result = ~(right);
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

	int	size;
	t_hash_elem	*memo_table;
	char		**wires;

	size = count_occur("\n", str_file);
	memo_table = calloc(size, sizeof(*memo_table));

	NEWLINE_SPLIT(wires, str_file, size)

	result = fetch_signal("a", wires, memo_table);
	// printf("RESULT: %d\n", result);
	bzero(memo_table, sizeof(*memo_table) * size);

	i = 0;
	while (wires[i] != NULL)
	{
		ptr = strstr(wires[i], "-> ");
		if (ptr != NULL)
		{
			ptr += 3;
			if (strncmp("b", ptr, strchr("b", ' ') - "b") == 0 &&
				strncmp("b", ptr, strlen(ptr)) == 0)
				break ;
		}
		i++;
	}

	memo_table[i].solved = true;
	memo_table[i].value = result;
	result = fetch_signal("a", wires, memo_table);

	printf("RESULT: %d\n", result);
	return (0);
}