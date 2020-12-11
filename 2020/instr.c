/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/10 20:48:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define SIZE (10000)

int		do_op(char *line, int *regs, int *acc)
{
	int		jump = 1;
	int		num;
	char	*ptr;

	ptr = line;
	if (strchr("1234567890-", line[4]))
		ptr += fetch_int(line, &num);


	if (strstr(line, "set") != NULL)
	{

	}
	else if (strstr(line, "jmp") != NULL)
	{

	}
	else if (strstr(line, "nop") != NULL)
	{

	}
	else if (strstr(line, "acc") != NULL)
	{
		*acc += num;
	}

	return (jump);
}

int		main(void)
{
	int		i;
	int		j;
	int		len;
	char	**lines;
	char	*str_file;
	// char	**map;

	// str_file = extract_file("input.txt");
	str_file = extract_file("aoc++.h");
	NEWLINE_SPLIT(lines, str_file, len)
	// ALLOC_2D(map, SIZE * 2, SIZE * 2, calloc_wrapper, NULL)

	long long	count;
	long long	num;

	i = 0;
	j = 0;
	count = 0;
	// while (i < len)
	// {
	// 	printf("%s\n", lines[i]);

	// 	// lines[i] += fetch_int(lines[i], &num);

	// 	// printf("%lld\n", num);

	// 	i++;
	// }

	int regs[256] = { 0 };

	int acc = 0;

	i = 0;
	while (bound(0, i, len - 1))
	{
		printf("%s\n", lines[i]);
		i += do_op(lines[i], regs, &acc);
	}

	printf("%lld\n", count);
	return (0);
}
