/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_16_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 06:45:02 by home              #+#    #+#             */
/*   Updated: 2020/10/21 03:07:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	addr(int a, int b, int c, int *regs) { regs[c] = regs[a] + regs[b]; }
void	addi(int a, int b, int c, int *regs) { regs[c] = regs[a] + b; }
void	mulr(int a, int b, int c, int *regs) { regs[c] = regs[a] * regs[b]; }
void	muli(int a, int b, int c, int *regs) { regs[c] = regs[a] * b; }
void	banr(int a, int b, int c, int *regs) { regs[c] = regs[a] & regs[b]; }
void	bani(int a, int b, int c, int *regs) { regs[c] = regs[a] & b; }
void	borr(int a, int b, int c, int *regs) { regs[c] = regs[a] | regs[b]; }
void	bori(int a, int b, int c, int *regs) { regs[c] = regs[a] | b; }
void	setr(int a, int b, int c, int *regs) { regs[c] = regs[a]; }
void	seti(int a, int b, int c, int *regs) { regs[c] = a; }
void	gtir(int a, int b, int c, int *regs) { regs[c] = (a > regs[b]) ? 1 : 0; }
void	gtri(int a, int b, int c, int *regs) { regs[c] = (regs[a] > b) ? 1 : 0; }
void	gtrr(int a, int b, int c, int *regs) { regs[c] = (regs[a] > regs[b]) ? 1 : 0; }
void	eqir(int a, int b, int c, int *regs) { regs[c] = (a == regs[b]) ? 1 : 0; }
void	eqri(int a, int b, int c, int *regs) { regs[c] = (regs[a] == b) ? 1 : 0; }
void	eqrr(int a, int b, int c, int *regs) { regs[c] = (regs[a] == regs[b]) ? 1 : 0; }

typedef struct	s_opcodes
{
	void	(*fn)(int, int, int, int *);
}				t_opcodes;

t_opcodes	opcodes[] = {
	{ addr },
	{ addi },
	{ mulr },
	{ muli },
	{ banr },
	{ bani },
	{ borr },
	{ bori },
	{ setr },
	{ seti },
	{ gtir },
	{ gtri },
	{ gtrr },
	{ eqir },
	{ eqri },
	{ eqrr },
	{ NULL }
};

int		debugger(char *before, char *command, char *after)
{
	int		before_regs[4] = { 0 };
	int		after_regs[4] = { 0 };
	int		command_regs[4] = { 0 };
	int		copy[4] = { 0 };
	int		match;
	int		i;

	before += fetch_int(before, &before_regs[0]);
	before += fetch_int(before, &before_regs[1]);
	before += fetch_int(before, &before_regs[2]);
	before += fetch_int(before, &before_regs[3]);

	after += fetch_int(after, &after_regs[0]);
	after += fetch_int(after, &after_regs[1]);
	after += fetch_int(after, &after_regs[2]);
	after += fetch_int(after, &after_regs[3]);

	command += fetch_int(command, &command_regs[0]);
	command += fetch_int(command, &command_regs[1]);
	command += fetch_int(command, &command_regs[2]);
	command += fetch_int(command, &command_regs[3]);

	i = 0;
	match = 0;
	while (opcodes[i].fn != NULL)
	{
		memcpy(copy, before_regs, sizeof(before_regs));
		// printf("BEF: %d %d %d %d\n", copy[0], copy[1], copy[2], copy[3]);
		opcodes[i].fn(command_regs[1], command_regs[2], command_regs[3], copy);
		// printf("AFT: %d %d %d %d\n", copy[0], copy[1], copy[2], copy[3]);
		if (memcmp(copy, after_regs, sizeof(after_regs)) == 0)
			match++;
		i++;
	}
	return (match);
}

int	main(void)
{
	char	*str_file;
	char	*before;
	char	*command;
	char	*after;
	int		result;

	str_file = extract_file("input.txt");
	strstr(str_file, "\n\n\n")[0] = '\0';

	// printf("%s\n", str_file);

	result = 0;
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		before = str_file;
		command = strtok(NULL, "\n");
		after = strtok(NULL, "\n");

		if (debugger(before, command, after) >= 3)
			result++;

		str_file = strtok(NULL, "\n");
	}
	answer(d, result);
	return (0);
}
