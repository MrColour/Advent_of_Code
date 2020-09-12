/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_13_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 00:00:35 by home              #+#    #+#             */
/*   Updated: 2020/09/11 20:30:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

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

int		calc_hap(int *seat_order, int size, int seek, int **happiness)
{
	int	i;
	int	from, to;

	if (seek == 0)
		return (0);

	i = 0;
	while (i < size)
	{
		if (seat_order[i] == seek)
			from = i;
		if (seat_order[i] == seek + 1)
			to = i;
		if (seek == size && seat_order[i] == 1)
			to = i;
		i++;
	}

	// if (from == size)
	// 	from = 0;
	// if (to == size)
	// 	to = 0;

	// if (to == 0)
	// 	to++;

	int		a;
	int		b;

	a = happiness[from][to];
	b = happiness[to][from];

	if (from < to)
	{
		a = happiness[from][to - 1];
		b = happiness[to][from];
	}

	if (from + 1 == size)
	{
		b = happiness[to][from - 1];
	}

	// printf("%d %d %d\n", from, to, seek);
	// printf("Seats %d %d chaning %d and %d\n", from, to, a, b);
	return (a + b);
}

int		print_seats(int	*seat_order, int size, int **happiness, int s)
{
	int i;
	int n;

	int fi;
	int ti;

	int total;

	i = 0;
	total = 0;
	while (i < size)
	{

		if (s == 1)
		{
		if (seat_order[i] == 1)
			printf("Alice");
		if (seat_order[i] == 2)
			printf("Bob");
		if (seat_order[i] == 3)
			printf("Carol");
		if (seat_order[i] == 4)
			printf("David");
		if (seat_order[i] == 5)
			printf("Eric");
		if (seat_order[i] == 6)
			printf("Frank");
		if (seat_order[i] == 7)
			printf("George");
		if (seat_order[i] == 8)
			printf("Mallory");
		if (seat_order[i] == 9)
			printf("Me");
		}

		n = i + 1;
		if (i + 1 == size)
			n = 0;

		int a;
		int b;

		fi = seat_order[i] - 1;
		ti = seat_order[n] - 1;

		a = 0;
		b = 0;

		a = happiness[fi][ti];
		b = happiness[ti][fi - 1];
		if (fi < ti)
		{
			a = happiness[fi][ti - 1];
			b = happiness[ti][fi];
		}

		if (fi + 1 == size)
		{
			b = happiness[ti][fi - 1];
		}
		// {
		// }

		if (s == 1)
			printf(" %d to %d ", a, b);
		total += (a + b);
		i++;
	}
	if (s == 1)
		printf("ENDING %d\n", total);
	// printf("\n");
	return (total);
}

void	depth_first_permute(int seated, int limit, bool *seated_list, int *seat_order, int *max_hap, int **happiness, int *dst)
{
	int		i;
	int		new_hap;

	if (seated == limit)
	{
		new_hap = print_seats(seat_order, limit, happiness, 0);
		if (new_hap > *max_hap)
		{
			// printf("%d %d %d %d %d %d %d %d\n", seat_order[0], seat_order[1], seat_order[2], seat_order[3], seat_order[4], seat_order[5], seat_order[6], seat_order[7]);

			print_seats(seat_order, limit, happiness, 1);

			*max_hap = new_hap;
			// memcpy(dst, seat_order, sizeof(*dst) * limit);
			// printf("HAP: %d\n", curr_hap);
		}
		return ; // Possible route, and update to max_hap.
	}

	i = 0;
	while (i < limit)
	{
		if (seated_list[i] == false)
		{
			seated_list[i] = true;
			seat_order[i] = seated + 1;

			depth_first_permute(seated + 1, limit, seated_list, seat_order, max_hap, happiness, dst);

			seated_list[i] = false;
			seat_order[i] = 0;
		}
		i++;
	}
}

int		main(void)
{
	int		row;
	int		col;
	int		attendees;
	char	*str_file;
	char	*s_tok;
	int		**happiness;

	str_file = extract_file("input.txt");

	row = 0;
	attendees = 8;
	s_tok = str_file;
	happiness = calloc(attendees + 1, sizeof(*happiness));

	while (row < attendees)
	{
		col = 0;
		happiness[row] = calloc(attendees + 1, sizeof(**happiness));
		while (col < attendees - 1)
		{
			s_tok = strpbrk(s_tok, "1234567890-");
			happiness[row][col] = atoi(s_tok);

			if (s_tok[-2] == 'e')
				happiness[row][col] *= -1;

			// printf("%d\n", happiness[row][col]);

			s_tok += strspn(s_tok, "1234567890-");
			col++;
		}
		row++;
	}
	happiness[row] = calloc(attendees + 1, sizeof(**happiness));

	int		max_happiness;
	int		*visit_order;
	int		*optimal_order;
	bool	*visited_list;

	max_happiness = INT32_MIN;
	visit_order = calloc(attendees + 1, sizeof(*visit_order));
	visited_list = calloc(attendees + 1, sizeof(*visited_list));
	optimal_order = calloc(attendees + 1, sizeof(*optimal_order));
	depth_first_permute(0, attendees + 1, visited_list, visit_order, &max_happiness, happiness, optimal_order);

	printf("RESULT: %d\n", max_happiness);

	return (0);
}