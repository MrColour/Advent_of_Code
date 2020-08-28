/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_12b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:20:23 by kmira             #+#    #+#             */
/*   Updated: 2019/12/17 02:39:41 by kmira            ###   ########.fr       */
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

#define X0 -8
#define X1 5
#define X2 2
#define X3 9

#define Y0 -10
#define Y1 5
#define Y2 -7
#define Y3 -8

#define Z0 0
#define Z1 10
#define Z2 3
#define Z3 -3


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
	t_moon		moons[5];

	moons[IO] = create_moon(X0, Y0, Z0);
	moons[EUROPA] = create_moon(X1, Y1, Z1);
	moons[GANYMEDE] = create_moon(X2, Y2, Z2);
	moons[CALLISTO] = create_moon(X3, Y3, Z3);

	moons[4].null = 1;

	int		i;
	int		j;

	long long	time_x;
	long long	time_y;
	long long	time_z;
	int toggle = 0;

	printf(BOLDPURPLE"MACHINE IS STARTING UP\n"COLOR_RESET);
	time_step = 0;
	while (1)
	{
		i = 0;
		while (moons[i].null != 1)
		{
			j = i + 1;
			while (moons[j].null != 1)
			{
				if (moons[i].pos.val[X] > moons[j].pos.val[X])
				{
					moons[i].vel.val[X]--;
					moons[j].vel.val[X]++;
				}
				else if (moons[i].pos.val[X] < moons[j].pos.val[X])
				{
					moons[i].vel.val[X]++;
					moons[j].vel.val[X]--;
				}
				j++;
			}
			i++;
		}

		moons[0].pos.val[X] += moons[0].vel.val[X];
		moons[1].pos.val[X] += moons[1].vel.val[X];
		moons[2].pos.val[X] += moons[2].vel.val[X];
		moons[3].pos.val[X] += moons[3].vel.val[X];

		if (moons[0].pos.val[X] == X0 && moons[0].vel.val[X] == 0)
		{
			if (moons[1].pos.val[X] == X1 &&
				moons[2].pos.val[X] == X2 &&
				moons[3].pos.val[X] == X3 &&
				moons[1].vel.val[X] == 0 &&
				moons[2].vel.val[X] == 0 &&
				moons[3].vel.val[X] == 0 )
				{
					printf("CYCLE: %lld\n", time_step);
					if (toggle == 8)
						break ;
					toggle++;
				}
		}
		time_step++;
	}
	time_x = time_step;
	printf("TIMESTAMP: %lld\n", time_step);

		time_step = 0;
		toggle = 0;
	while (1)
	{
		i = 0;
		while (moons[i].null != 1)
		{
			j = i + 1;
			while (moons[j].null != 1)
			{
				if (moons[i].pos.val[Y] > moons[j].pos.val[Y])
				{
					moons[i].vel.val[Y]--;
					moons[j].vel.val[Y]++;
				}
				else if (moons[i].pos.val[Y] < moons[j].pos.val[Y])
				{
					moons[i].vel.val[Y]++;
					moons[j].vel.val[Y]--;
				}
				j++;
			}
			i++;
		}

		moons[0].pos.val[Y] += moons[0].vel.val[Y];
		moons[1].pos.val[Y] += moons[1].vel.val[Y];
		moons[2].pos.val[Y] += moons[2].vel.val[Y];
		moons[3].pos.val[Y] += moons[3].vel.val[Y];

		if (moons[0].pos.val[Y] == Y0 && moons[0].vel.val[Y] == 0)
		{
			if (moons[1].pos.val[Y] == Y1 &&
				moons[2].pos.val[Y] == Y2 &&
				moons[3].pos.val[Y] == Y3 &&
				moons[1].vel.val[Y] == 0 &&
				moons[2].vel.val[Y] == 0 &&
				moons[3].vel.val[Y] == 0 )
				{
					printf("CYCLE: %lld\n", time_step);
					if (toggle == 8)
						break ;
					toggle++;
				}
		}
		time_step++;
	}
	time_x = time_step;
	printf("TIMESTAMP: %lld\n", time_step);

	time_step = 0;
	toggle = 0;
	while (1)
	{
		i = 0;
		while (moons[i].null != 1)
		{
			j = i + 1;
			while (moons[j].null != 1)
			{
				if (moons[i].pos.val[Z] > moons[j].pos.val[Z])
				{
					moons[i].vel.val[Z]--;
					moons[j].vel.val[Z]++;
				}
				else if (moons[i].pos.val[Z] < moons[j].pos.val[Z])
				{
					moons[i].vel.val[Z]++;
					moons[j].vel.val[Z]--;
				}
				j++;
			}
			i++;
		}

		moons[0].pos.val[Z] += moons[0].vel.val[Z];
		moons[1].pos.val[Z] += moons[1].vel.val[Z];
		moons[2].pos.val[Z] += moons[2].vel.val[Z];
		moons[3].pos.val[Z] += moons[3].vel.val[Z];

		if (moons[0].pos.val[Z] == Z0 && moons[0].vel.val[Z] == 0)
		{
			if (moons[1].pos.val[Z] == Z1 &&
				moons[2].pos.val[Z] == Z2 &&
				moons[3].pos.val[Z] == Z3 &&
				moons[1].vel.val[Z] == 0 &&
				moons[2].vel.val[Z] == 0 &&
				moons[3].vel.val[Z] == 0 )
				{
					printf("CYCLE: %lld\n", time_step);
					if (toggle == 8)
						break ;
					toggle++;
				}
		}
		time_step++;
	}
	time_x = time_step;

	printf("TIMESTAMP: %lld\n", time_step);

	long long	attempt;

	attempt = 2;
	while (attempt < time_x && attempt < time_y && attempt < time_z)
	{
		// printf("ATTEMPT: %lld\n", attempt);
		if (time_x % attempt == 0 && time_y % attempt == 0)
		{
			printf("Here\n");
			time_x = time_x / attempt;
			time_y = time_y / attempt;
			attempt = 1;
		}
		else if (time_x % attempt == 0 && time_z % attempt == 0)
		{
			printf("Here\n");
			time_x = time_x / attempt;
			time_z = time_z / attempt;
			attempt = 1;
		}
		else if (time_y % attempt == 0 && time_z % attempt == 0)
		{
			printf("Here\n");
			time_y = time_y / attempt;
			time_z = time_z / attempt;
			attempt = 1;
		}
		attempt++;
	}

	time_x = 2028 / 2;
	time_y = 5898 / 2;
	time_z = 4702 / 2;
	// long long result = time_x * time_y * time_z;
	printf("X: %lld, Y: %lld, Z: %lld\n", time_x, time_y, time_z);
	printf("Result: %lld\n", time_x * time_y * time_z);

	attempt = 2;
	printf(BOLDLIGHT_PURPLE"This is time_x\n"COLOR_RESET);
	while (attempt < time_x)
	{
		if (time_x % attempt == 0)
		{
			printf("Composed from: %lld\n", attempt);
			time_x = time_x / attempt;
			attempt = 1;
		}
		attempt++;
	}
	printf(BOLDLIGHT_PURPLE"This is time_y\n"COLOR_RESET);

	attempt = 2;
	while (attempt < time_y)
	{
		if (time_y % attempt == 0)
		{
			printf("Composed from: %lld\n", attempt);
			time_y = time_y / attempt;
			attempt = 1;
		}
		attempt++;
	}

	attempt = 2;
	printf(BOLDLIGHT_PURPLE"This is time_z\n"COLOR_RESET);
	while (attempt < time_z)
	{
		if (time_z % attempt == 0)
		{
			printf("Composed from: %lld\n", attempt);
			time_z = time_z / attempt;
			attempt = 1;
		}
		attempt++;
	}

	// attempt = 2;
	// while (attempt <= result)
	// {
	// 	if (result % attempt == 0)
	// 	{
	// 		printf("Composed from: %lld\n", attempt);
	// 		result = result / attempt;
	// 		attempt = 1;
	// 	}
	// 	attempt++;
	// }

	printf("X: %lld, Y: %lld, Z: %lld\n", time_x, time_y, time_z);
	printf("Result: %lld\n", time_x * time_y * time_z);

	return (0);
}

