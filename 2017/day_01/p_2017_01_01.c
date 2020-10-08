/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:12:20 by home              #+#    #+#             */
/*   Updated: 2020/10/08 03:39:17 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		sum;
	char	*str_file;

	i = 0;
	sum = 0;
	str_file = extract_file("input.txt");
	strchr(str_file, '\n')[0] = str_file[0];
	while (str_file[i + 1] != '\0')
	{
		if (str_file[i] == str_file[i + 1])
			sum += (str_file[i] - '0');
		i++;
	}
	printf("RESULT: %d\n", sum);
	return (0);
}
