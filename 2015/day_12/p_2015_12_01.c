/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_12_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:15:06 by home              #+#    #+#             */
/*   Updated: 2020/09/28 20:33:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		result;
	char	*str_file;

	result = 0;
	str_file = extract_file("input.txt");
	while (str_file != NULL && str_file[0] != '\0')
	{
		result += atoi(str_file);
		str_file += strspn(str_file, DIGITS);
		str_file = strpbrk(str_file, DIGITS);
		printf("STR: [ %.5s ]\n", str_file);
	}
	printf("Result: %d\n", result);
	return (0);
}