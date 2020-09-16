/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_05_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:40:12 by home              #+#    #+#             */
/*   Updated: 2020/09/16 01:12:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#include "md5.h"

int		main(void)
{
	int			i;
	int			l;
	char		*input;
	char		*hash;
	MD5_CTX		cxt;
	unsigned char		result[50];
	char				pass[8] = { 0 };

	i = 1;
	l = 0;
	input = strdup("abbhdwsy");
	while (l < 8)
	{
		asprintf(&hash, "%s%d", input, i);

		MD5_Init(&cxt);
		MD5_Update(&cxt, hash, strlen(hash));
		MD5_Final(result, &cxt);

		if (result[0] == 0 && result[1] == 0 && (result[2] & 0xF0) == 0)
		{
			if (result[2] <= 7 && pass[result[2]] == 0)
			{
				// printf("%d and %x\n", result[2], (result[3] & 0xF0) >> 4);
				pass[result[2]] = HEX[(result[3] & 0xF0) >> 4];
				l++;
			}
		}
		free(hash);
		i++;
	}
	printf("%s\n", pass);
	return (0);
}
