/***************************************************************************
 * FILENAME:    p_2021_02_01.c
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
	char	*str_file;

	str_file = extract_file("input.txt");

	int	pos_horizontal;
	int	pos_depth;
	int	aim;

	int	sign;

	aim = 0;
	sign = 1;
	pos_depth = 0;
	pos_horizontal = 0;
	char	*str_number;

	FOR_EACH_STRTOK(str_file, "\n ",

		str_number = strtok(NULL, "\n ");
		if (_tok[0] == 'f')
		{
			pos_horizontal += atoi(str_number);
			pos_depth += aim * atoi(str_number);
		}
		else if (_tok[0] == 'u') { aim -= atoi(str_number); }
		else if (_tok[0] == 'd') { aim += atoi(str_number); }

	);

	answer(d, pos_depth * pos_horizontal);
	return (0);
}