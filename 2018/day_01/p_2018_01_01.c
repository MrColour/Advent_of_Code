/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_01_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:41:07 by home              #+#    #+#             */
/*   Updated: 2020/10/17 17:43:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, "\n",
		result += atoi(_tok);
	)
	answer(d, result);
	return (0);
}
