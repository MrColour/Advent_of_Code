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

int		count_place(char **lines, int line_size, int place, char compare)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	while (i < line_size)
	{
		if (lines[i][place] == compare)
			count++;
		i++;
	}
	return count;
}

int		get_binary(char **lines, int line_size)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	result = 0;
	while (i < line_size)
	{
		if (lines[i][0] != '\0')
		{
			j = 0;
			while (j < BIT_SIZE)
			{
				result <<= 1;
				if (lines[i][j] == '1') { result |= 1;}
				j++;
			}
			break ;
		}
		i++;
	}

	return result;
}

int		main(void)
{
	char	*str_file;
	int		total_lines;
	char	**lines;

	int		i;
	int		remaining;
	char	most;

	str_file = extract_file("input.txt");
	STR_SPLIT(lines, str_file, NULL, "\n", total_lines);

	i = 0;
	int amount = 0;
	remaining = total_lines;
	while (i < BIT_SIZE)
	{
		amount = count_place(lines, total_lines, i, '1');

		if (amount >= ((remaining + 1) / 2))
			most = '1';
		else
			most = '0';

		_i = 0;
		FOR_EACH(_i < total_lines,
			if (lines[_i][i] != most && lines[_i][i] != '\0')
			{
				memset(lines[_i], '\0', BIT_SIZE);
				remaining--;
			}
		);

		if (remaining == 1)
			break ;

		i++;
	}

	int oxygen = get_binary(lines, total_lines);

	str_file = extract_file("input.txt");
	STR_SPLIT(lines, str_file, NULL, "\n", total_lines);

	i = 0;
	amount = 0;
	remaining = total_lines;
	while (i < BIT_SIZE)
	{
		amount = count_place(lines, total_lines, i, '1');

		if (amount >= ((remaining + 1) / 2))
			most = '1';
		else
			most = '0';

		_i = 0;
		FOR_EACH(_i < total_lines,
			if (lines[_i][i] == most && lines[_i][i] != '\0')
			{
				memset(lines[_i], '\0', BIT_SIZE);
				remaining--;
			}
		);

		if (remaining == 1)
			break ;

		i++;
	}

	int carbon_dioxide = get_binary(lines, total_lines);

	answer(d, oxygen * carbon_dioxide);
	return (0);
}
