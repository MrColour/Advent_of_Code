/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:52:51 by home              #+#    #+#             */
/*   Updated: 2020/09/28 16:06:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		l, w, h;
	int		total_ribbon;
	char	*str_file;

	total_ribbon = 0;
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

		total_ribbon += (l * w * h);
		total_ribbon += (MIN(MIN((l + w), (w + h)), (h + l))) * 2;
	}

	printf("Result: %d\n", total_ribbon);
	return (0);
}
