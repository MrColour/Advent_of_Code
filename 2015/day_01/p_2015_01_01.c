/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 04:06:35 by home              #+#    #+#             */
/*   Updated: 2020/09/13 19:21:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	size_t	i;
	int		result;
	char	*file;

	i = 0;
	result = 0;
	file = extract_file("input.txt");

	result += count_occur("(", file);
	result -= count_occur(")", file);

	printf("Result: %d\n", result);
	return (0);
}
