/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_12_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:00:17 by home              #+#    #+#             */
/*   Updated: 2020/10/19 20:42:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define OFFSET (10)
#define LEN (150)

char	*new_generation(char *initial_state, char **transforms)
{
	int	i;
	int	j;
	char	*result;

	i = 0;
	result = strdup(initial_state);
	memset(result, '.', strlen(initial_state));
	while (transforms[i] != NULL)
	{
		j = 0;
		while (initial_state[j + 4] != '\0')
		{
			if (strncmp(&initial_state[j], transforms[i], 5) == 0)
				result[j + 2] = strchr(transforms[i], '>')[2];
			j++;
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	char	**transforms;
	char	*initial_state;
	int		len;

	str_file = extract_file("input.txt");
	strrchr(str_file, '\n')[0] = '\0';

	NEWLINE_SPLIT(transforms, str_file, len)
	transforms = &transforms[2];

	initial_state = calloc(LEN + OFFSET, sizeof(*initial_state));
	memset(initial_state, '.', LEN + OFFSET - 1);
	str_file = &strrchr(str_file, ' ')[1];
	memcpy(&initial_state[OFFSET], str_file, strlen(str_file));

	printf(" 0: [%s]\n", initial_state);

	size_t	i;

	i = 1;
	while (i <= 20)
	{
		initial_state = new_generation(initial_state, transforms);
		printf("%2zu: [%s]\n", i, initial_state);
		i++;
	}

	int	result;

	i = 0;
	result = 0;
	while (initial_state[i] != '\0')
	{
		if (initial_state[i] == '#')
			result += (i - OFFSET);
		i++;
	}
	answer(d, result);
	return (0);
}
