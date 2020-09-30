/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_23_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 02:03:54 by home              #+#    #+#             */
/*   Updated: 2020/09/30 00:59:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	toggle_protocal(char **code, int index, int len)
{
	char	*toggle;

	if (index >= len)
		return ;

	toggle = code[index];
	if (toggle[0] == 'i')
		memcpy(toggle, "dec", 3);
	else if (toggle[0] == 'd' || toggle[0] == 't')
		memcpy(toggle, "inc", 3);
	else if (toggle[0] == 'j')
		memcpy(toggle, "cpy", 3);
	else if (toggle[0] == 'c')
		memcpy(toggle, "jnz", 3);
}

int		do_op(char **code, int ins_ptr, int *reg, int len)
{
	int		jump;
	char	*instr;

	jump = 1;
	instr = code[ins_ptr];
	if (instr[0] == 'c')
	{
		if (isalpha(instr[4]))
			reg[instr[6] - 'a'] = reg[instr[4] - 'a'];
		else if (isalpha(instr[skip_space(instr, 2) + 1]) != 0)
			reg[instr[skip_space(instr, 2) + 1] - 'a'] = atoi(&instr[4]);
	}
	else if (instr[0] == 'i')
		reg[instr[4] - 'a']++;
	else if (instr[0] == 'd')
		reg[instr[4] - 'a']--;
	else if (instr[0] == 't')
	{
		if (isalpha(instr[4]))
			toggle_protocal(code, ins_ptr + reg[instr[4] - 'a'], len);
		else
			toggle_protocal(code, ins_ptr + atoi(&instr[4]), len);
	}
	else
	{
		if (isalpha(instr[4]) && reg[instr[4] - 'a'] != 0) //First argu is reg
		{
			if (isalpha(instr[skip_space(instr, 2) + 1])) //Sec argu is reg
				jump = reg[instr[skip_space(instr, 2) + 1] - 'a'];
			else
				jump = atoi(&instr[6]);
		}
		else if (atoi(&instr[4]) != 0) //First argu is not reg
		{
			if (isalpha(instr[skip_space(instr, 2) + 1])) //Sec argu is reg
				jump = reg[instr[skip_space(instr, 2) + 1] - 'a'];
			else
				jump = atoi(&instr[skip_space(instr, 2) + 1]);
		}
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

	NEWLINE_SPLIT(instr, str_file, len)

	int	reg[4] = { 0 };

	i_ptr = 0;

	reg[0] = 12;
	while (i_ptr < len)
		i_ptr += do_op(instr, i_ptr, reg, len);

	printf("\n%d, %d, %d, %d\n", reg[0], reg[1], reg[2], reg[3]);
	return (0);
}
