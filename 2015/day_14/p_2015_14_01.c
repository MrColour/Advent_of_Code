/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_14_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:30:05 by home              #+#    #+#             */
/*   Updated: 2020/10/13 02:46:12 by home             ###   ########.fr       */
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
	int		race_dur;
	int		speed, fly_dur, rest_dur;

	int		max;
	int		temp;

	race_dur = 2503;
	str_file = extract_file("input.txt");

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &speed);
		_tok += fetch_int(_tok, &fly_dur);
		_tok += fetch_int(_tok, &rest_dur);

		temp = calc_reindeer_dist(speed, fly_dur, rest_dur, race_dur);
		max = MAX(temp, max);
	)
	answer(d, max);
	return (0);
}