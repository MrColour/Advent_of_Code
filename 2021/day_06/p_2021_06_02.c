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

#define STOP_DATE (256)

int		main(void)
{
	char		*str_file;
	int			lantern_no;
	long long	timer[9] = { 0 };

	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, ",",
		fetch_int(_tok, &(lantern_no));
		timer[lantern_no]++;
	);

	int			i;
	long long	carry_over;
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

	long long	total;

	total = 0;
	FOR_EACH(_i < sizeof(timer) / sizeof(*timer),
		total += timer[_i]
	);

	answer(lld, total);
	return (0);
}
