/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_15_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:48:09 by home              #+#    #+#             */
/*   Updated: 2020/11/25 22:01:20 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	long long	a;
	int			ia;
	long long	b;
	int			ib;

	int			f_a;
	int			f_b;

	str_file = extract_file("input.txt");
	str_file += fetch_int(str_file, &ia);
	fetch_int(str_file, &ib);
	a = ia;
	b = ib;
	f_a = 16807;
	f_b = 48271;

	int			i;
	int			result;

	i = 0;
	result = 0;
	while (i < 40000000)
	{
		a = (a * f_a) % 2147483647;
		b = (b * f_b) % 2147483647;
		if ((short)a == (short)b)
			result++;
		// printf("%d\n", i);
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}
