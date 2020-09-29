/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_19_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:48:14 by home              #+#    #+#             */
/*   Updated: 2020/09/28 21:48:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

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

int		main(void)
{
	int		transitions_count;
	char	*str_file;
	char	*s_tok;
	char	*prev;
	char	*input_mol;

	str_file = extract_file("input.txt");

	transitions_count = count_occur("=>", str_file);

	input_mol = strstr(str_file, "\n\n") + 2;
	strchr(input_mol, '\n')[0] = '\0';
	// printf("MOL: %s\n", input_mol);

	int		i;
	int		result;
	int		t_size;
	char	*t_str;
	char	**strings;

	t_str = apply_transitions(str_file, transitions_count, input_mol);
	// printf("%s", t_str);

	NEWLINE_SPLIT(strings, t_str, t_size)
	// printf("SIZE: %d\n", t_size);

	qsort(strings, t_size - 1, sizeof(*strings), str_cmp);

	i = 1;
	result = 1;
	while (i < t_size - 1)
	{
		if (strcmp(strings[i - 1], strings[i]) != 0)
			result++;
		// printf("STR: %s\n", strings[i]);
		i++;
	}
	printf("RESULT: %d\n", result);
	return (0);
}