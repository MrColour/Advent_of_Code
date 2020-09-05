/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_14_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:35:52 by home              #+#    #+#             */
/*   Updated: 2020/09/05 02:35:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE (1024)

char	*extract_file(char *file_name)
{
	int		fd;
	int		bytes_read;
	int		size;
	char	*result;

	size = 0;
	result = NULL;
	fd = open(file_name, O_RDONLY);

	bytes_read = 1;
	while (bytes_read != 0)
	{
		result = realloc(result, size + BUFF_SIZE + 1);
		bytes_read = read(fd, &result[size], BUFF_SIZE);
		size += bytes_read;
		result[size] = '\0';
	}
	return (result);
}

typedef	struct	s_reindeer
{
	int			speed;
	int			fly_dur;
	int			rest_dur;

	int			cur_dist;
	int			points;

	int			fly_t_rem;
	int			rest_t_rem;
}				t_reindeer;

int		main(void)
{
	char	*str_file;
	char	*ptr;
	int		i;
	int		reindeer_count;
	t_reindeer	*reindeer_array;

	reindeer_count = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		str_file = strtok(NULL, "\n");
		reindeer_count++;
	}

	i = 0;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");
	reindeer_array = calloc(reindeer_count, sizeof(*reindeer_array));
	while (str_file != NULL)
	{
		ptr = strpbrk(str_file, "1234567890-");
		reindeer_array[i].speed = atoi(ptr);
		ptr += strspn(ptr, "1234567890-");

		ptr = strpbrk(ptr, "1234567890-");
		reindeer_array[i].fly_dur = atoi(ptr);
		ptr += strspn(ptr, "1234567890-");

		ptr = strpbrk(ptr, "1234567890-");
		reindeer_array[i].rest_dur = atoi(ptr);

		reindeer_array[i].fly_t_rem = reindeer_array[i].fly_dur;
		reindeer_array[i].rest_t_rem = reindeer_array[i].rest_dur;

		str_file = strtok(NULL, "\n");
		i++;
	}

	int		race_time;
	int		lead_dis;

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

			if (reindeer_array[i].cur_dist > lead_dis)
				lead_dis = reindeer_array[i].cur_dist;

			i++;
		}

		// printf("LEAD: %d %d\n", reindeer_array[0].cur_dist, reindeer_array[1].cur_dist);
		i = 0;
		while (i < reindeer_count)
		{
			if (reindeer_array[i].cur_dist == lead_dis)
				reindeer_array[i].points++;
			i++;
		}

		race_time--;
	}

	int max_points;

	i = 0;
	max_points = 0;
	while (i < reindeer_count)
	{
		// printf("%d\n", reindeer_array[i].points);
		if (reindeer_array[i].points > max_points)
			max_points = reindeer_array[i].points;
		i++;
	}
	printf("Result: %d\n", max_points);
	return (0);
}