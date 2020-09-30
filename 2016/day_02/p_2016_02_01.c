/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:09:21 by home              #+#    #+#             */
/*   Updated: 2020/09/29 17:15:54 by home             ###   ########.fr       */
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
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		process_line(&row, &col, str_file);
		printf("%d", row * 3 + (col + 1));
		str_file = strtok(NULL, "\n");
	}
	printf("\n");
	return (0);
}
