/***************************************************************************
 * FILENAME:    p_2021_07_01.c
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

int		main(void)
{
	char	*str_file;
	int		max;
	int		i;
	int		crab_no;

	str_file = extract_file("input.txt");
	FOR_EACH_STRTOK(str_file, ",",
		fetch_int(_tok, &(i));
		if (i > max)
			max = i;
	);
	crab_no = _i;

	int		*positions;
	int		*less_thans;
	int		*more_thans;
	int		individual_pos;

	str_file = extract_file("input.txt");
	max += 1;
	positions = calloc(max, sizeof(*positions));
	less_thans = calloc(max, sizeof(*less_thans));
	more_thans = calloc(max, sizeof(*more_thans));

	FOR_EACH(_i < crab_no,
		str_file += fetch_int(str_file, &(individual_pos));
		positions[individual_pos]++;
	)

	FOR_EACH(_i < max,
		more_thans[_i] = crab_no;
	);

	int	base;

	base = 0;
	more_thans[0] -= positions[0];
	FOR_EACH(_i <= max,
		base += positions[_i] * _i;

		if (_i != 0)
			less_thans[_i] += less_thans[_i - 1] + positions[_i - 1];

		if (_i != max && _i != 0)
		{
			more_thans[_i] = more_thans[_i - 1] - positions[_i];
		}
	)

	int	min_fuel;

	min_fuel = base;
	FOR_EACH(_i < max - 1,
		base += less_thans[_i + 1];
		base -= more_thans[_i + 1];
		base -= positions[_i + 1];

		if (base < min_fuel)
			min_fuel = base;
	);

	answer(d, min_fuel)
	return (0);
}
