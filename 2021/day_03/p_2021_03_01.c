/***************************************************************************
 * FILENAME:    p_2021_03_01.c
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

#define BIT_SIZE (12)

int		main(void)
{
	char	*str_file;
	int		count[BIT_SIZE] = { 0 };
	int		total_lines;

	str_file = extract_file("input.txt");
	total_lines = count_occur("\n", str_file);

	int i;

	FOR_EACH_STRTOK(str_file, "\n",
		i = 0;
		while (i < BIT_SIZE)
		{
			if (_tok[i] == '1') { count[i]++; }
			i++;
		}
	);

	int gamma_rate;

	gamma_rate = 0;
	i = 0;
	while (i < BIT_SIZE)
	{
		gamma_rate <<= 1;
		if (count[i] > total_lines / 2)
			gamma_rate |= 1;
		i++;
	}

	int	epsilon_rate;

	epsilon_rate = ~gamma_rate;
	epsilon_rate &= 0xFFFFFFFF ^ (0xFFFFFFFF << (BIT_SIZE));

	answer(d, epsilon_rate * gamma_rate);
	return (0);
}
