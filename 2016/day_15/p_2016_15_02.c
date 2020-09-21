/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_15_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:06:42 by home              #+#    #+#             */
/*   Updated: 2020/09/21 03:40:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct	s_disk
{
	int			max;
	int			pos;
}				t_disk;

int		main(void)
{
	int		i;
	int		new_lines;
	char	*str_file;
	char	*s_tok;

	t_disk	*disks;

	str_file = extract_file("input2.txt");
	new_lines = count_occur("\n", str_file);

	i = 0;
	s_tok = strtok(str_file, "\n");
	disks = calloc(new_lines, sizeof(*disks));
	while (s_tok != NULL)
	{
		s_tok += skip_space(s_tok, 2);

		s_tok += fetch_int(s_tok, &(disks[i].max));

		s_tok += fetch_int(s_tok, &(disks[i].pos));
		s_tok += fetch_int(s_tok, &(disks[i].pos));

		disks[i].pos += i + 1;
		disks[i].pos %= disks[i].max;

		s_tok = strtok(NULL, "\n");
		i++;
	}

	int	time;
	int	checksum;

	time = 0;
	while (1)
	{
		i = 0;
		checksum = 0;
		while (i < new_lines)
		{
			if (disks[i].pos == disks[i].max)
				disks[i].pos = 0;

			checksum += disks[i].pos;

			disks[i].pos += 1;

			i++;
		}

		if (checksum == 0)
			break ;

		time++;
	}
	printf("RESULT: %d\n", time);
	return (0);
}
