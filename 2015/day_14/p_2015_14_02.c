/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_14_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:35:52 by home              #+#    #+#             */
/*   Updated: 2020/10/13 03:18:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct	s_reindeer
{
	int			points; //Using the fact that this is the first item in the struct for a sort search. Beware if moved.

	int			speed;
	int			fly_dur;
	int			rest_dur;

	int			cur_dist;

	int			fly_t_rem;
	int			rest_t_rem;
}				t_reindeer;

int		main(void)
{
	char	*str_file;
	int		reindeer_count;
	t_reindeer	*reindeer_array;

	str_file = extract_file("input.txt");
	reindeer_count = count_occur("\n", str_file);
	reindeer_array = calloc(reindeer_count, sizeof(*reindeer_array));

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &(reindeer_array[_i].speed));
		_tok += fetch_int(_tok, &(reindeer_array[_i].fly_dur));
		_tok += fetch_int(_tok, &(reindeer_array[_i].rest_dur));

		reindeer_array[_i].fly_t_rem = reindeer_array[_i].fly_dur;
		reindeer_array[_i].rest_t_rem = reindeer_array[_i].rest_dur;
	)

	int		i;
	int		lead_dis;
	int		race_time;

	lead_dis = 0;
	race_time = 2503;
	while (race_time > 0)
	{
		i = 0;
		while (i < reindeer_count)
		{
			if (reindeer_array[i].fly_t_rem > 0)
			{
				reindeer_array[i].cur_dist += reindeer_array[i].speed;
				reindeer_array[i].fly_t_rem--;
			}
			else if (reindeer_array[i].rest_t_rem > 1)
				reindeer_array[i].rest_t_rem--;
			else
			{
				reindeer_array[i].rest_t_rem = reindeer_array[i].rest_dur;
				reindeer_array[i].fly_t_rem = reindeer_array[i].fly_dur;
			}

			lead_dis = MAX(reindeer_array[i].cur_dist, lead_dis);

			i++;
		}

		FOR_EACH(_i < reindeer_count,
			if (reindeer_array[_i].cur_dist == lead_dis)
				reindeer_array[_i].points++;
		)

		race_time--;
	}

	int *max_points;

	max_points = last(reindeer_array, reindeer_count, sizeof(*reindeer_array), int_cmp_asc); //Assumes points is first mem of struct

	answer(d, *max_points);
	return (0);
}