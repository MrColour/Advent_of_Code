/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_06b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:29:43 by kmira             #+#    #+#             */
/*   Updated: 2019/12/07 05:04:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_trie
{
	char			has_parent;
	char			key[4];
	struct s_trie	*children;	//depth + 1
	struct s_trie	*next;		//width + 1
}				t_trie;

t_trie	*create_object(char *name)
{
	t_trie *result;

	result = malloc(sizeof(*result));
	strcpy(result->key, name);
	result->children = NULL;
	result->next = NULL;
	return (result);
}

void	insert_child(t_trie	**list, t_trie *elem)
{
	t_trie	*prev;

	if (*list == NULL)
		*list = elem;
	else
	{
		prev = *list;
		while (prev->next)
			prev = prev->next;
		prev->next = elem;
	}
}

int	traverse_orbits(t_trie *root, int prev_orbit)
{
	int result;
	t_trie *iter;

	result = prev_orbit;
	iter = root->children;
	if (iter == NULL)
		return (prev_orbit);
	printf("Parent: %s\n", root->key);
	while (iter)
	{
		printf("Child:  %s\n", iter->key);
		result += traverse_orbits(iter, prev_orbit + 1);
		iter = iter->next;
	}
	return (result);
}

t_trie	*transfer_orbits(t_trie *root, int *found_YOU, int *found_SAN)
{
	// int	result;
	int	curr_YOU;
	int	curr_SAN;
	t_trie *iter;
	t_trie *result;

	curr_SAN = 0;
	curr_YOU = 0;
	iter = root->children;
	if (iter == NULL)
		return (NULL);
	// printf("Parent: %s\n", root->key);
	while (iter)
	{
		// printf("Child:  %s\n", iter->key);
		if (strcmp(iter->key, "YOU") == 0)
			*found_YOU = 1;
		if (strcmp(iter->key, "SAN") == 0)
			*found_SAN = 1;
		// result += traverse_orbits(iter, prev_orbit + 1);
		result = transfer_orbits(iter, &curr_YOU, &curr_SAN);
		if (curr_YOU == 1 && curr_SAN == 1) //This returns internally
		{
			printf("NODE HAS BOTH %s\n", root->key);
			return (root);
		}
		if (result != NULL) //This returns outside
			return (result);
		iter = iter->next;
	}
	*found_SAN |= curr_SAN;
	*found_YOU |= curr_YOU;
	return (NULL);
}

int		key_finder(t_trie *root, char *key)
{
	t_trie	*iter;
	int		result;

	result = 0;
	if (strcmp(root->key, key) == 0)
		return (1);
	iter = root->children;
	while (iter)
	{
		result = key_finder(iter, key);
		if (result != 0)
			break ;
		iter = iter->next;
	}
	if (result != 0)
		return (result + 1);
	return (0);
}

int		main(void)
{
	int		fd;
	int		count;
	char	str[9]; //3 letter, ')', 3 letters, then '\n'
	t_trie	*root;
	char	*file;

	file = "day_06.txt";
	// file = "test.txt";
	count = 0;
	root = NULL;
	fd = open(file, O_RDONLY);
	while (read(fd, str, 8))
		count++;
	close(fd);
	fd = open(file, O_RDONLY);

	int		i;
	t_trie	**trie_arr;
	i = 0;
	trie_arr = malloc(sizeof(*trie_arr) * (count + 1));
	while (read(fd, str, 8))
	{
		str[3] = '\0';
		str[7] = '\0';
		trie_arr[i] = create_object(&str[4]);
		// printf("STR: %s\n", trie_arr[i]->key);
		i++;
	}
	trie_arr[i] = NULL;

	int	at;

	at = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	while (read(fd, str, 8))
	{
		str[3] = '\0';
		str[7] = '\0';
		i = 0;
		while (trie_arr[i] != NULL)
		{
			if (strcmp(trie_arr[i]->key, &str[0]) == 0)
			{
				// printf("Adding: %s to parent %s\n", trie_arr[at]->key, trie_arr[i]->key);
				insert_child(&trie_arr[i]->children, trie_arr[at]);
				break ;
			}
			i++;
		}
		if (trie_arr[i] == NULL)
		{
			// printf("Found a root! It is: %s\n", &str[0]);
			if (root == NULL)
				root = create_object(&str[0]);
			insert_child(&(root->children), trie_arr[at]);
		}
		at++;
	}

	t_trie *intersection;

	int found_Y = 0;
	int found_S = 0;
	intersection = transfer_orbits(root, &found_Y, &found_S);

	printf("RESULT: %s\n", intersection->key);

	int	toYOU = 0;
	int	toSAN = 0;

	toYOU = key_finder(intersection, "YOU") - 2; //YOU to orbit doesn't count, function will then add another 1
	toSAN = key_finder(intersection, "SAN") - 2;

	printf("YOU: %d SAN: %d\n", toYOU, toSAN);
	printf("RESULT: %d\n", toSAN + toYOU);
	return (0);
}
