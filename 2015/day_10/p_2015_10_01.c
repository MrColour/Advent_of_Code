/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_10_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:37:24 by home              #+#    #+#             */
/*   Updated: 2020/09/04 15:51:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*next_sequence(char *str)
{
	int		i;
	char	digit;
	int		digit_count;
	char	*result;
	size_t	size;

	FILE	*stream;

	i = 0;
	stream = open_memstream(&result, &size);

	while (str[i] != '\0')
	{
		digit = str[i];
		digit_count = 1;
		while (str[i] != '\0' && str[i + 1] == digit)
		{
			digit_count++;
			i++;
		}
		fprintf(stream, "%d%c", digit_count, digit);
		i++;
	}
	fclose(stream);
	return (result);
}

int	main(void)
{
	int		i;
	char	*input;
	char	*next;

	i = 0;
	next = NULL;
	input = strdup("1113122113");
	while (i < 40)
	{
		next = next_sequence(input);
		// printf("[%s]\n", next);

		free(input);
		input = next;
		i++;
	}
	printf("Result: %lu\n", strlen(input));
	return (0);
}