/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_14_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 20:55:48 by home              #+#    #+#             */
/*   Updated: 2020/09/21 01:15:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#include "md5.h"

// typedef struct	s_hash
// {
// 	int				index;
// 	int				type;
// 	char			which;

// 	struct s_hash	*next;
// }				t_hash;

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

// if (next_1000_check(hash, memo, &i, &max_i))
bool	next_1000_check(unsigned char *try, int index, char *salt)
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
		asprintf(&input, "%s%d", salt, i);

		MD5_Init(&cxt);
		MD5_Update(&cxt, input, strlen(input));
		MD5_Final(hash, &cxt);

		hash_to_str(hash, hash_byte);

		if (has_n_kind(hash_byte, 5) == type)
		{
			printf("TRY: %s\n5: %s\n", try, hash_byte);
			found = true;
		}

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

	i = 0;
	key_pad_count = 0;
	salt = strdup("qzyelonm");
	// salt = strdup("abc");
	while (key_pad_count < 64)
	{
		asprintf(&input, "%s%d", salt, i);

		MD5_Init(&cxt);
		MD5_Update(&cxt, input, strlen(input));
		MD5_Final(hash, &cxt);

		hash_to_str(hash, hash_byte);

		// printf("I %4i: %s \n", i, hash_byte);

		if (has_n_kind(hash_byte, 3) != 0)
		{
			if (next_1000_check(hash_byte, i, salt))
				key_pad_count++;
		}
		i++;

		free(input);
	}
	printf("RESULT: %d\n", i - 1);
	return (0);
}

