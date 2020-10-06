/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_18_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:37:05 by home              #+#    #+#             */
/*   Updated: 2020/10/06 01:27:27 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef struct	s_queue
{
	long long		val;
	struct s_queue	*next;
}				t_queue;

typedef struct	s_program
{
	t_queue		*queue;
	bool		waiting;
	long long	reg[256];
	int			ptr;
	int			sent;
}				t_program;

enum	sound_op
{
	SND,
	RCV,
	GET
}		sound_op;

void	sound_card(int op, long long *value)
{
	static long long frq;

	if (op == SND) { frq = *value; }
	else if (op == RCV) { printf("RESULT: %lld\n", frq); exit(0); }
	// else if (op == GET) { *value = frq; }
}

/*
s[n]d
r[c]v
s[e]t
a[d]d
m[u]l
m[o]d
j[g]z
*/

long long	second_value(char *instr, long long *reg)
{
	char		*ptr;
	long long	result;

	ptr = instr + skip_space(instr, 2) + 1;
	if (isalpha(ptr[0]))
		result = reg[(int)ptr[0]];
	else
		result = atoi(ptr);

	return (result);
}

t_queue *go_to_end(t_queue **queue_addr)
{
	t_queue	*queue;

	if (*queue_addr == NULL)
	{
		*queue_addr = calloc(1, sizeof(**queue_addr));
		return (*queue_addr);
	}

	queue = *queue_addr;

	while (queue->next != NULL)
		queue = queue->next;

	queue->next = calloc(1, sizeof(*queue));
	queue = queue->next;

	return (queue);
}

int		do_op(char *instr, long long *reg, t_program *other, t_program *running)
{
	int			jump;
	long long	second_val;
	t_queue		*end;

	jump = 1;
	if (instr[1] == 'n')
	{
		end = go_to_end(&(other->queue));

		if (isalpha(instr[4]))
			end->val = reg[(int)instr[4]];
		else
			end->val = atoi(&instr[4]);
		running->sent++;
	}
	else if (instr[1] == 'c')
	{
		if (running->queue == NULL)
		{
			running->waiting = true;
			jump = 0;
		}
		else
		{
			reg[(int)instr[4]] = running->queue->val;
			running->waiting = false;
			running->queue = running->queue->next;
			jump = 1;
		}
	}
	else
		second_val = second_value(instr, reg);

	if (instr[1] == 'e')
		reg[(int)instr[4]] = second_val;
	else if (instr[1] == 'd')
		reg[(int)instr[4]] += second_val;
	else if (instr[1] == 'u')
		reg[(int)instr[4]] *= second_val;
	else if (instr[1] == 'o')
		reg[(int)instr[4]] %= second_val;
	else if (instr[1] == 'g')
	{
		if (isalpha(instr[4]))
		{
			if (reg[(int)instr[4]] > 0)
				jump = second_val;
		}
		else if (atoi(&instr[4]) > 0)
			jump = second_val;
	}

	return (jump);
}

int		main(void)
{
	char	*str_file;
	char	**instr;
	int		len;

	t_program *program1;
	t_program *program2;
	t_program *running;
	t_program *other;

	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(instr, str_file, len)

	program1 = calloc(1, sizeof(*program1));
	program2 = calloc(1, sizeof(*program2));

	program1->reg['p'] = 0;
	program2->reg['p'] = 1;

	running = program1;
	other = program2;

	while (1)
	{
		running->ptr += do_op(instr[running->ptr], running->reg, other, running);
		if (running->ptr >= len - 1)
			break ;

		if (program1->waiting == true && program1->queue == NULL && program2->waiting == true && program2->queue == NULL)
			break ;

		if (running->waiting == true && running == program1)
		{
			running = program2;
			other = program1;
		}
		else if (running->waiting == true)
		{
			running = program1;
			other = program2;
		}
	}

	printf("RESULT: %d\n", program2->sent);
	return (0);
}
