/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:48:39 by home              #+#    #+#             */
/*   Updated: 2020/10/02 00:52:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_reg
{

	char		*id;
	int			val;

	struct s_reg	*next;
}				t_reg;

int		get_index(char *reg)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (reg[i] != ' ')
	{
		result *= 26;
		result += reg[i] - 'a' + 1;
		i++;
	}
	return (result);
}

void	do_op(char *r1, char *comm, char *r2, int *regs)
{
	int	r1_i;
	int	r2_i;
	int	num;
	int	add;

	r1_i = get_index(r1);
	r2_i = get_index(r2);
	fetch_int(r1, &add);
	fetch_int(r2, &num);

	if (strchr(r1, ' ')[1] == 'd')
		add *= -1;

	if (strncmp(comm, "< ", 2) == 0 && regs[r2_i] < num)
		regs[r1_i] += add;
	if (strncmp(comm, "<=", 2) == 0 && regs[r2_i] <= num)
		regs[r1_i] += add;
	if (strncmp(comm, "> ", 2) == 0 && regs[r2_i] > num)
		regs[r1_i] += add;
	if (strncmp(comm, ">=", 2) == 0 && regs[r2_i] >= num)
		regs[r1_i] += add;
	if (strncmp(comm, "==", 2) == 0 && regs[r2_i] == num)
		regs[r1_i] += add;
	if (strncmp(comm, "!=", 2) == 0 && regs[r2_i] != num)
		regs[r1_i] += add;
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	char	*r1;
	char	*r2;
	char	*comm;
	int		reg[26 * 26 * 26] = { 0 };

	str_file = extract_file("input.txt");

	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		r1 = s_tok;
		r2 = &(strstr(s_tok, "if")[3]);
		comm = &strchr(r2, ' ')[1];

		do_op(r1, comm, r2, reg);

		s_tok = strtok(NULL, "\n");
	}

	size_t i;
	int		max;
	max = INT_MIN;

	i = 0;
	while (i < sizeof(reg) / 4)
	{
		max = MAX(max, reg[i]);
		i++;
	}

	printf("RESULT: %d\n", max);
	return (0);
}
