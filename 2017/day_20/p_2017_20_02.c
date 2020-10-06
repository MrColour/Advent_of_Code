/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_20_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:48:17 by home              #+#    #+#             */
/*   Updated: 2020/10/06 05:18:08 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

# define A_LONG_TIME (10000)

typedef struct	s_particle
{
	int			x;
	int			y;
	int			z;

	int			vx;
	int			vy;
	int			vz;

	int			ax;
	int			ay;
	int			az;

	int			time;
	bool		destroyed;
}				t_particle;

int		pos_cmp(const void *ptr_a, const void *ptr_b)
{
	t_particle *a;
	t_particle *b;

	a = (t_particle *)ptr_a;
	b = (t_particle *)ptr_b;

	if (a->destroyed == true)
		return (-1);
	else if (b->destroyed == true)
		return (1);

	if (a->x > b->x)
		return(1);
	else if (a->x == b->x && a->y > b->y)
		return(1);
	else if (a->x == b->x && a->y == b->y && a->z > b->z)
		return(1);
	else
		return(-1);
}

void	update(t_particle *obj)
{
	if (obj->destroyed == true)
		return ;

	obj->vx += obj->ax;
	obj->vy += obj->ay;
	obj->vz += obj->az;

	obj->x += obj->vx;
	obj->y += obj->vy;
	obj->z += obj->vz;

	obj->time++;
}

int		main(void)
{
	char	*str_file;
	t_particle	*objs;

	int		time;
	int		len;

	str_file = extract_file("input.txt");
	len = count_occur("\n", str_file);

	objs = calloc(len, sizeof(*objs));

	len = 0;
	strtok(str_file, "\n");
	while (str_file != NULL)
	{
		str_file += fetch_int(str_file, &objs[len].x);
		str_file += fetch_int(str_file, &objs[len].y);
		str_file += fetch_int(str_file, &objs[len].z);

		str_file += fetch_int(str_file, &objs[len].vx);
		str_file += fetch_int(str_file, &objs[len].vy);
		str_file += fetch_int(str_file, &objs[len].vz);

		str_file += fetch_int(str_file, &objs[len].ax);
		str_file += fetch_int(str_file, &objs[len].ay);
		str_file += fetch_int(str_file, &objs[len].az);
		str_file = strtok(NULL, "\n");
		len++;
	}

	int	i;
	int	result;

	time = 0;
	while (time < A_LONG_TIME)
	{
		i = 0;
		while (i < len)
		{
			update(&objs[i]);
			i++;
		}

		psort(objs, len, sizeof(*objs), pos_cmp);

		i = 0;
		while (i < len - 1)
		{
			if (objs[i].x == objs[i + 1].x && objs[i].y == objs[i + 1].y && objs[i].z == objs[i + 1].z && objs[i].time == objs[i + 1].time)
			{
				objs[i].destroyed = true;
				objs[i + 1].destroyed = true;
			}
			i++;
		}

		time++;
	}

	i = 0;
	result = 0;
	while (i < len)
	{
		if (objs[i].destroyed == false)
			result++;
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}
