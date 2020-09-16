/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_07_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 01:45:43 by home              #+#    #+#             */
/*   Updated: 2020/09/16 03:26:35 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool	abba_finder(char *str)
{
	int		i;
	bool	result;

	i = 0;
	result = false;
	while (str[i + 0] != '\0' &&
		   str[i + 1] != '\0' &&
		   str[i + 2] != '\0' &&
		   str[i + 3] != '\0' &&
		   result == false)
	{

		if (str[i + 0] != str[i + 1] &&
			str[i + 0] == str[i + 3] &&
			str[i + 1] == str[i + 2])
				result = true;

		i++;
	}
	return (result);
}

bool	process_string(char *ip)
{
	char	*ptr;
	char	*open;
	int		i;
	int		open_a;
	int		closed_a;
	int		rounds;

	rounds = count_occur("[", ip);
	ptr = strchr(ip, '[') + 1;
	ptr[-1] = '\0';

	open_a = 0;
	closed_a = 0;

	// printf("OPEN: %s\n", ip);
	if (abba_finder(ip) == true)
		open_a++;

	i = 0;
	while (i < rounds)
	{

		open = strchr(ptr, ']') + 1;
		open[-1] = '\0';

		// printf("CLOSED: %s\n", ptr);
		if (abba_finder(ptr) == true)
			closed_a++;

		ptr = strchr(open, '[') + 1;
		if (ptr - 1 != NULL)
			ptr[-1] = '\0';

		// printf("OPEN: %s\n", open);
		if (abba_finder(open) == true)
			open_a++;

		i++;
	}
	if (closed_a > 0)
		return (false);

	if (open_a >= 1)
		return (true);
	else
		return (false);
}

int		main(void)
{
	int		i;
	char	*str_file;
	char	*s_tok;
	int		TLS_count;

	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");

	i = 1;
	TLS_count = 0;
	while (s_tok != NULL)
	{
		if (process_string(s_tok) == true)
			TLS_count++;
		s_tok = strtok(NULL, "\n");
		i++;
	}

	printf("%d\n", TLS_count);
	return (0);
}