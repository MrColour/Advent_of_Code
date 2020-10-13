/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 04:06:35 by home              #+#    #+#             */
/*   Updated: 2020/10/12 18:29:04 by home             ###   ########.fr       */
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

	answer(d, result);
	return (0);
}
