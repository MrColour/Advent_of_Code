/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_14_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 04:34:42 by home              #+#    #+#             */
/*   Updated: 2020/10/20 05:32:30 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_recipe
{
	int		id;
	struct s_recipe	*next;
}				t_recipe;

void		print_recipes(t_recipe *recipes)
{
	t_recipe	*out = recipes;
	while (out->next != recipes) { printf("%d ", out->id); out = out->next; }
	printf("%d\n", out->id);
}

t_recipe	*forward(t_recipe *at, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		at = at->next;
		i++;
	}
	return (at);
}

t_recipe	*new_recipe(int sum, t_recipe *last)
{
	t_recipe	*first;

	t_recipe	*ones;
	t_recipe	*tens;

	first = last->next;

	ones = calloc(1, sizeof(*ones));
	ones->id = sum % 10;
	ones->next = first;
	last->next = ones;

	if (sum / 10 > 0)
	{
		tens = calloc(1, sizeof(*tens));
		tens->id = sum / 10;
		tens->next = ones;
		last->next = tens;
	}
	return (ones);
}

bool	check(t_recipe *recipes, int num)
{
	int	result;

	result = 0;
	while (result < num)
	{
		result *= 10;
		result += recipes->id;
		recipes = recipes->next;
	}
	if (result == num)
		return (true);
	else
		return (false);
}

#define BIG_NUM (100000000)

int		main(void)
{
	int		i;
	int		stop;
	int		finding;
	int		f_start;
	int		len;

	t_recipe	*recipes;
	t_recipe	*last;
	t_recipe	*elf1;
	t_recipe	*elf2;

	finding = atoi(extract_file("input.txt"));

	f_start = finding;
	FOR_EACH(f_start > 10,
		f_start /= 10;
	)

	stop = BIG_NUM;

	recipes = &(t_recipe){3, NULL};
	recipes->next = recipes;
	last = recipes;
	last = new_recipe(7, last);

	elf1 = recipes;
	elf2 = recipes->next;

	len = 2;
	while (len <= stop)
	{
		last = new_recipe(elf1->id + elf2->id, last);

		elf1 = forward(elf1, elf1->id + 1);
		elf2 = forward(elf2, elf2->id + 1);
		// print_recipes(recipes);
		len++;
	}

	i = 0;
	while (i < stop)
	{
		if (recipes->id == f_start && check(recipes, finding) == true)
			break ;

		recipes = recipes->next;
		i++;
	}

	answer(d, i);
	return (0);
}
