/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_10_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 01:39:50 by home              #+#    #+#             */
/*   Updated: 2020/10/17 02:58:54 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	knot_hash(int len, int curr, int *list)
{
	int	i;
	int	stop;

	int	size = 256;

	int	top;
	int	bottom;

	bottom = curr;
	top = curr + len - 1;

	i = 0;
	stop = len / 2;
	while (i < stop)
	{
		// printf("INT: %d and %d\n", list[top % size], list[bottom % size]);
		SWAP(list[top % size], list[bottom % size], int)
		bottom++;
		top--;
		if (top < 0)
			top = size - 1;
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	int		list[256];
	size_t	i;

	str_file = extract_file("input.txt");
	str_file = strtok(str_file, ",");

	FOR_EACH(_i < (int)(sizeof(list) / 4),
		list[_i] = _i;
	)

	int		curr_pos;
	int		skip;
	int		len;

	skip = 0;
	curr_pos = 0;
	while (str_file != NULL)
	{
		len = atoi(str_file);

		// printf("%d and %d\n", len, curr_pos);
		knot_hash(len, curr_pos, list);

		str_file = strtok(NULL, ",");
		curr_pos += len + skip;
		curr_pos %= 256;
		skip++;
	}

	answer(d, list[0] * list[1]);
	return (0);
}
