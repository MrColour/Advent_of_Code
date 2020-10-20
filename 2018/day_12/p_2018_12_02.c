/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_12_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:00:17 by home              #+#    #+#             */
/*   Updated: 2020/10/19 21:35:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

#define OFFSET (10)
#define LEN (500)
#define TO (50000000000)

char	*new_generation(char *initial_state, char **transforms)
{
	int	i;
	int	j;
	char	*result;

	i = 0;
	result = calloc(OFFSET + LEN, 1);

	memset(result, '.', LEN + OFFSET - 1);
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
	free(initial_state);
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

	// printf("  0: [%.270s]\n", initial_state);

	size_t	i;

	// i = 1;
	// while (i <= TO)
	// {
	// 	initial_state = new_generation(initial_state, transforms);
	// 	printf("%3zu: [%.270s]\n", i, initial_state);
	// 	i++;
	// }
	// printf("%3zu: [%s]\n", i, initial_state);

	char	*seed;
	int		start_seed;

	//Seed was found through the code above. Upon printing it one sees that
	//plants don't change anymore. Their positions do however, but not their configuration.
	seed = strdup("............................................................................................#.##...#.##.##....#.##...#.##.##...#.##.##.##.##.##.##.##.##...#.##...#.##.##.##.##.##.##....#.##...#.##...#.##.##...#.##...#.##.##.##.##.##.##.##................................");
	start_seed = 128;

	long long	result;

	//Below is validation code to ensure that the calulated method is the same
	//as the actual method. Note that because of space and time comlexity, the
	//actual method can only go up TO about (LEN - 50).
	// i = 0;
	// result = 0;
	// while (initial_state[i] != '\0')
	// {
	// 	if (initial_state[i] == '#')
	// 		result += (i - OFFSET);
	// 	i++;
	// }
	// answer(lld, result);

	i = 0;
	result = 0;
	while (seed[i] != '\0')
	{
		if (seed[i] == '#')
			result += (i + (TO - start_seed - OFFSET));
		i++;
	}
	answer(lld, result);
	return (0);
}
