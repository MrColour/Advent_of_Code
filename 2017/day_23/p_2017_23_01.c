/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_23_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:26:14 by home              #+#    #+#             */
/*   Updated: 2020/10/11 01:48:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

static int g_debug_int = 0;

//set
//sub
//mul
//jnz

int		do_op(char *str, int *regs)
{
	int		value2;
	int		jump;
	char	*ptr;

	ptr = str + skip_space(str, 2) + 1;
	// printf("S: [%s]\n", ptr);
	if (isalpha(ptr[0]))
		value2 = regs[ptr[0]];
	else
		value2 = atoi(ptr);

	jump = 1;
	if (str[2] == 't')
		regs[str[4]] = value2;
	else if (str[2] == 'b')
		regs[str[4]] -= value2;
	else if (str[2] == 'l')
	{
		regs[str[4]] *= value2;
		g_debug_int++;
	}
	else if (str[2] == 'z')
	{
		if (isalpha(str[4]) && regs[str[4]] != 0)
			jump = value2;
		else if (atoi(&str[4]) != 0)
			jump = value2;
	}
	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	**instr;
	int		regs['h' + 1] = { 0 };
	int		len;
	int		i;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(instr, str_file, len)
	len--;

	i = 0;
	while (i < len)
		i += do_op(instr[i], regs);

	printf("RESULT: %d\n", g_debug_int);
	return (0);
}
