/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_24_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 05:04:33 by home              #+#    #+#             */
/*   Updated: 2020/10/11 23:45:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_pipe
{
	int		a;
	int		b;
	bool	used;
}				t_pipe;

void	dfs_optimize(t_pipe *pipes, int len, int curr, int connecting, int *result)
{
	int	i;

	if (*result < curr)
		*result = curr;

	i = 0;
	while (i < len)
	{
		if (pipes[i].used == false && (pipes[i].a == connecting || pipes[i].b == connecting))
		{
			pipes[i].used = true;
			if (pipes[i].a == connecting)
				dfs_optimize(pipes, len, curr + pipes[i].a + pipes[i].b, pipes[i].b, result);
			else
				dfs_optimize(pipes, len, curr + pipes[i].a + pipes[i].b, pipes[i].a, result);
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

	FOR_EACH_STRTOK(s_tok, "\n",
		_tok += fetch_int(_tok, &pipes[_i].b);
		_tok += fetch_int(_tok, &pipes[_i].a);
		pipes[_i].used = false;
	)

	int	result;

	i = 0;
	result = INT_MIN;
	while (i < len)
	{
		if (pipes[i].a == 0 || pipes[i].b == 0)
		{
			pipes[i].used = true;
			if (pipes[i].a == 0)
				dfs_optimize(pipes, len, pipes[i].a + pipes[i].b, pipes[i].b, &result);
			else
				dfs_optimize(pipes, len, pipes[i].a + pipes[i].b, pipes[i].a, &result);
			pipes[i].used = false;
		}
		i++;
	}
	answer(d, result);
	return (0);
}
