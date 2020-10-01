/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:12:20 by home              #+#    #+#             */
/*   Updated: 2020/09/30 22:50:46 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		j;
	int		sum;
	char	*str_file;
	char	prev;

	i = 0;
	sum = 0;
	prev = '\0';
	str_file = extract_file("input.txt");
	while (str_file[i] != '\n')
	{
		if (prev == str_file[i])
			sum += (prev - '0');
		prev = str_file[i];
		i++;
	}
	if (prev == str_file[0])
		sum += (prev - '0');

	printf("RESULT: %d\n", sum);
	return (0);
}
