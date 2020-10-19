/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_10_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:57:01 by home              #+#    #+#             */
/*   Updated: 2020/10/19 03:42:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_star
{
	int	x;
	int	y;

	int	v_x;
	int	v_y;
}				t_star;

#define GRID_SIZE (100)

void	update_stars(t_star *stars, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		stars[i].x += stars[i].v_x;
		stars[i].y += stars[i].v_y;

		i++;
	}
}

#define JUMP (10885)
#define OFFSET_X (140)
#define OFFSET_Y (100)

void	print_grid(t_star *stars, int size)
{
	int		i;
	int		count;
	char	grid[GRID_SIZE][GRID_SIZE];

	memset(grid, '.', sizeof(grid));

	i = 0;
	count = 0;
	while (i < size)
	{
		if (bound_box(0 + OFFSET_X, stars[i].x, GRID_SIZE - 1 + OFFSET_X,
					  0 + OFFSET_Y, stars[i].y, GRID_SIZE - 1 + OFFSET_Y) == true)
		{
			grid[stars[i].y - OFFSET_Y - 1][stars[i].x - OFFSET_X - 1] = '#';
			count++;
		}
		i++;
	}

	i = 0;
	while (i < GRID_SIZE - 1)
	{
		printf("%.*s\n", GRID_SIZE, grid[i]);
		i++;
	}
}


int		main(void)
{
	char	*str_file;
	char	*src;
	int		size;
	t_star	*stars;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file);

	stars = calloc(size + 1, sizeof(*stars));

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &stars[_i].x);
		_tok += fetch_int(_tok, &stars[_i].y);
		_tok += fetch_int(_tok, &stars[_i].v_x);
		_tok += fetch_int(_tok, &stars[_i].v_y);

		stars[_i].x += (stars[_i].v_x * JUMP);
		stars[_i].y += (stars[_i].v_y * JUMP);
	)

	char	input;
	int		i;

	i = 0;
	while (1)
	{
		scanf("%c", &input);

		i++;
		printf("SEC: "GOLD"%d\e[0m\n", i + JUMP);
		update_stars(stars, size);
		print_grid(stars, size);
	}

	return (0);
}
