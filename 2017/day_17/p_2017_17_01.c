/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_17_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 01:08:18 by home              #+#    #+#             */
/*   Updated: 2020/10/05 18:41:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_node
{
	int				number;
	struct s_node	*next;
}				t_node;

void	add_node(int insert, t_node *from)
{
	t_node	*next;
	t_node	*new_elem;

	next = from->next;

	new_elem = calloc(1, sizeof(*new_elem));
	new_elem->number = insert;
	new_elem->next = next;

	from->next = new_elem;
}

int		main(void)
{
	int		steps;
	int		rounds;
	t_node	*root;
	t_node	*at;

	steps = atoi(extract_file("input.txt"));

	root = &((t_node){0, NULL});
	root->next = root;
	at = root;

	int		i;

	rounds = 0;
	while (rounds < 2017)
	{
		i = 0;
		while (i < steps)
		{
			at = at->next;
			i++;
		}
		add_node(rounds + 1, at);
		at = at->next;
		rounds++;
	}
	printf("RESULT: %d\n", at->next->number);
	return (0);
}
