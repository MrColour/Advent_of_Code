/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_14_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:30:05 by home              #+#    #+#             */
/*   Updated: 2020/09/28 03:22:02 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		calc_reindeer_dist(int speed, int fly_dur, int rest_dur, int race_dur)
{
	int	result;
	int	stride_dur;
	int	strides;
	int	time_remaining;

	stride_dur = fly_dur + rest_dur;
	strides = race_dur / stride_dur;
	time_remaining = race_dur % stride_dur;

	result = 0;
	result += strides * speed * fly_dur;
	if (time_remaining > fly_dur)
		result += fly_dur * speed;
	else
		rest_dur += time_remaining * speed;

	return (result);
}

int		main(void)
{
	char	*str_file;
	char	*ptr;
	int		race_dur;
	int		speed, fly_dur, rest_dur;

	int		max;
	int		temp;

	race_dur = 2503;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		ptr = str_file;
		ptr += fetch_int(ptr, &speed);
		ptr += fetch_int(ptr, &fly_dur);
		ptr += fetch_int(ptr, &rest_dur);

		temp = calc_reindeer_dist(speed, fly_dur, rest_dur, race_dur);
		max = _max(temp, max);

		str_file = strtok(NULL, "\n");
	}
	printf("Result: %d\n", max);
	return (0);
}