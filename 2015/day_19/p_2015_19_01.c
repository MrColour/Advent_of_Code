/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_19_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:48:14 by home              #+#    #+#             */
/*   Updated: 2020/09/09 20:46:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE (1024)

char	*extract_file(char *file_name)
{
	int		fd;
	int		bytes_read;
	int		size;
	char	*result;

	size = 0;
	result = NULL;
	fd = open(file_name, O_RDONLY);

	bytes_read = 1;
	while (bytes_read != 0)
	{
		result = realloc(result, size + BUFF_SIZE + 1);
		bytes_read = read(fd, &result[size], BUFF_SIZE);
		size += bytes_read;
		result[size] = '\0';
	}
	return (result);
}

void	find_all_occurrences(char *needle, char *haystack, FILE *stream, char *replacement)
{
	char	*loc;
	int		n_length;
	int		r_length;

	n_length = strlen(needle);
	r_length = strchr(replacement, '\n') - replacement;
	loc = strstr(haystack, needle);
	while (loc != NULL)
	{
		// printf("FOUND: %s in %s\n", needle, loc);
		// printf("%.*s", (int)(loc - haystack), haystack);
		fprintf(stream, "%.*s", (int)(loc - haystack), haystack);
		// printf("%.*s", r_length, replacement);
		fprintf(stream, "%.*s", r_length, replacement);

		loc += n_length;
		// printf("%s\n", loc);
		fprintf(stream, "%s\n", loc);
		loc = strstr(loc, needle);
	}
	(void)stream;
}

char	*apply_transitions(char *transition, int transition_count, char *mol)
{
	int		i;
	char	*t_end;
	char	*r_start;
	char	*all_tranforms;
	size_t	size;
	FILE	*stream;

	i = 0;
	stream = open_memstream(&all_tranforms, &size);
	while (i < transition_count)
	{
		t_end = strchr(transition, ' ');

		t_end[0] = '\0';
		r_start = t_end + 4;
		// printf("T:%d %s with %s", i, transition, r_start);
		find_all_occurrences(transition, mol, stream, r_start);

		transition = t_end + 1;
		transition = strchr(transition, '\n') + 1;

		i++;
	}
	fclose(stream);
	return (all_tranforms);
}

int		m_cmp(const void *ptr_a, const void *ptr_b)
{
	int		result;
	char	*str_a;
	char	*str_b;

	str_a = *(char **)ptr_a;
	str_b = *(char **)ptr_b;
	result = strcmp(str_a, str_b);
	return (result);
}

int		main(void)
{
	int		transitions_count;
	char	*str_file;
	char	*s_tok;
	char	*prev;
	char	*input_mol;

	str_file = extract_file("input.txt");

	prev = NULL;
	transitions_count = -1;
	s_tok = str_file - 1;
	while (s_tok != NULL)
	{
		s_tok++;
		// printf("STR %d: %.4s\n", transitions_count, s_tok);
		prev = s_tok;
		s_tok = strchr(s_tok, '>');
		transitions_count++;
	}

	s_tok = strchr(prev, '\n') + 1;
	input_mol = strchr(s_tok, '\n') + 1;
	strchr(input_mol, '\n')[0] = '\0';
	printf("MOL: %s\n", input_mol);

	int		i;
	int		result;
	int		t_size;
	char	*t_str;
	char	**strings;

	t_str = apply_transitions(str_file, transitions_count, input_mol);

	t_size = 0;
	s_tok = t_str - 1;
	while (s_tok != NULL)
	{
		s_tok++;
		t_size++;
		s_tok = strchr(s_tok, '\n');
	}
	printf("SIZE: %d\n", t_size);
	// printf("%s", t_str);

	i = 0;
	strings = calloc(t_size, sizeof(*strings));
	strings[i] = strtok(t_str, "\n");
	while (strings[i] != NULL)
	{
		// printf("STR: %s\n", strings[i]);
		strings[i + 1] = strtok(NULL, "\n");
		i++;
	}

	qsort(strings, t_size - 1, sizeof(*strings), m_cmp);

	i = 1;
	result = 1;
	while (i < t_size - 1)
	{
		if (strcmp(strings[i - 1], strings[i]) != 0)
			result++;
		printf("STR: %s\n", strings[i]);
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}