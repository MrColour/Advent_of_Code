/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:53:29 by home              #+#    #+#             */
/*   Updated: 2020/09/30 23:20:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		process_line(char *line)
{
	int	i;
	int	j;
	int	size;
	int	*nums;

	size = 0;
	nums = alloca(strlen(line) * sizeof(nums));
	while (line[0] != '\0')
	{
		line += fetch_int(line, &(nums[size]));
		size++;
	}

	i = 0;
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
	char	*str_file;
	char	*s_tok;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		result += process_line(s_tok);
		s_tok = strtok(NULL, "\n");
	}
	printf("RESULT: %d\n", result);
	return (0);
}
