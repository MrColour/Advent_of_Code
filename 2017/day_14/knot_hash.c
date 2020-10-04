/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knot_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:31:13 by home              #+#    #+#             */
/*   Updated: 2020/10/03 21:34:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	convert_ascii(int *dst, char *str)
{
	int	i = 0;
	while (str[i] != '\0') { dst[i] = str[i]; i++; }
	return (i);
}

void	append_len(int *dst, int start, int *suffix, int size)
{
	int		i = 0;
	while (i < size) { dst[i + start] = suffix[i]; i++; }
}

void	knot_round(int len, int curr, int *list)
{
	int	i;
	int	stop;

	int	size = 256;

	int	top;
	int	bottom;

	bottom = curr;
	top = curr + len - 1;

	i = 0;
	stop = len / 2;
	while (i < stop)
	{
		// printf("INT: %d and %d\n", list[top % size], list[bottom % size]);
		SWAP(list[top % size], list[bottom % size], int)
		bottom++;
		top--;
		if (top < 0)
			top = size - 1;
		i++;
	}
}

void	dense_hash(int *dense_dst, int *list)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		j = 1;
		dense_dst[i] = list[i * 16];
		while (j < 16)
		{
			dense_dst[i] ^= list[i * 16 + j];
			j++;
		}
		i++;
	}
}

char	*knot_hash(char *str_file)
{
	int		*new_len;
	int		size;
	int		at;
	int		suffix_len[] = {17, 31, 73, 47, 23};

	size = strlen(str_file) + sizeof(suffix_len) / 4;
	new_len = calloc((size), sizeof(*new_len));

	at = convert_ascii(new_len, str_file);
	append_len(new_len, at, suffix_len, sizeof(suffix_len) / 4);

	int		i;
	int		curr_pos;
	int		skip;
	int		round;
	int		len;
	int		list[256];

	i = 0;
	while (i < (int)(sizeof(list) / 4))
	{
		list[i] = i;
		i++;
	}

	skip = 0;
	curr_pos = 0;
	round = 0;
	while (round < 64)
	{
		i = 0;
		while (i < size)
		{
			len = new_len[i];
			knot_round(len, curr_pos, list);
			curr_pos += len + skip;
			curr_pos %= 256;
			skip++;
			i++;
		}
		round++;
	}

	int		dense_dst[16];
	char	*hash;

	dense_hash(dense_dst, list);
	hash = calloc(33, sizeof(*hash));

	i = 0;
	while (i < 16)
	{
		sprintf(&hash[i * 2], "%0.2x", dense_dst[i]);
		i++;
	}
	return (hash);
}