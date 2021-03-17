/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_18_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:37:05 by home              #+#    #+#             */
/*   Updated: 2020/11/28 22:30:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

enum	sound_op
{
	SND,
	RCV,
	GET
}		sound_op;

void	sound_card(int op, long long *value)
{
	static long long frq;

	if (op == SND) { frq = *value; }
	else if (op == RCV) { printf("RESULT: %lld\n", frq); exit(0); }
	// else if (op == GET) { *value = frq; }
}

int		second_value(char *instr, long long *reg)
{
	char		*ptr;
	long long	result;

	ptr = instr + skip_space(instr, 2) + 1;
	// printf("AT: [%s]\n", ptr);
	if (isalpha(ptr[0]))
		result = reg[ptr[0]];
	else
		result = atoi(ptr);

	return (result);
}

/*
s[n]d
r[c]v
s[e]t
a[d]d
m[u]l
m[o]d
j[g]z
*/

int		do_op(char *instr, long long *reg)
{
	int			jump;
	long long	second_val;

	if (instr[1] == 'n')
		sound_card(SND, &reg[instr[4]]);
	else if (instr[1] == 'c')
	{
		if (reg[instr[4]] != 0)
			sound_card(RCV, NULL);
	}
	else
		second_val = second_value(instr, reg);

	jump = 1;
	if (instr[1] == 'e')
		reg[instr[4]] = second_val;
	else if (instr[1] == 'd')
		reg[instr[4]] += second_val;
	else if (instr[1] == 'u')
		reg[instr[4]] *= second_val;
	else if (instr[1] == 'o')
		reg[instr[4]] %= second_val;
	else if (instr[1] == 'g')
	{
		if (isalpha(instr[4]))
		{
			if (reg[instr[4]] > 0)
				jump = second_val;
		}
		else if (atoi(&instr[4]) > 0)
			jump = second_val;
	}

	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	**instr;
	int		len;
	int		ptr;
	long long	reg['z'] = { 0 };

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(instr, str_file, len)

	ptr = 0;
	while (ptr < len - 1)
	{
		printf("STR: %s %lld\n", instr[ptr], reg['a']);
		ptr += do_op(instr[ptr], reg);
	}
	return (0);
}
