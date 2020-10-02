/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_07_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:38:17 by home              #+#    #+#             */
/*   Updated: 2020/10/01 20:43:14 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_tower_elem
{
	char	*id;
	int		wieght;
	int		own_wieght;
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
	new_prog->own_wieght = new_prog->wieght;
	new_prog->child = false;
	new_prog->child_amount = 0;
	new_prog->children = NULL;

	// printf("STR %d: %.10s\n", *alloc_info->index, new_prog->id);
	(*alloc_info->index)++;
	*alloc_info->iter_addr = strchr(line, '\n') + 1;

	return (new_prog);
}

void	tag_children(t_tower_elem *tower, int size, char *line, int index)
{
	int		i;
	int		j;
	int		c_i;
	char	*children;
	char	**child_split;

	children = strstr(line, "->");
	if (children == NULL)
		return ;

	STR_SPLIT(child_split, children, NULL, " ", i)
	child_split = &child_split[1];
	tower[index].child_amount = i - 1;
	tower[index].children = calloc(tower[index].child_amount, sizeof(tower[index].children));

	i = 0;
	c_i = 0;
	while (child_split[i] != NULL)
	{
		j = 0;
		if (strchr(child_split[i], ','))
			strchr(child_split[i], ',')[0] = '\0';
		while (j < size)
		{
			if (strcmp(tower[j].id, child_split[i]) == 0)
			{
				tower[index].children[c_i] = &tower[j];
				tower[j].child = true;
				c_i++;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		traverse(t_tower_elem *root)
{
	int		i;

	if (root->child_amount == 0)
		return (0);

	i = 0;
	while (i < root->child_amount)
	{
		root->children[i]->wieght = traverse(root->children[i]) + root->children[i]->wieght;
		i++;
	}

	int		check;
	int		sum;

	i = 0;
	sum = 0;
	check = root->children[i]->wieght;
	while (i < root->child_amount)
	{
		if (root->children[i]->wieght != check)
		{
			printf("check: %d %d and %d %d\n", check, root->children[0]->own_wieght, root->children[i]->wieght, root->children[i]->own_wieght);
			if (i == 1)
				printf("Match: %d\n", root->children[2]->wieght);
			else
				printf("Match: %d\n", root->children[1]->wieght);
			exit(0);
		}
		sum += root->children[i]->wieght;
		i++;
	}
	return (sum);
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
		tag_children(tower, size, s_tok, i);
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

	traverse(&tower[i]);

	printf("RESULT: %s\n", tower[i].id);
	return (0);
}
