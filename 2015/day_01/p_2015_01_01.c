/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 04:06:35 by home              #+#    #+#             */
/*   Updated: 2020/09/28 04:02:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		result;
	char	*file;

	file = extract_file("input.txt");

	result = count_occur("(", file);
	result -= strlen(file) - result;

	printf("Result: %d\n", result);
	return (0);
}
