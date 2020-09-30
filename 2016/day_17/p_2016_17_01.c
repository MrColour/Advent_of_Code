/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_17_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:39:05 by home              #+#    #+#             */
/*   Updated: 2020/09/30 00:22:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"
#include "md5.h"

typedef struct s_qelem t_queue_elem;

struct s_qelem
{
	int				x;
	int				y;
	char			*curr_path;
	t_queue_elem	*next;
};

bool	is_open(char c) { return (bound('b', c, 'f')); }

void	hash_to_str(unsigned char *hash, char *dst)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		dst[i * 2] = HEX[hash[i] >> 4];
		dst[i * 2 + 1] = HEX[hash[i] & 0x0F];
		i++;
	}
}

void	add_node(char dir, t_queue_elem *last, t_queue_elem *from)
{
	t_queue_elem	*new_elem;

	new_elem = calloc(1, sizeof(*new_elem));
	new_elem->next = NULL;
	asprintf(&(new_elem->curr_path), "%s%c", from->curr_path, dir);
	new_elem->x = from->x;
	new_elem->y = from->y;

	direction("DULR", dir, &(new_elem->x), &(new_elem->y));

	if (bound(0, new_elem->x, 3) && bound(0, new_elem->y, 3))
		last->next = new_elem;
}

int		main(void)
{
	int				i;
	char			*salt;
	char			*input;
	unsigned char	hash[16 + 1] = { 0 };
	char			hash_str[16 * 2 + 1] = { 0 };
	MD5_CTX			cxt;
	t_queue_elem	*last;
	t_queue_elem	*queue;
	char			dir[] = {'U', 'D', 'L', 'R'};

	salt = extract_file("input.txt");
	strchr(salt, '\n')[0] = '\0';

	queue = calloc(1, sizeof(*queue));
	*queue = (t_queue_elem){0, 0, "\0", NULL};
	last = queue;

	while (1 && queue != NULL)
	{
		if (queue->x == 3 && queue->y == 3)
			break ;

		asprintf(&input, "%s%s", salt, queue->curr_path);

		MD5_Init(&cxt);
		MD5_Update(&cxt, input, strlen(input));
		MD5_Final(hash, &cxt);
		hash_to_str(hash, hash_str);

		i = 0;
		while (i < 4)
		{
			if (is_open(hash_str[i]))
			{
				add_node(dir[i], last, queue);
				if (last->next != NULL)
					last = last->next;
			}
			i++;
		}

		queue = queue->next;
	}
	printf("RESULT: %s\n", queue->curr_path);
	return (0);
}
