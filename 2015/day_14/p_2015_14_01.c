/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_14_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:30:05 by home              #+#    #+#             */
/*   Updated: 2020/09/05 00:23:13 by home             ###   ########.fr       */
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
	char	*ptr;
	int		race_dur;
	int		speed, fly_dur, rest_dur;

	int		max;
	int		temp;

	race_dur = 2503;
	str_file = extract_file("input.txt");
	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		// printf("STR: [ %s ]\n", str_file);

		ptr = strpbrk(str_file, "1234567890-");
		speed = atoi(ptr);
		ptr += strspn(ptr, "1234567890-");

		ptr = strpbrk(ptr, "1234567890-");
		fly_dur = atoi(ptr);
		ptr += strspn(ptr, "1234567890-");

		ptr = strpbrk(ptr, "1234567890-");
		rest_dur = atoi(ptr);

		temp = calc_reindeer_dist(speed, fly_dur, rest_dur, race_dur);
		if (temp > max)
			max = temp;

		// printf("%d for %d and %d\n\n", speed, fly_dur, rest_dur);
		// printf("End: %d\n", temp);
		str_file = strtok(NULL, "\n");
	}
	printf("Result: %d\n", max);
	return (0);
}