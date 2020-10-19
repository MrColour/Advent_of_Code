/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_09_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:34:20 by home              #+#    #+#             */
/*   Updated: 2020/10/19 01:10:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_marble
{
	struct s_marble	*next;
}				t_marble;

void	print(t_marble *marbles)
{
	t_marble *at = &marbles[0];
	while ((at->next - marbles) != 0)
	{
		printf("%ld ", at - marbles);
		at = at->next;
	}
	printf("%ld ", at - marbles);
	printf("\n");
}

t_marble	*reverse_7(t_marble *curr)
{
	int			i;
	t_marble	*behind;
	t_marble	*stop;

	i = 0;
	stop = curr;
	behind = curr;
	while (i < 7 + 1) // We want to stop one prior.
	{
		curr = curr->next;
		i++;
	}

	while (curr != stop)
	{
		curr = curr->next;
		behind = behind->next;
	}
	return (behind);
}

int		main(void)
{
	char	*str_file;
	int		players;
	int		m_size;

	str_file = extract_file("input.txt");

	str_file += fetch_int(str_file, &players);
	str_file += fetch_int(str_file, &m_size);

	int			turn;
	int			*elves;
	t_marble	*marbles;
	t_marble	*curr;

	turn = 1;
	elves = calloc(players, sizeof(*elves));
	marbles = calloc(m_size, sizeof(*marbles));

	curr = &marbles[0];
	marbles[0].next = &marbles[0];
	while (turn <= m_size)
	{
		if (turn % 23 != 0)
		{
			curr = curr->next;
			marbles[turn].next = curr->next;
			curr->next = &marbles[turn];
		}
		else
		{
			curr = reverse_7(curr);
			elves[turn % players] += turn + (curr->next - marbles);
			// printf("Reverse %ld\n", curr - marbles);
			curr->next = curr->next->next;
		}

		// print(marbles);

		curr = curr->next;
		turn++;
	}

	int		*result;

	result = last(elves, players, sizeof(*elves), int_cmp_asc);
	answer(d, *result);
	return (0);
}
