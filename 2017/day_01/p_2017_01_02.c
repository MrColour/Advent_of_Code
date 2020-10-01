/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_01_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:12:20 by home              #+#    #+#             */
/*   Updated: 2020/09/30 22:50:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		j;
	int		sum;
	char	*str_file;

	i = 0;
	sum = 0;
	str_file = extract_file("input.txt");
	j = (strchr(str_file, '\n') - str_file) / 2;
	while (str_file[i] != '\n')
	{
		if (str_file[j] == '\n')
			j = 0;

		if (str_file[j] == str_file[i])
			sum += (str_file[j] - '0');

		i++;
		j++;
	}
	printf("RESULT: %d\n", sum);
	return (0);
}
