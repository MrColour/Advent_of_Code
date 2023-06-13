/***************************************************************************
 * FILENAME:    p_2021_06_01.c
 * DESCRIPTION:
 *
 * ENVIRONMENT:
 *     macOS Ventura 13.2.1
 *     Visual Studio Code 1.76.0
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 12Jun2023
***************************************************************************/

#include "../aoc++.h"

#define STOP_DATE (80)

int		main(void)
{
	char	*str_file;
	int		timer[9] = { 0 };
	int		lantern_no;

	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, ",",
		fetch_int(_tok, &(lantern_no));
		timer[lantern_no]++;
	);

	int	i;
	int	carry_over;
	FOR_EACH(_i < STOP_DATE,

		i = 0;
		carry_over = timer[0];
		while (i < sizeof(timer) / sizeof(*timer))
		{
			timer[i] = timer[i + 1];
			i++;
		}
		timer[8] = carry_over;
		timer[6] += carry_over;
	);

	int	total;

	total = 0;
	FOR_EACH(_i < sizeof(timer) / sizeof(*timer),
		total += timer[_i]
	);

	answer(d, total);
	return (0);
}
