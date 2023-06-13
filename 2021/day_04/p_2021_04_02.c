/***************************************************************************
 * FILENAME:    p_2021_04_01.c
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

int		find_match(int board[25], int seek)
{
	int i = 0;
	int	result;

	result = -1;
	while (i < 25)
	{
		if (board[i] == seek)
		{
			result = i;
			break;
		}
		// printf("%d ", board[i]);
		i++;
	}
	// printf("\n");
	return (result);
}

int		main(void)
{
	char	*str_file;
	int		total_lines;
	int		total_sections;
	char	**lines;

	str_file = extract_file("input.txt");
	total_sections = count_occur("\n\n", str_file);

	STR_SPLIT(lines, str_file, NULL, "\n", total_lines);

	int		(*boards)[25];
	int		(*boards_state)[10];
	int		*board_wins;
	int		i;
	int		j;
	char	*working_str;
	int		board_num;

	board_num = 0;
	ALLOC_1D(boards, total_sections, calloc_wrapper, &g_ameta);
	ALLOC_1D(boards_state, total_sections, calloc_wrapper, &g_ameta);
	ALLOC_1D(board_wins, total_sections, calloc_wrapper, &g_ameta);
	FOR_EACH(_i < total_lines,
		if (lines[_i + 1][0] == '\0')
		{
			_i++;
		} else {
			i = 0;
			j = 0;
			while (i < 5)
			{
				working_str = lines[_i];

				working_str += fetch_int(working_str, &(boards[board_num][i * 5 + 0]));
				working_str += fetch_int(working_str, &(boards[board_num][i * 5 + 1]));
				working_str += fetch_int(working_str, &(boards[board_num][i * 5 + 2]));
				working_str += fetch_int(working_str, &(boards[board_num][i * 5 + 3]));
				working_str += fetch_int(working_str, &(boards[board_num][i * 5 + 4]));

				i++;
				_i++;
			}
			board_num++;
		}
	);

	int	wins;
	int	*draws;
	int draw_length = count_occur(",", lines[0]) + 1;

	ALLOC_1D(draws, draw_length, calloc_wrapper, &g_ameta);
	working_str = lines[0];
	FOR_EACH(_i < draw_length,
		working_str += fetch_int(working_str, &(draws[_i]));
	);

	int	row;
	int	col;
	int	index;
	int	last_win;

	wins = total_sections;
	FOR_EACH(_i < draw_length && wins >= 1,
		i = 0;
		while (i < total_sections)
		{
			index = find_match(boards[i], draws[_i]);
			if (index != -1)
			{
				row = index / 5;
				col = index % 5 + 5;
				boards_state[i][row]++;
				boards_state[i][col]++;

				if (boards_state[i][row] >= 5 || boards_state[i][col] >= 5)
				{
					if (board_wins[i] == 0)
					{
						board_wins[i] = 1;
						wins--;
						last_win = i;
					}
				}
			}
			i++;
		}
	);

	int	total_sum;
	int	marked_sum;

	total_sum = 0;
	index = _i;
	FOR_EACH(_i < 25,
		total_sum += boards[last_win][_i];
	);

	FOR_EACH(_i < index,
		i = find_match(boards[last_win], draws[_i]);
		if (i != -1)
		{
			marked_sum += boards[last_win][i];
		}
	);

	answer(d, (total_sum - marked_sum) * draws[_i - 1]);
	return (0);
}
