/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_03_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:25:30 by home              #+#    #+#             */
/*   Updated: 2020/09/30 23:51:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		corner;
	int		finding;

	i = 0;
	finding = atoi(extract_file("input.txt"));
	while (1)
	{
		corner = (i * 2) + 1;
		if (finding <= corner * corner)
			break ;
		i++;
	}

	int at;
	int dif;

	dif = 0;
	at = corner * corner;
	while (bound(at - (corner - 1), finding, at) == false)
		at = at - (corner - 1);
	dif = at - finding;
	printf("RESULT: %d\n", ((corner / 2) - dif) + (corner / 2));
	return (0);
}
