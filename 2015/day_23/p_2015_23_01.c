/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_23_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 04:23:55 by home              #+#    #+#             */
/*   Updated: 2020/09/10 05:08:40 by home             ###   ########.fr       */
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

int		do_op(char *instr, int *a, int *b)
{
	int		jump;
	int		cmp;
	char	*offset;

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
	{
		offset = strchr(instr, ' ');
		jump = atoi(offset);
	}
	else if (strncmp(instr, "jie", strlen("jie")) == 0)
	{
		if (instr[4] == 'a')
			cmp = *a;
		else
			cmp = *b;

		offset = strchr(&instr[6], ' ');
		if (cmp % 2 == 0)
			jump = atoi(offset);
		else
			jump = 1;
	}
	else
	{
		if (instr[4] == 'a')
			cmp = *a;
		else
			cmp = *b;

		offset = strchr(&instr[6], ' ');
		if (cmp == 1)
			jump = atoi(offset);
		else
			jump = 1;
	}

	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	char	**instructions;
	int		instr_ptr;
	int		program_length;

	str_file = extract_file("input.txt");
	program_length = -1;
	s_tok = str_file - 1;
	while (s_tok != NULL)
	{
		s_tok++;
		s_tok = strchr(s_tok, '\n');
		program_length++;
	}

	instr_ptr = 0;
	instructions = calloc(program_length, sizeof(*instructions));
	instructions[instr_ptr] = strtok(str_file, "\n");
	while (instr_ptr < program_length)
	{
		instructions[instr_ptr + 1] = strtok(NULL, "\n");
		instr_ptr++;
	}

	int	a;
	int	b;

	a = 0;
	b = 0;
	instr_ptr = 0;
	while (instr_ptr < program_length)
		instr_ptr += do_op(instructions[instr_ptr], &a, &b);
	printf("RESULT: %d\n", b);
	return (0);
}