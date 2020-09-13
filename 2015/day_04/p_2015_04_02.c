/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_04_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 03:38:36 by home              #+#    #+#             */
/*   Updated: 2020/09/13 04:42:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "md5.h"

int	main(void)
{
	int			i;
	char		*input;
	char		*hash;
	MD5_CTX		cxt;
	unsigned char		result[50];

	i = 1;
	input = strdup("ckczppom");
	while (1)
	{
		asprintf(&hash, "%s%d", input, i);

		MD5_Init(&cxt);
		MD5_Update(&cxt, hash, strlen(hash));
		MD5_Final(result, &cxt);

		if (result[0] == 0 && result[1] == 0 && result[2] == 0)
			break ;
		free(hash);
		i++;
	}
	printf("Result: %d\n", i);
	return (0);
}