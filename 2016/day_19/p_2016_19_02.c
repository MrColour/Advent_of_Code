/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_19_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:59:11 by home              #+#    #+#             */
/*   Updated: 2020/09/22 22:58:17 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct	s_elf
{
	int				id;
	struct s_elf	*next;
}				t_elf;

int		main(void)
{
	int		i;
	int		size;
	char	*str_file;
	t_elf	*elf_list;

	str_file = extract_file("input.txt");
	size = atoi(str_file);

	elf_list = calloc(size, sizeof(*elf_list));

	i = 0;
	while (i < size - 1)
	{
		elf_list[i].id = i + 1;
		elf_list[i].next = &(elf_list[i + 1]);
		i++;
	}
	elf_list[i].id = i + 1;
	elf_list[i].next = &(elf_list[0]);

	t_elf	*curr;
	t_elf	*prior_del;

	curr = &elf_list[0];
	prior_del = &(elf_list[size / 2 - 1]);
	while (curr != curr->next && size > 2)
	{
		prior_del->next = prior_del->next->next; //prior_del deletes a node every turn.

		if (size % 2 == 1)
			prior_del = prior_del->next; //prior_del needs to advance every other turn.

		curr = curr->next;
		size--;
	}

	printf("RESULT: %d\n", curr->id);
	return (0);
}
