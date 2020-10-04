/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_16_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 23:09:27 by home              #+#    #+#             */
/*   Updated: 2020/10/03 23:58:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	process_line(char *command, char *programs)
{
	int		index1;
	int		index2;
	int		len;
	char	buff[20] = { 0 };

	if (command[0] == 's')
	{
		strcpy(buff, programs);
		fetch_int(command, &index1);

		len = strlen(programs);
		memcpy(&programs[0], &buff[len - index1], index1);
		memcpy(&programs[index1], &buff[0], len - index1);
	}
	else if (command[0] == 'x')
	{
		command += fetch_int(command, &index1);
		command += fetch_int(command, &index2);

		SWAP(programs[index1], programs[index2], char)
	}
	if (command[0] == 'p')
	{
		index1 = strchr(programs, command[1]) - programs;
		index2 = strchr(programs, command[3]) - programs;

		SWAP(programs[index1], programs[index2], char)
	}
}

int		main(void)
{
	char	*str_file;
	char	*programs;
	char	**dance_moves;
	int		length;

	str_file = extract_file("input.txt");
	strchr(str_file, '\n')[0] = '\0';
	STR_SPLIT(dance_moves, str_file, NULL, ",", length)

	programs = strdup(LOW_ALPHA);
	strchr(programs, 'p' + 1)[0] = '\0';

	int		i;
	long long	times;

	times = 0;
	while (times < (1000000000 % 15000)) //See README.md
	{
		i = 0;
		while (dance_moves[i] != NULL)
		{
			// printf("STR: %s\n", dance_moves[i]);
			process_line(dance_moves[i], programs);
			// printf("OUT: %s\n", programs);
			i++;
		}
		if (times % 5000 == 0)
			printf("OUT: %s at %lld\n", programs, times);
		times++;
	}
	printf("RESULT: %s\n", programs);
	return (0);
}
