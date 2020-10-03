/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_12_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:46:01 by home              #+#    #+#             */
/*   Updated: 2020/10/03 01:48:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_graph
{
	bool		visted;
	bool		*connections;
}				t_graph;

void	fill_connex(t_graph *dst, char *str_file)
{
	int		to;

	str_file = strstr(str_file, "> ") + 2;
	while (str_file[0] != '\0')
	{
		str_file += fetch_int(str_file, &to);
		dst->connections[to] = true;
	}
}

void graph_travel(int into, t_graph *graph, int size, int *acum_vist)
{
	int		i;
	t_graph	*node;

	i = 0;
	(*acum_vist)++;
	node = &graph[into];
	node->visted = true;
	while (i < size)
	{
		if (node->connections[i] == true && graph[i].visted == false)
			graph_travel(i, graph, size, acum_vist);
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	int		total_programs;
	t_graph	*graph;
	int		id;

	str_file = extract_file("input.txt");
	total_programs = count_occur("\n", str_file);

	graph = calloc(total_programs, sizeof(*graph));

	str_file = strtok(str_file, "\n");
	while (str_file != NULL)
	{
		str_file += fetch_int(str_file, &id);
		graph[id].connections = calloc(total_programs, sizeof(*(graph[id].connections)));
		fill_connex(&graph[id], str_file);
		graph[id].visted = false;

		str_file = strtok(NULL, "\n");
	}

	int		result;

	result = 0;
	graph_travel(0, graph, total_programs, &result);
	printf("RESULT: %d\n", result);
	return (0);
}
