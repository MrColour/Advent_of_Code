/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2020_11_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:15 by home              #+#    #+#             */
/*   Updated: 2020/12/10 22:51:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		reach_bounds(char **read, int x, int y, int d_x, int d_y, int len, int size)
{
	x += d_x;
	y += d_y;

	while (bound(0, x, size) && bound(0, y, len) && read[y][x] == '.')
	{
		x += d_x;
		y += d_y;
	}

	if (bound(0, x, size) && bound(0, y, len) && read[y][x] == '#')
		return (1);

	return (0);
}

int		occupied(char **read, int x, int y, int len, int size)
{
	int count = 0;

	count += reach_bounds(read, x, y, 1, 0, len, size);
	count += reach_bounds(read, x, y, -1, 0, len, size);
	count += reach_bounds(read, x, y, 0, 1, len, size);
	count += reach_bounds(read, x, y, 0, -1, len, size);

	count += reach_bounds(read, x, y, -1, -1, len, size);
	count += reach_bounds(read, x, y, 1, 1, len, size);
	count += reach_bounds(read, x, y, -1, 1, len, size);
	count += reach_bounds(read, x, y, 1, -1, len, size);

	return (count);
}

char	res(char **read, int x, int y, int len, int size)
{
	int count;

	if (read[y][x] == 'L')
	{
		// printf("%d\n", occupied(read, x, y, len, size));
		if (occupied(read, x, y, len, size) == 0)
			return ('#');
	}
	else if (read[y][x] == '#')
	{
		if (occupied(read, x, y, len, size) >= 5)
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
		// printf("%d: %s\n", i, to[i]);
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
