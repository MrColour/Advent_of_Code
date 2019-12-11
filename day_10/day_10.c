/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:24:59 by kmira             #+#    #+#             */
/*   Updated: 2019/12/11 10:58:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 1000

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

	at = 0;
	while (asteroid[at].used == 1)
	{
		printf("COORD: (%3d, %3d) for %d\n", asteroid[at].x, asteroid[at].y, at);
		at++;
	}

	int	max;
	int	iter;
	int	slope_i;
	int	s_iter;
	int	curr_max;

	at = 0;
	max = 0;
	slope_i = 0;
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
			// printf("RISE: %3d RUN: %3d from B: (%d, %d) and A: (%d, %d)\n", slopes[iter].y, slopes[iter].x, slopes[iter].base.x, slopes[iter].base.y, slopes[iter].point.x, slopes[iter].point.y);
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
		bzero(slopes, sizeof(slopes));
		if (curr_max > max)
			max = curr_max;
		at++;
	}

	iter = 0;
	while (slopes[iter].used != 0)
	{
		printf("RUN: %3d RISE: %3d from B: (%d, %d) and A: (%d, %d) POS: %d U:%d\n", slopes[iter].x, slopes[iter].y, slopes[iter].base.x, slopes[iter].base.y, slopes[iter].point.x, slopes[iter].point.y, slopes[iter].pos, slopes[iter].used);
		iter++;
	}

	printf("RESULT: %d\n", max);

	(void)asteroid;
	return (0);
}
