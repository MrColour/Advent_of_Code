/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:09:21 by home              #+#    #+#             */
/*   Updated: 2020/09/14 22:23:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	process_line(int *row, int *col, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'U')
			(*row)--;
		else if (str[i] == 'D')
			(*row)++;
		else if (str[i] == 'R')
			(*col)++;
		else if (str[i] == 'L')
			(*col)--;

		if (*row == -1)
			*row = 0;
		if (*row == 3)
			*row = 2;

		if (*col == -1)
			*col = 0;
		if (*col == 3)
			*col = 2;
		i++;
	}
}

int		main(void)
{
	int		row;
	int		col;
	char	*s_tok;
	char	*str_file;

	str_file = extract_file("input.txt");

	row = 1;
	col = 1;
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		process_line(&row, &col, s_tok);
		// printf("LINE: %s\n", s_tok);
		printf("%d", row * 3 + (col + 1));
		s_tok = strtok(NULL, "\n");
	}
	printf("\n");
	return (0);
}
