/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_24_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 05:04:33 by home              #+#    #+#             */
/*   Updated: 2020/10/07 21:19:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_pipe
{
	int		a;
	int		b;
	bool	used;
}				t_pipe;

void	dfs_optimize(t_pipe *pipes, int size, int curr, int len, int connecting, int *result, int *longest)
{
	int	i;

	if (*longest == len && *result < curr)
		*result = curr;
	if (*longest < len)
	{
		*result = curr;
		*longest = len;
	}

	i = 0;
	while (i < size)
	{
		if (pipes[i].used == false && (pipes[i].a == connecting || pipes[i].b == connecting))
		{
			pipes[i].used = true;
			if (pipes[i].a == connecting)
				dfs_optimize(pipes, size, curr + pipes[i].a + pipes[i].b, len + 1, pipes[i].b, result, longest);
			else
				dfs_optimize(pipes, size, curr + pipes[i].a + pipes[i].b, len + 1, pipes[i].a, result, longest);
			pipes[i].used = false;
		}
		i++;
	}
}

int		main(void)
{
	char	*s_tok;
	t_pipe	*pipes;
	int		len;
	int		i;

	s_tok = extract_file("input.txt");

	len = count_occur("\n", s_tok);
	pipes = calloc(len, sizeof(*pipes));

	i = 0;
	s_tok = strtok(s_tok, "\n");
	while (s_tok != NULL)
	{
		// printf("%s\n", s_tok);
		s_tok += fetch_int(s_tok, &pipes[i].a);
		s_tok += fetch_int(s_tok, &pipes[i].b);
		pipes[i].used = false;
		s_tok = strtok(NULL, "\n");
		i++;
	}

	int	result;
	int	longest;

	i = 0;
	result = INT_MIN;
	longest = 0;
	while (i < len)
	{
		if (pipes[i].a == 0 || pipes[i].b == 0)
		{
			pipes[i].used = true;
			if (pipes[i].a == 0)
				dfs_optimize(pipes, len, pipes[i].a + pipes[i].b, 1, pipes[i].b, &result, &longest);
			else
				dfs_optimize(pipes, len, pipes[i].a + pipes[i].b, 1, pipes[i].a, &result, &longest);
			pipes[i].used = false;
		}
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}
