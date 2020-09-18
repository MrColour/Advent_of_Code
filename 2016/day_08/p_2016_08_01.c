/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 03:41:41 by home              #+#    #+#             */
/*   Updated: 2020/09/17 19:21:55 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	rect_on(char (*screen)[51], int width, int tall)
{
	int		i;
	int		j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < tall)
		{
			screen[i][j] = '#';
			j++;
		}
		i++;
	}
}

void	rotate_row(char (*screen)[51], int which, int amount)
{
	char	buffer[50];

	amount %= 50;
	memcpy(buffer, screen[0], 50);
	// printf("%.50s\n", screen[0]);
	memmove(screen[which], &(buffer[50 - amount]), amount);
	memmove(&(screen[which][amount]), buffer, 50 - amount);
}

void	rotate_col(char (*screen)[51], int which, int amount)
{
	int		i;
	char	buffer[6];
	char	buffer_buff[6];

	i = 0;
	while (i < 6)
	{
		buffer[i] = screen[i][which];
		i++;
	}

	amount %= 5;
	memcpy(buffer_buff, buffer, 6);
	memmove(buffer, &buffer_buff[6 - amount], amount);
	memmove(&buffer[amount], buffer_buff, 6 - amount);

	i = 0;
	while (i < 6)
	{
		screen[i][which] = buffer[i];
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	char	*ptr;
	char	screen[6][51];
	int		a;
	int		b;

	memset(screen, '.', sizeof(screen));
	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");

	while (s_tok != NULL)
	{
		// printf("STR: %s\n", s_tok);
		ptr = s_tok;
		ptr += fetch_int(ptr, &a);
		ptr += fetch_int(ptr, &b);

		// printf("%d", i);
		if (s_tok[1] == 'e')
			rect_on(&(screen[0]), a, b);
		else
		{
			if (s_tok[7] == 'r')
				rotate_row(screen, a, b);
			else
				rotate_col(screen, a, b);
		}
		// printf("\n");
		s_tok = strtok(NULL, "\n");
	}

	int		i;
	int		lights_on;

	i = 0;
	lights_on = 0;
	while (i < 5)
	{
		screen[i][50] = '\0';
		lights_on += count_occur("#", screen[i]);
		printf("%.50s\n", screen[i]);
		i++;
	}
	printf("RESULT: %d\n", lights_on);
	return (0);
}
