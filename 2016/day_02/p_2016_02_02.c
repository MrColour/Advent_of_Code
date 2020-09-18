/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:24:33 by home              #+#    #+#             */
/*   Updated: 2020/09/14 22:40:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

enum	valid
{
	N = 0b0000,
	R = 0b0001,
	L = 0b0010,
	U = 0b0100,
	D = 0b1000,
};

void	process_line(int *row, int *col, char *str, int **mask)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'U' && (mask[*row][*col] & U))
			(*row)--;
		else if (str[i] == 'D' && (mask[*row][*col] & D))
			(*row)++;
		else if (str[i] == 'R' && (mask[*row][*col] & R))
			(*col)++;
		else if (str[i] == 'L' && (mask[*row][*col] & L))
			(*col)--;

		i++;
	}
}

int		main(void)
{
	int		row;
	int		col;
	char	*s_tok;
	char	*str_file;

	int		**mask;

	str_file = extract_file("input.txt");

	row = 2;
	col = 0;

	mask = calloc(5, sizeof(*mask));
	mask[0] = calloc(5, sizeof(**mask));
	mask[1] = calloc(5, sizeof(**mask));
	mask[2] = calloc(5, sizeof(**mask));
	mask[3] = calloc(5, sizeof(**mask));
	mask[4] = calloc(5, sizeof(**mask));

	mask[0][2] = D;

	mask[1][1] = R | D;
	mask[1][2] = R | D | L | D;
	mask[1][3] = L | D;

	mask[2][0] = R;
	mask[2][1] = R | L | U | D;
	mask[2][2] = R | L | U | D;
	mask[2][3] = R | L | U | D;
	mask[2][4] = L;

	mask[3][1] = R | U;
	mask[3][2] = R | U | L | D;
	mask[3][3] = L | U;

	mask[4][2] = U;

	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		process_line(&row, &col, s_tok, mask);
		// printf("LINE: %s\n", s_tok);
		printf("%d ", row * 5 + (col + 1));
		s_tok = strtok(NULL, "\n");
	}
	printf("\n");
	return (0);
}

//1
//6
//11
//16
//21

//26B96