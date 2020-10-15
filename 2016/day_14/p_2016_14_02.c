/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_14_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 20:55:48 by home              #+#    #+#             */
/*   Updated: 2020/10/15 01:06:48 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#include "md5.h"

typedef struct	s_hash
{
	int				index;
	unsigned char	hash_byte[16 * 2 + 1];
}				t_hash;

void	hash_to_str(unsigned char *hash, unsigned char *dst)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		dst[i * 2] = HEX[hash[i] >> 4];
		dst[i * 2 + 1] = HEX[hash[i] & 0x0F];
		i++;
	}
}

char	has_n_kind(unsigned char *hash, int n)
{
	int		i;
	int		j;
	char	type;
	bool	found;

	i = 0;
	found = false;
	while (hash[i] != '\0' && found == false)
	{
		j = i + 1;
		type = hash[i];
		while (j < i + n && hash[j] != '\0')
		{
			if (hash[j] != type)
				break ;
			j++;
		}

		if (j - i == n)
			found = true;
		i++;
	}

	if (found == true)
		return (type);
	else
		return (0);
}

void	hash_2016(unsigned char *start)
{
	int		i;
	MD5_CTX				cxt;
	unsigned char		hash[16 + 1];
	unsigned char		hash_byte[16 * 2 + 1];

	i = 0;
	memcpy(hash_byte, start, 33);
	while (i < 2016)
	{
		MD5_Init(&cxt);
		MD5_Update(&cxt, hash_byte, 32);
		MD5_Final(hash, &cxt);

		hash_to_str(hash, hash_byte);

		i++;
	}
	memcpy(start, hash_byte, 33);
}

bool	next_1000_check(unsigned char *try, int index, char *salt, t_hash *sliding_window)
{
	int		i;
	char	type;
	bool	found;

	char				*input;
	MD5_CTX				cxt;
	unsigned char		hash[16 + 1] = { 0 };
	unsigned char		hash_byte[16 * 2 + 1] = { 0 };

	i = index + 1;
	found = false;
	type = has_n_kind(try, 3);
	while (i < index + 1000 && found == false)
	{
		if (sliding_window[i % 1000].index == i)
			memcpy(hash_byte, sliding_window[i % 1000].hash_byte, sizeof(hash_byte));
		else
		{
			asprintf(&input, "%s%d", salt, i);

			MD5_Init(&cxt);
			MD5_Update(&cxt, input, strlen(input));
			MD5_Final(hash, &cxt);
			hash_to_str(hash, hash_byte);

			hash_2016(hash_byte);
			sliding_window[i % 1000].index = i;
			memcpy(sliding_window[i % 1000].hash_byte, hash_byte, sizeof(hash_byte));
		}

		if (has_n_kind(hash_byte, 5) == type)
			found = true;

		i++;
	}
	return (found);
}

int		main(void)
{
	int			i;
	int			max_i;
	int			key_pad_count;

	char				*salt;
	char				*input;
	MD5_CTX				cxt;
	unsigned char		hash[16 + 1] = { 0 };
	unsigned char		hash_byte[16 * 2 + 1] = { 0 };

	t_hash				sliding_window[1000] = { 0 };

	i = 0;
	key_pad_count = 0;
	salt = strdup("qzyelonm");
	while (key_pad_count < 64)
	{
		if (sliding_window[i % 1000].index == i)
			memcpy(hash_byte, sliding_window[i % 1000].hash_byte, sizeof(hash_byte));
		else
		{
			asprintf(&input, "%s%d", salt, i);

			MD5_Init(&cxt);
			MD5_Update(&cxt, input, strlen(input));
			MD5_Final(hash, &cxt);
			hash_to_str(hash, hash_byte);
			hash_2016(hash_byte);
			sliding_window[i % 1000].index = i;
			memcpy(sliding_window[i % 1000].hash_byte, hash_byte, sizeof(hash_byte));
		}

		if (has_n_kind(hash_byte, 3) != 0)
		{
			if (next_1000_check(hash_byte, i, salt, sliding_window))
				key_pad_count++;
		}
		i++;
	}
	answer(d, i - 1);
	return (0);
}