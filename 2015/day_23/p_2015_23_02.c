/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_23_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 04:23:55 by home              #+#    #+#             */
/*   Updated: 2020/09/28 22:13:40 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		do_op(char *instr, int *a, int *b)
{
	int		jump;
	int		cmp;

	if (strncmp(instr, "hlf", strlen("hlf")) == 0)
	{
		if (instr[4] == 'a')
			*a /= 2;
		else
			*b /= 2;
		jump = 1;
	}
	else if (strncmp(instr, "tpl", strlen("tpl")) == 0)
	{
		if (instr[4] == 'a')
			*a *= 3;
		else
			*b *= 3;
		jump = 1;
	}
	else if (strncmp(instr, "inc", strlen("inc")) == 0)
	{
		if (instr[4] == 'a')
			*a += 1;
		else
			*b += 1;
		jump = 1;
	}
	else if (strncmp(instr, "jmp", strlen("jmp")) == 0)
		fetch_int(instr, &jump);
	else if (strncmp(instr, "jie", strlen("jie")) == 0)
	{
		if (instr[4] == 'a')
			cmp = *a;
		else
			cmp = *b;

		if (cmp % 2 == 0)
			fetch_int(instr, &jump);
		else
			jump = 1;
	}
	else
	{
		if (instr[4] == 'a')
			cmp = *a;
		else
			cmp = *b;

		if (cmp == 1)
			fetch_int(instr, &jump);
		else
			jump = 1;
	}

	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	**instructions;
	int		instr_ptr;
	int		program_length;

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(instructions, str_file, program_length)

	int	a;
	int	b;

	a = 1;
	b = 0;
	instr_ptr = 0;
	while (instr_ptr < program_length)
		instr_ptr += do_op(instructions[instr_ptr], &a, &b);
	printf("RESULT: %d\n", b);
	return (0);
}