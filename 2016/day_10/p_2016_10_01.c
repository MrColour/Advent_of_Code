/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_10_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:20:43 by home              #+#    #+#             */
/*   Updated: 2020/09/29 23:10:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct		s_bot
{
	int				temp;
	int				given;
	struct s_bot	*hi_give;
	struct s_bot	*low_give;

	int				hi;
	int				low;
}					t_bot;

void	give_bot(t_bot *bot, int value)
{
	if (bot->given == 0)
	{
		bot->temp = value;
		bot->given = 1;
	}
	else if (bot->given == 1 && value != bot->temp)
	{
		bot->low = MIN(value, bot->temp);
		bot->hi = MAX(value, bot->temp);
		bot->given = 2;
	}
}

int		main(void)
{
	char	*str_file;
	int		newlines;
	t_bot	*bots;

	str_file = extract_file("input.txt");
	newlines = count_occur("\n", str_file);

	bots = calloc(newlines, sizeof(*bots));

	int		value;
	int		bot_no;
	char	*s_tok;
	char	*ptr;

	int		from;
	int		low_to;
	int		hi_to;

	s_tok = str_file - 1;
	while (s_tok[1] != '\0')
	{
		s_tok++;

		ptr = s_tok;
		if (s_tok[0] == 'v')
		{
			ptr += fetch_int(ptr, &value);
			ptr += fetch_int(ptr, &bot_no);
			give_bot(&bots[bot_no], value);
		}
		else
		{
			ptr += fetch_int(ptr, &from);

			if (strstr(ptr, "to")[3] == 'b')
			{
				ptr += fetch_int(ptr, &low_to);
				bots[from].low_give = &bots[low_to];
			}
			else
				ptr += fetch_int(ptr, &low_to);

			if (strstr(ptr, "to")[3] == 'b')
			{
				ptr += fetch_int(ptr, &hi_to);
				bots[from].hi_give = &bots[hi_to];
			}
		}

		s_tok = strchr(s_tok, '\n');
	}

	int		hi_seek;
	int		low_seek;

	low_seek = 17;
	hi_seek = 61;

	bot_no = 0;
	while (1)
	{
		if (bots[bot_no].given == 2)
		{
			//Each bot has already been given two.
			if(bots[bot_no].low == low_seek && bots[bot_no].hi == hi_seek)
				break ;
			if (bots[bot_no].low_give != NULL)
				give_bot(bots[bot_no].low_give, bots[bot_no].low);
			if (bots[bot_no].hi_give != NULL)
				give_bot(bots[bot_no].hi_give, bots[bot_no].hi);
		}

		bot_no++;
		if (bot_no >= newlines)
			bot_no = 0;
	}
	printf("RESULT: %d\n", bot_no);
	return (0);
}
