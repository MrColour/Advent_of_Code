/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_10b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:24:59 by kmira             #+#    #+#             */
/*   Updated: 2019/12/15 22:17:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define BUFF_SIZE 1000

#define CAN_BE_VAPORIZED 1
#define HAS_BEEN_VAPORIZED -1
#define END_OF_ARRAY 0

typedef	struct	s_point
{
	int	x;
	int	y;
	int	used;
}				t_point;

//A slope is the smallest co prime of x and y.
typedef	struct	s_slope
{
	int	x;
	int	y;
	int	pos;	//An astriod can have 2 seeking for each line. This is determined on which side it is.
	t_point	base;
	t_point	point;
	double	angle;
	double	distance;
	int	used;
}				t_slope;

void	make_slope(t_point base, t_point asteroid, t_slope *result)
{
	int	run;
	int	rise;
	int	attempt;

	run = asteroid.x - base.x;
	rise = asteroid.y - base.y;

	result->pos = -1;
	if (base.y < asteroid.y)
		result->pos = 1;
	else if (base.y == asteroid.y && base.x < asteroid.x)
		result->pos = 1;
	/*
	** Below part with atan2 (man atan2, )is a bit tricky. atan gets the angle from the x-pos axis leaning towards the y-pos axis.
	** We however want from the y-pos axis to the x-pos axis
	** However! Our grid is also flipped! not cartesian... All this combined make it take (x_delta, y_delta * -1)
	** instead of the usual (y_delta, x_delta).
	**
	** Next since atan2 gives you negative numbers once you turned 180 degrees, pi rads. Since it is negative
	** the angle increase is (pi + angle), this is then added by another pi since it is 180 degrees, pi rads.
	**
	** Further down however we need to keep track of which side of the line the number is at (pos), make sure
	** it isn't zero to avoid division or mod by zero. Then find the LCD (lowest common denominator) etc...
	** Overall it was fun to code, finally got some use for that trig which I learned, although even then it is tricky
	** because of the precision loss and how math works on floating point numbers.
	*/
	result->angle = atan2(run, -1 * rise);
	if (result->angle < 0)
		result->angle += 2 * M_PI;
	if (rise == 0 || run == 0)
	{
		if (rise == 0)
		{
			rise = 0;
			run = result->pos;
		}
		if (run == 0)
		{
			run = 0;
			rise = result->pos;
		}
	}
	int	run_sign;
	int	rise_sign;

	run_sign = 1;
	rise_sign = 1;
	attempt = 2;
	if (rise < 0)
	{
		rise *= -1;
		rise_sign = -1;
	}
	if (run < 0)
	{
		run *= -1;
		run_sign = -1;
	}
	while (attempt <= rise && attempt <= run)
	{
		if (run % attempt == 0 && rise % attempt == 0)
		{
			run = run / attempt;
			rise = rise / attempt;
			attempt = 1;
		}
		attempt++;
	}
	if (run_sign == rise_sign)
	{
		run_sign = 1;
		rise_sign = 1;
	}
	result->x = run * run_sign;
	result->y = rise * rise_sign;
	result->used = 1;
	result->base = base;
	result->point = asteroid;
	result->distance = sqrt( pow((base.x - asteroid.x), 2) + pow((base.y - asteroid.y), 2));
}

int		main(void)
{
	int		fd;
	int		line_size;
	t_point	asteroid[1000];
	t_slope	slopes[1000];
	char	buff[BUFF_SIZE];

	int	y;
	int	x;
	int	at;

	y = 0;
	at = 0;
	fd = open("day_10.txt", O_RDONLY);
	read(fd, buff, 100);
	line_size = strchr(buff, '\n') - buff;
	close(fd);
	bzero(buff, sizeof(buff));
	bzero(asteroid, sizeof(asteroid));
	fd = open("day_10.txt", O_RDONLY);
	while (read(fd, buff, line_size))
	{
		printf("LINE: %s\n", buff);
		x = 0;
		while (buff[x] != '\0')
		{
			if (buff[x] == '#')
			{
				asteroid[at].x = x;
				asteroid[at].y = y;
				asteroid[at].used = 1;
				at++;
			}
			x++;
		}
		y++;
		read(fd, buff, 1);
		bzero(buff, sizeof(buff));
	}

	int	max;
	int	iter;
	int	slope_i;
	int	s_iter;
	int	curr_max;

	at = 0;
	max = 0;
	slope_i = 0;
	/*
	** This bad boy down here makes a slope from each asteroid to every other and then does a LCD slope (rise over run) compare
	** Keep in mind that a base has a foward intersection and a 'backward' intersection.
	** From the last puzzle the magic number (max intersections) is 263, that is our break point.
	*/
	while (asteroid[at].used == 1)
	{
		iter = 0;
		slope_i = 0;
		while (asteroid[iter].used == 1)
		{
			if (iter != at)
			{
				make_slope(asteroid[at], asteroid[iter], &slopes[slope_i]);
				slope_i++;
			}
			iter++;
		}
		iter = 0;
		while (slopes[iter].used != 0)
		{
			s_iter = iter + 1;
			while (slopes[s_iter].used != 0)
			{
				if (slopes[s_iter].used == 1)
					if (slopes[iter].x == slopes[s_iter].x && slopes[iter].y == slopes[s_iter].y && slopes[iter].pos == slopes[s_iter].pos)
					{
						slopes[iter].used = 2;
						slopes[s_iter].used = -1;
					}
				s_iter++;
			}
			iter++;
		}
		curr_max = 0;
		iter = 0;
		while (slopes[iter].used != 0)
		{
			if (slopes[iter].used == 1 || slopes[iter].used == 2)
				curr_max++;
			iter++;
		}
		if (curr_max == 263)
			break ;
		bzero(slopes, sizeof(slopes));
		at++;
	}

	t_slope		tmp;

	s_iter = 0;
	iter = 0;

	/*
	** Simple bubble sort that sorts by angle and if the angle is the same then attempts to sort
	** by distance.
	*/
	while (slopes[iter].used != 0)
	{
		s_iter = 0;
		while (slopes[s_iter + 1].used != 0)
		{
			if (slopes[s_iter].angle > slopes[s_iter + 1].angle)
			{
				tmp = slopes[s_iter];
				slopes[s_iter] = slopes[s_iter + 1];
				slopes[s_iter + 1] = tmp;
			}
			else if (slopes[s_iter].angle == slopes[s_iter + 1].angle) //There should probably be a delta here instead of a test of equality
			{
				if (slopes[s_iter].distance > slopes[s_iter + 1].distance)
				{
					tmp = slopes[s_iter];
					slopes[s_iter] = slopes[s_iter + 1];
					slopes[s_iter + 1] = tmp;
				}
			}
			s_iter++;
		}
		iter++;
	}

	int		vapor_count;
	double	d_curr_angle;

	iter = 0;
	while (slopes[iter].used != END_OF_ARRAY)
	{
		slopes[iter].used = CAN_BE_VAPORIZED;
		iter++;
	}

	iter = 0;
	vapor_count = 1;
	d_curr_angle = -1.0;
	while (vapor_count != 200)
	{
		while (slopes[iter].used == HAS_BEEN_VAPORIZED || slopes[iter].angle == d_curr_angle)
			iter++;
		if (slopes[iter].used == END_OF_ARRAY)
		{
			iter = 0;
			continue ;
		}
		else if (slopes[iter].used == CAN_BE_VAPORIZED)
		{
			slopes[iter].used = -1; //vaporized!
			d_curr_angle = slopes[iter].angle;
			iter++;
		}
		vapor_count++;
	}
	printf("(%d, %d)\n", slopes[iter].point.x, slopes[iter].point.y);
	return (0);
}
