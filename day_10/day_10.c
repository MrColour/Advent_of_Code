/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:24:59 by kmira             #+#    #+#             */
/*   Updated: 2019/12/10 21:40:39 by kmira            ###   ########.fr       */
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
	int	used;
}				t_slope;

void	make_slope(t_point base, t_point asteroid)
{
	t_slope	result;
	int	rise;
	int	run;

	run = base.y - asteroid.y;
	rise = base.x - asteroid.x;

	result.pos = -1;
	if (base.y > asteroid.y)
		result.pos = 1;
	else if (base.y == asteroid.y && base.x > asteroid.x)
		result.pos = 1;
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

	int	iter;
	at = 0;
	while (asteroid[at].used == 1)
	{
		iter = 0;
		while (asteroid[iter].used == 1)
		{
			if (iter != at)
				make_slope(asteroid[at], asteroid[iter]);
			iter++;
		}
		at++;
	}

	(void)asteroid;
	return (0);
}
