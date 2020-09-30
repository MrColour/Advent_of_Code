/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_18_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 01:07:01 by home              #+#    #+#             */
/*   Updated: 2020/09/30 00:47:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct		s_prev
{
	char			lcr[4];
}					t_prev;

void	create_lcr(t_prev *tile, char *prev, int i)
{
	if (i == 0 || prev[i - 1] == '.')
		tile->lcr[0] = '.';
	else
		tile->lcr[0] = '^';

	tile->lcr[1] = prev[i];

	if (i + 1 == (int)strlen(prev) || prev[i + 1] == '.')
		tile->lcr[2] = '.';
	else
		tile->lcr[2] = '^';
}

void	new_row(char *dst, char *src)
{
	int		i;
	t_prev	tile;

	i = 0;
	tile.lcr[3] = '\0';
	while (src[i] != '\0')
	{
		create_lcr(&tile, src, i);

		if (strstr("^^. .^^ ^.. ..^", tile.lcr))
			dst[i] = '^';
		else
			dst[i] = '.';
		i++;
	}
}

int		main(void)
{
	int		safe_tiles;
	char	*prev;
	char	*curr;
	int		row;

	prev = extract_file("input.txt");
	strchr(prev, '\n')[0] = '\0';
	curr = strdup(prev);

	row = 1;
	safe_tiles = count_occur(".", prev);
	while (row < 40)
	{
		new_row(curr, prev);

		safe_tiles += count_occur(".", curr);

		SWAP(prev, curr, char *)
		row++;
	}
	printf("RESULT: %d\n", safe_tiles);
	return (0);
}
