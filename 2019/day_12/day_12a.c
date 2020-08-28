/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_12a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:20:23 by kmira             #+#    #+#             */
/*   Updated: 2019/12/16 22:51:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../color.h"

#define X 0
#define Y 1
#define Z 2

#define IO 0
#define EUROPA 1
#define GANYMEDE 2
#define CALLISTO 3

#define END_OF_ARRAY 0

#define END_OF_SIMULATION 1000

typedef	struct	s_point
{
	int	val[3];
}				t_point;

typedef struct	s_moon
{
	t_point	pos;
	t_point	vel;
	int		null;

}				t_moon;

// <x=5, y=-1, z=5>
// <x=0, y=-14, z=2>
// <x=16, y=4, z=0>
// <x=18, y=1, z=16>

t_moon	create_moon(int x, int y, int z)
{
	t_moon result;
	result.pos.val[X] = x;
	result.pos.val[Y] = y;
	result.pos.val[Z] = z;

	result.vel.val[X] = 0;
	result.vel.val[Y] = 0;
	result.vel.val[Z] = 0;

	result.null = 0;
	return (result);
}

int	main(void)
{
	long long	time_step;
	int			collison;
	t_moon		moons[5];

	moons[IO] = create_moon(5, -1, 5);
	moons[EUROPA] = create_moon(0, -14, 2);
	moons[GANYMEDE] = create_moon(16, 4, 0);
	moons[CALLISTO] = create_moon(18, 1, 16);

	moons[4].null = 1;

	int		i;
	int		j;
	int		k;

	time_step = 0;
	collison = 0;
	printf(BOLDPURPLE"MACHINE IS STARTING UP\n"COLOR_RESET);
	while (1)
	{
		printf(BOLDCYAN"After %lld steps:\n"COLOR_RESET, time_step);
		i = 0;
		while (moons[i].null != 1)
		{
			printf("pos=<x=%3d, y=%3d, z=%3d>, vel=<x=%3d, y=%3d, z=%3d>\n",
			moons[i].pos.val[X], moons[i].pos.val[Y], moons[i].pos.val[Z],
			moons[i].vel.val[X], moons[i].vel.val[Y], moons[i].vel.val[Z]);
			i++;
		}
		printf("\n");

		i = 0;
		while (moons[i].null != 1)
		{
			j = 0;
			while (moons[j].null != 1)
			{
				if (i != j)
				{
					k = 0;
					while (k <= Z)
					{
						if (moons[i].pos.val[k] > moons[j].pos.val[k])
							moons[i].vel.val[k]--;
						else if (moons[i].pos.val[k] < moons[j].pos.val[k])
							moons[i].vel.val[k]++;
						k++;
					}
				}
				j++;
			}
			i++;
		}

		i = 0;
		while (moons[i].null != 1)
		{
			k = 0;
			while (k <= Z)
			{
				moons[i].pos.val[k] += moons[i].vel.val[k];
				k++;
			}
			i++;
		}

		time_step++;
	}
	printf("TIMESTAMP: %lld\n", time_step);

	int	total_energy;
	int	curr_kin;
	int	curr_pot;

	total_energy = 0;
	i = 0;
	while (moons[i].null != 1)
	{
		k = 0;
		curr_pot = 0;
		curr_kin = 0;
		while (k <= Z)
		{
			if (moons[i].pos.val[k] < 0)
				moons[i].pos.val[k] *= -1;
			if (moons[i].vel.val[k] < 0)
				moons[i].vel.val[k] *= -1;
			curr_pot += moons[i].pos.val[k];
			curr_kin += moons[i].vel.val[k];
			k++;
		}
		total_energy += (curr_kin * curr_pot);
		i++;
	}
	printf(BOLDGREEN"RESULT: %d\n"COLOR_RESET, total_energy);
	return (0);
}
