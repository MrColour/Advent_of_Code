/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:45:51 by kmira             #+#    #+#             */
/*   Updated: 2019/12/11 10:08:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	attempt = 2;
	if (rise < 0)
		rise *= -1;
	if (run < 0)
		run *= -1;
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
	result->x = run;
	result->y = rise;
	result->used = 1;
	result->base = base;
	result->point = asteroid;
}

int		main(void)
{
	t_point	p1;
	t_point	p2;
	t_slope slope;

	p1.x = 0;
	p1.y = 0;

	p2.x = 0;
	p2.y = 4;
	make_slope(p1, p2, &slope);
	printf("RISE: %3d RUN: %3d from B: (%d, %d) and A: (%d, %d) pos %d\n", slope.y, slope.x, slope.base.x, slope.base.y, slope.point.x, slope.point.y, slope.pos);

	t_point	p1a;
	t_point	p2a;
	t_slope slopea;

	p1a.x = 0;
	p1a.y = 0;

	p2a.x = p2.x * -1;
	p2a.y = p2.y * -1;
	make_slope(p1a, p2a, &slopea);
	printf("RISE: %3d RUN: %3d from B: (%d, %d) and A: (%d, %d) pos %d\n", slopea.y, slopea.x, slopea.base.x, slopea.base.y, slopea.point.x, slopea.point.y, slopea.pos);
	return (0);
}
