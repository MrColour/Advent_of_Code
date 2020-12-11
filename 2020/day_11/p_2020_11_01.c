/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_11_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/10 22:48:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		occupied(char **read, int x, int y, int len, int size)
{
	int count = 0;
	int i = y - 1;

	while (i < y + 2)
	{
		if (i >= 0 && i <= len)
		{
			int j = x - 1;
			while (j < x + 2)
			{
				if (j >= 0 && j < size && read[i][j] == '#')
					count++;
				j++;
			}
		}
		i++;
	}
	return (count);
}

char	res(char **read, int x, int y, int len, int size)
{
	if (read[y][x] == 'L')
	{
		if (occupied(read, x, y, len, size) == 0)
			return ('#');
	}
	else if (read[y][x] == '#')
	{
		if (occupied(read, x, y, len, size) >= 5) //counts itself, hence >= 5
			return ('L');
	}
	else if (read[y][x] == '.')
		return ('.');

	return (read[y][x]);
}

void	update(char **from, char **to, int len, int size)
{
	int i = 0;
	int j;

	while (i < len)
	{
		j = 0;
		while (j < size)
		{
			to[i][j] = res(from, j, i, len, size);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	int		i;
	int		len;
	char	*str_file;
	char	**lines;
	char	**buffer;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(lines, str_file, len)

	i = 0;
	buffer = calloc(len, sizeof(*buffer));
	while (i < len)
	{
		buffer[i] = strdup(lines[i]);
		i++;
	}

	int stop = 0;
	char **dest = lines;
	char **to = lines;

	dest = lines;
	while (stop < 1000)
	{
		if (dest == lines)
		{
			to = lines;
			dest = buffer;
		}
		else
		{
			to = buffer;
			dest = lines;
		}

		update(dest, to, len - 1, strlen(lines[0]));

		stop++;
	}

	long long seats = 0;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		// printf("%s\n", to[i]);
		while (j < (int)strlen(lines[i]))
		{
			if (lines[i][j] == '#')
				seats++;
			j++;
		}
		i++;
	}

	printf("%lld\n", seats);
	return (0);
}
