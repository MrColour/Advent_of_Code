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

	int	sign;
	int	*change_to;

	sign = 1;
	pos_depth = 0;
	pos_horizontal = 0;
	FOR_EACH_STRTOK(str_file, "\n ",
		if (_tok[0] == 'f')
			change_to = &pos_horizontal;
		else
			change_to = &pos_depth;

		if (_tok[0] == 'u')
			sign = -1;

		_tok = strtok(NULL, "\n ");
		*change_to += sign * atoi(_tok);
		sign = 1;
	);

	answer(d, pos_depth * pos_horizontal);
	return (0);
}