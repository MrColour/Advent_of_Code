/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_05_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:36:12 by home              #+#    #+#             */
/*   Updated: 2020/10/17 22:56:08 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	int		i;
	int		j;
	int		size;
	int		destroyed;

	str_file = extract_file("input.txt");
	size = strlen(str_file) - 1; //One more fot the newline.

	i = 0;
	j = 1;
	destroyed = 0;
	while (i < size)
	{
		if (str_file[i] + ('a' - 'A') == str_file[j] || str_file[i] + ('A' - 'a') == str_file[j])
		{
			// printf("Removed %c and %c\n", str_file[i], str_file[j]);
			str_file[i] = '\0';
			str_file[j] = '\0';
			while (i > 0 && str_file[i] == '\0')
				i--;
			j++;
			i--;
			destroyed++;
		}

		i++;
		if (i < 0)
			i = 0;
		if (j == i)
			j++;
	}
	answer(d, size - (destroyed * 2))
	return (0);
}
