/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_07_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:38:17 by home              #+#    #+#             */
/*   Updated: 2020/10/01 19:59:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_tower_elem
{
	char	*id;
	int		wieght;
	bool	child;

	int		child_amount;
	struct s_tower_elem	**children;
}				t_tower_elem;

void	*node_alloc(t_alloc_meta *alloc_info, size_t count, size_t elem_size)
{
	t_tower_elem *new_prog;
	char		*line;

	line = *(alloc_info->iter_addr);
	new_prog = malloc(count * elem_size);

	new_prog->id = strndup(line, strchr(line, ' ') - line);
	fetch_int(line, &new_prog->wieght);
	new_prog->child = false;
	new_prog->children = NULL;

	// printf("STR %d: %.10s\n", *alloc_info->index, new_prog->id);
	(*alloc_info->index)++;
	*alloc_info->iter_addr = strchr(line, '\n') + 1;

	return (new_prog);
}

void	tag_children(t_tower_elem *tower, int size, char *line)
{
	int		i;
	int		j;
	char	*children;
	char	**child_split;

	children = strstr(line, "->");
	if (children == NULL)
		return ;

	STR_SPLIT(child_split, children, NULL, " ", i)
	child_split = &child_split[1];

	i = 0;
	while (child_split[i] != NULL)
	{
		j = 0;
		if (strchr(child_split[i], ','))
			strchr(child_split[i], ',')[0] = '\0';
		while (j < size)
		{
			if (strcmp(tower[j].id, child_split[i]) == 0)
			{
				tower[j].child = true;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		size;
	int		i;
	t_tower_elem	*tower;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file);

	i = 0;
	s_tok = str_file;
	g_ameta.index = &i;
	g_ameta.iter_addr = (void **)&s_tok;
	ALLOC_1D(tower, size, node_alloc, &g_ameta)

	i = 0;
	s_tok = strtok(str_file, "\n");
	while (i < size)
	{
		tag_children(tower, size, s_tok);
		// printf("STR %d: %.10s\n", i, tower[i].id);
		s_tok = strtok(NULL, "\n");
		i++;
	}

	i = 0;
	while (i < size)
	{
		if (tower[i].child == false)
			break ;
		i++;
	}
	printf("RESULT: %s\n", tower[i].id);
	return (0);
}
