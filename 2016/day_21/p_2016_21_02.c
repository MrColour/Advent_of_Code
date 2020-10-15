/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_21_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:23:03 by home              #+#    #+#             */
/*   Updated: 2020/10/15 03:09:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

typedef	struct s_command
{
	char		*command;
	char		*(*func)(char *, char *);
}				t_command;

char		*swap_position_op_r(char *instr, char *string)
{
	int		first;
	int		second;
	char	*ptr;

	ptr = instr;
	ptr += fetch_int(ptr, &second);
	ptr += fetch_int(ptr, &first);

	// printf("swap p %d with %d\n", first, second);
	SWAP(string[first], string[second], char)

	return (string);
};

char		*swap_letters_op_r(char *instr, char *string)
{
	int		i;
	char	x;
	char	y;

	x = instr[12];
	y = instr[26];
	// printf("swap l %c with %c\n", x, y);

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == x)
			string[i] = y;
		else if (string[i] == y)
			string[i] = x;
		i++;
	}

	return (string);
}

char		*rotate_b_op_r(char *instr, char *string)
{
	int		i;
	int		at;
	int		rotate_amount;
	int		len;
	char	seek;
	char 	*buff;

	seek = instr[strlen(instr) - 1];
	// printf("CHAR: %c\n", instr[strlen(instr) - 1]);

	at = strchr(string, seek) - string;

	i = 0;
	len = strlen(string);
	while (string[i] != '\0')
	{
		rotate_amount = i + 1;
		rotate_amount += (i >= 4 ? 1 : 0);

		if (at == (i + rotate_amount) % len)
			break ;

		i++;
	}

	rotate_amount %= len;
	buff = strdup(string);

	memmove(&string[0], &buff[rotate_amount], len - rotate_amount);
	memmove(&string[len - rotate_amount], &buff[0], rotate_amount);

	return (string);
}

char		*rotate_op_r(char *instr, char *string)
{
	int		x;
	int		len;
	char	dir;
	char	*buff;

	fetch_int(instr, &x);
	dir = instr[7];

	buff = strdup(string);
	len = strlen(string);
	x %= len;

	// printf("rotate %c %d\n", dir, x);
	if (dir != 'r')
	{
		memmove(&string[x], &buff[0], len - x);
		memmove(&string[0], &buff[len - x], x);
	}
	else
	{
		memmove(&string[0], &buff[x], len - x);
		memmove(&string[len - x], &buff[0], x);
	}
	return (string);
}

char		*reverse_op_r(char *instr, char *string)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = instr;
	ptr += fetch_int(ptr, &x);
	ptr += fetch_int(ptr, &y);

	// printf("reverse %d - %d\n", x, y);
	while (x < y)
	{
		SWAP(string[x], string[y], char)

		x++;
		y--;
	}
	return (string);
}

char		*move_op_r(char *instr, char *string)
{
	char	*ptr;
	char	move_char;
	int		x;
	int		y;

	ptr = instr;
	ptr += fetch_int(ptr, &y);
	ptr += fetch_int(ptr, &x);

	// printf("move at %d to %d\n", x, y);
	move_char = string[x];

	if (x < y)
		memmove(&string[x], &string[x + 1], y - x);
	else
		memmove(&string[y + 1], &string[y], x - y);
	string[y] = move_char;
	return (string);
}

t_command	commands[] =
{
	{"swap position",		swap_position_op_r},
	{"swap letter",			swap_letters_op_r},
	{"rotate based",		rotate_b_op_r},
	{"rotate ",				rotate_op_r}, // This one must short circuited by rotate based, ie under it.
	{"reverse position",	reverse_op_r},
	{"move position",		move_op_r},
	{NULL, NULL}
};

char	*do_op(char *instr, char *string)
{
	int		i;

	i = 0;
	while (commands[i].command != NULL)
	{
		if (strncmp(instr, commands[i].command, strlen(commands[i].command)) == 0)
		{
			commands[i].func(instr, string);
			break ;
		}
		i++;
	}
	return (string);
}

int		main(void)
{
	int		newlines;
	char	*str_file;
	char	*start;
	char	**instr;

	start = strdup("fbgdceah");
	str_file = extract_file("input.txt");

	NEWLINE_SPLIT(instr, str_file, newlines);

	int		i;
	char	*string;

	i = newlines - 1;
	string = start;
	while (i >= 0)
	{
		string = do_op(instr[i], string);
		i--;
	}
	answer(s, string);
	return (0);
}
