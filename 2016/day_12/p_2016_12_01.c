/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_12_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 01:49:56 by home              #+#    #+#             */
/*   Updated: 2020/09/27 23:21:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define A (0)
#define B (1)
#define C (2)
#define D (3)

// .0123456
// "cpy a b"
// "inc"
// "dec"
// "jnz"

int		do_op(char *instr, int *reg)
{
	int	jump;

	jump = 1;
	if (instr[0] == 'c')
	{
		if (isalpha(instr[4]))
			reg[instr[6] - 'a'] = reg[instr[4] - 'a'];
		else
			reg[instr[skip_space(instr, 2) + 1] - 'a'] = atoi(&instr[4]);
	}
	else if (instr[0] == 'i')
		reg[instr[4] - 'a']++;
	else if (instr[0] == 'd')
		reg[instr[4] - 'a']--;
	else
	{
		if (reg[instr[4] - 'a'] != 0)
			jump = atoi(&instr[6]);
	}
	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	**instr;
	int		len;
	int		i_ptr;

	str_file = extract_file("input.txt");

	// char	*s_tok;
	// len = count_occur("\n", str_file);
	// i_ptr = 0;
	// s_tok = strtok(str_file, "\n");
	// instr = calloc(len, sizeof(*instr));
	// while (s_tok != NULL)
	// {
	// 	instr[i_ptr] = s_tok;
	// 	s_tok = strtok(NULL, "\n");
	// 	i_ptr++;
	// }

	// char	*s_tok;
	// len = count_occur("\n", str_file);
	// s_tok = strtok(str_file, "\n");

	// g_ameta.s_delim = "\n";
	// g_ameta.iter_addr = (void **)(&s_tok);
	// ALLOC_2D(instr, len, 0, strtok_alloc, &g_ameta);

	NEWLINE_SPLIT(instr, str_file, len)

	int	reg[4] = { 0 };

	i_ptr = 0;
	while (i_ptr < len)
		i_ptr += do_op(instr[i_ptr], reg);

	printf("%d, %d, %d, %d\n", reg[0], reg[1], reg[2], reg[3]);

	return (0);
}
