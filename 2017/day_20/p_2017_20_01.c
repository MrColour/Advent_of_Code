/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_20_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 02:51:38 by home              #+#    #+#             */
/*   Updated: 2020/10/06 03:48:14 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

double	calc_acc(char *str)
{
	double	x_a;
	double	y_a;
	double	z_a;
	int		fetch;

	str += fetch_int(str, &fetch);
	x_a = fetch;
	str += fetch_int(str, &fetch);
	y_a = fetch;
	str += fetch_int(str, &fetch);
	z_a = fetch;

	return (x_a * x_a + y_a * y_a + z_a * z_a);
}

int		main(void)
{
	char	*str_file;
	double	min_a;
	double	temp_a;
	int		i;
	int		particle_id;

	str_file = extract_file("input.txt");

	i = 0;
	particle_id = 0;
	min_a = calc_acc(strchr(str_file, 'a'));

	strtok(str_file, "\n");
	while (str_file != NULL)
	{
		temp_a = calc_acc(strchr(str_file, 'a'));
		if (temp_a < min_a)
		{
			particle_id = i;
			min_a = temp_a;
		}
		str_file = strtok(NULL, "\n");
		i++;
	}
	printf("RESULT: %d\n", particle_id); //The correct thing would be to compare all particles that
	//have the same minimun acceration by their velocity, then by position.
	return (0);
}
