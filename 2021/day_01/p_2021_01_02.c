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
	);

	increases = 0;
	FOR_EACH(_i + 3 < input_length,
		if (depths[_i] < depths[_i + 3])
			increases++;
	);

	answer(d, increases);
	return (EXIT_SUCCESS);
}
