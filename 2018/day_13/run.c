/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:18:33 by home              #+#    #+#             */
/*   Updated: 2020/10/20 03:53:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct s_carts
{
	int x;
	int y;

	int command;

	char facing;
	char replace;
	bool crashed;
} t_carts;

void extract_carts(char **map, t_carts *carts)
{
	int row;
	int col;
	int cart_id;
	char hash[256] = {
		['<'] = '-',
		['^'] = '|',
		['>'] = '-',
		['v'] = '|'};

	row = 0;
	cart_id = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (strchr("<^>v", map[row][col]))
			{
				carts[cart_id].x = col;
				carts[cart_id].y = row;
				carts[cart_id].command = 0;
				carts[cart_id].facing = map[row][col];
				carts[cart_id].replace = hash[map[row][col]];
				carts[cart_id].crashed = false;
				cart_id++;
			}
			col++;
		}
		row++;
	}
}

t_carts	*crash(t_carts *list, t_carts *match)
{
	int		i;

	i = 0;
	while (!(list[i].x == match->x && list[i].y == match->y && list[i].crashed == false))
		i++;
	list[i].crashed = true;
	match->crashed = true;
	return (&list[i]);
}

int cart_cmp(const void *ptr_a, const void *ptr_b)
{
	t_carts *a;
	t_carts *b;

	a = (t_carts *)ptr_a;
	b = (t_carts *)ptr_b;

	if (a->y == b->y && a->x > b->x)
		return (1);
	else if (a->y > b->y)
		return (1);
	else
		return (-1);
}

void advance(char **map, t_carts *carts, int size, int *rem)
{
	int i;
	t_carts *crashed;
	static int steps;
	char keypad[] = "v^<>"; //Up down reversed because moving in an array.
	char rotation[] = "<^>v";
	char r_index;
	int old_x;
	int old_y;

	char rail_for[] = {['v'] = '<', ['^'] = '>', ['>'] = '^', ['<'] = 'v'};
	char rail_bac[] = {['v'] = '>', ['^'] = '<', ['>'] = 'v', ['<'] = '^'};

	psort(carts, size, sizeof(*carts), cart_cmp);

	i = 0;
	crashed = NULL;
	while (i < size)
	{
		old_x = carts[i].x;
		old_y = carts[i].y;

		if (carts[i].crashed == false)
		{
			if (carts[i].replace == '+')
			{
				r_index = strchr(rotation, carts[i].facing) - rotation;
				if (carts[i].command == 0)
					r_index = strchr(rotation, carts[i].facing) - rotation - 1;
				if (carts[i].command == 2)
					r_index = strchr(rotation, carts[i].facing) - rotation + 1;
				r_index = (r_index + 4) % 4;

				carts[i].facing = rotation[r_index];

				carts[i].command++;
				carts[i].command %= 3;
			}

			direction(keypad, carts[i].facing, &carts[i].x, &carts[i].y);

			SWAP(map[old_y][old_x], carts[i].replace, char)
			carts[i].replace = map[carts[i].y][carts[i].x];
			if (strchr("v^<>", carts[i].replace) != NULL) // if it is replacing a cart.
			{
				crashed = crash(carts, &carts[i]);
				map[carts[i].y][carts[i].x] = crashed->replace;
				*rem -= 2;
			}
			else
			{
				if (carts[i].replace == '\\')
					carts[i].facing = rail_bac[carts[i].facing];
				if (carts[i].replace == '/')
					carts[i].facing = rail_for[carts[i].facing];
				map[carts[i].y][carts[i].x] = carts[i].facing;
			}

		}

		i++;
	}
}

int main(void)
{
	char *str_file;
	t_carts *carts;
	char **map;
	int len;
	int m_size;

	str_file = extract_file("input.txt");
	len = 0;
	FOR_EACH(str_file[_i] != '\0',
			 if (strchr("<^>v", str_file[_i]))
				 len++;)
	carts = calloc(len, sizeof(*carts));

	NEWLINE_SPLIT(map, str_file, m_size)

	extract_carts(map, carts);

	int cart_rem;

	cart_rem = len;
	while (cart_rem > 1)
	{
		advance(map, carts, len, &cart_rem);
		// printf("\n");
		// FOR_EACH(map[_i] != NULL,
		// 	printf("%s\n", map[_i])
		// )
	}

	FOR_EACH(_i < len,
		if (carts[_i].crashed == false)
			break ;
	)

	printf("%d,%d\n", carts[_i].x, carts[_i].y);
	return (0);
}
