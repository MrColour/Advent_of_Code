/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_08_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:48:39 by home              #+#    #+#             */
/*   Updated: 2020/10/10 19:17:48 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

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

int		do_op(char *r1, char *comm, char *r2, int *regs, int max)
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

	return (MAX(max, regs[r1_i]));
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	char	*r1;
	char	*r2;
	char	*comm;
	int		reg[26 * 26 * 26] = { 0 };
	int		max;

	str_file = extract_file("input.txt");

	int i = 0;
	max = INT_MIN;
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL && i < 1000)
	{
		r1 = s_tok;
		r2 = &(strstr(s_tok, "if")[3]);
		comm = &strchr(r2, ' ')[1];

		max = do_op(r1, comm, r2, reg, max);

		s_tok = strtok(NULL, "\n");
		i++;
	}

	printf("RESULT: %d\n", max);
	return (0);
}
