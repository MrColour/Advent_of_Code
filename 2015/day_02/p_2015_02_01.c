/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:52:51 by home              #+#    #+#             */
/*   Updated: 2020/09/28 04:05:02 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		l, w, h;
	int		total_paper;
	char	*str_file;

	total_paper = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "x\n");
	while (str_file != NULL)
	{
		l = atoi(str_file);
		str_file = strtok(NULL, "x\n");
		w = atoi(str_file);
		str_file = strtok(NULL, "x\n");
		h = atoi(str_file);
		str_file = strtok(NULL, "x\n");

		total_paper += (2 * l * w) + (2 * w * h) + (2 * h * l);
		total_paper += _min(_min((l * w), (w * h)), (h * l));
	}

	printf("Result: %d\n", total_paper);
	return (0);
}
