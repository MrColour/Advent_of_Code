/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:53:29 by home              #+#    #+#             */
/*   Updated: 2020/10/11 23:53:49 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		process_line(char *line)
{
	int	i;
	int	j;
	int	size;
	int	*nums;

	nums = alloca(strlen(line) * sizeof(nums));
	FOR_EACH(line[0] != '\0', line += fetch_int(line, &(nums[_i]));)

	i = 0;
	size = _i;
	while (i < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
				break ;
			j++;
		}
		if (j <= size && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0))
			break ;
		i++;
	}

	if (nums[i] > nums[j])
		return (nums[i] / nums[j]);
	else
		return (nums[j] / nums[i]);
}

int		main(void)
{
	char	*s_tok;
	int		result;

	result = 0;
	s_tok = extract_file("input.txt");

	FOR_EACH_STRTOK(s_tok, "\n", result += process_line(_tok);)
	answer(d, result);
	return (0);
}
