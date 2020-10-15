/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:09:21 by home              #+#    #+#             */
/*   Updated: 2020/10/14 03:33:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	process_line(int *row, int *col, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		direction("DULR", str[i], col, row);

		*row = restrict_val(0, *row, 2);
		*col = restrict_val(0, *col, 2);

		i++;
	}
}

int		main(void)
{
	int		row;
	int		col;
	char	*str_file;

	str_file = extract_file("input.txt");

	row = 1;
	col = 1;
	printf("RESULT: ");
	FOR_EACH_STRTOK(str_file, "\n",
		process_line(&row, &col, _tok);
		printf("%d", row * 3 + (col + 1));
	)
	printf("\n");
	return (0);
}
