/***************************************************************************
 * FILENAME:    p_2021_01_01.c
 * DESCRIPTION:
 *
 * ENVIRONMENT:
 *     macOS Ventura 13.2.1
 *     Visual Studio Code 1.76.0
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 11Jun2023
***************************************************************************/

#include "../aoc++.h"

int		main(void)
{
	int		*depths;
	char	*str_file;
	int		increases;

	str_file = extract_file("input.txt");
	int input_length = count_occur("\n", str_file);

	depths = calloc(input_length, sizeof(*depths));
	FOR_EACH_STRTOK(str_file, "\n",
		depths[_i] = atoi(_tok);
		// printf("%d at %d\n", depths[_i], _i);
	);

	int i;

	i = 0;
	increases = 0;
	while (i + 1 < input_length)
	{
		printf("%d at %d\n", depths[i], depths[i + 1]);
		if (depths[i] < depths[i + 1])
			increases++;
		i++;
	}

	answer(d, increases);
	return (EXIT_SUCCESS);
}
