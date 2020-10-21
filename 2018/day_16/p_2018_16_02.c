/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_16_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 06:45:02 by home              #+#    #+#             */
/*   Updated: 2020/10/21 04:19:14 by home             ###   ########.fr       */
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
	int		valid[20];
	char	*name;
	bool	found;
}				t_opcodes;

// Was like a puzzle moving the opcodes into the right place.
// Should figure out how this would be done programatically.

t_opcodes	opcodes[] = {
	{ borr , { 0 }, "borr", false },
	{ addr , { 0 }, "addr", false },
	{ eqrr , { 0 }, "eqrr", false },
	{ addi , { 0 }, "addi", false },
	{ eqri , { 0 }, "eqri", false },
	{ eqir , { 0 }, "eqir", false },
	{ gtri , { 0 }, "gtri", false },
	{ mulr , { 0 }, "mulr", false },
	{ setr , { 0 }, "setr", false },
	{ gtir , { 0 }, "gtir", false },
	{ muli , { 0 }, "muli", false },
	{ banr , { 0 }, "banr", false },
	{ seti , { 0 }, "seti", false },
	{ gtrr , { 0 }, "gtrr", false },
	{ bani , { 0 }, "bani", false },
	{ bori , { 0 }, "bori", false },
	{ NULL , { 0 }, "NULL", false }
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
		if (opcodes[i].found == true || opcodes[command_regs[0]].found == true)
		{
			i++;
			continue ;
		}
		memcpy(copy, before_regs, sizeof(before_regs));
		// printf("BEF: %d %d %d %d\n", copy[0], copy[1], copy[2], copy[3]);
		opcodes[i].fn(command_regs[1], command_regs[2], command_regs[3], copy);
		// printf("AFT: %d %d %d %d\n", copy[0], copy[1], copy[2], copy[3]);
		if (memcmp(copy, after_regs, sizeof(after_regs)) == 0)
		{
			opcodes[i].valid[command_regs[0]]++;
			match++;
		}
		else
			opcodes[i].valid[command_regs[0]] -= 10;
		i++;
	}
	return (match);
}

int	main(void)
{
	char	*str_file;

	int		regs[4] = { 0 };
	int		command[4] = { 0 };

	str_file = extract_file("input.txt");
	str_file = &strstr(str_file, "\n\n\n")[4];

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &command[0]);
		_tok += fetch_int(_tok, &command[1]);
		_tok += fetch_int(_tok, &command[2]);
		_tok += fetch_int(_tok, &command[3]);

		opcodes[command[0]].fn(command[1], command[2], command[3], regs);
	)
	answer(d, regs[0]);

	//Comment out the main above, and uncomment the below for method of finding opcode order.

	// char	*str_file;
	// char	*before;
	// char	*command;
	// char	*after;

	// str_file = extract_file("input.txt");
	// strstr(str_file, "\n\n\n")[0] = '\0';

	// str_file = strtok(str_file, "\n");
	// while (str_file != NULL)
	// {
	// 	before = str_file;
	// 	command = strtok(NULL, "\n");
	// 	after = strtok(NULL, "\n");

	// 	debugger(before, command, after);

	// 	str_file = strtok(NULL, "\n");
	// }

	// int i = 0;
	// int j = 0;

	// while (opcodes[i].fn != NULL)
	// {
	// 	j = 0;
	// 	printf("N: %s ", opcodes[i].name);
	// 	while (j < 16)
	// 	{
	// 		if (j == i)
	// 			printf(GOLD"%4d\e[0m ", opcodes[i].valid[j]);
	// 		else
	// 			printf("%4d ", opcodes[i].valid[j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

	return (0);
}
