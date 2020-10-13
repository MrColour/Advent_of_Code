/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_01_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:44:17 by home              #+#    #+#             */
/*   Updated: 2020/10/12 21:30:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	size_t	i;
	int		level;
	char	*file;

	i = 0;
	level = 0;
	file = extract_file("input.txt");
	while (file[i] != '\0' && level >= 0)
	{
		if (file[i] == '(')
			level++;
		else
			level--;
		i++;
	}
	answer(zu, i);
	return (0);
}
