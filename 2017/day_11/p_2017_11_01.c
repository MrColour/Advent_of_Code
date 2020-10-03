/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_11_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:22:35 by home              #+#    #+#             */
/*   Updated: 2020/10/02 23:22:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		n;
	int		ne;
	int		nw;

	str_file = extract_file("input.txt");
	strchr(str_file, '\n')[0] = '\0';

	n = 0;
	ne = 0;
	nw = 0;
	s_tok = strtok(str_file, ",");
	while (s_tok != NULL)
	{
		printf("%s\n", s_tok);
		if (strcmp(s_tok, "n") == 0)
			n++;
		else if (strcmp(s_tok, "s") == 0)
			n--;
		else if (strcmp(s_tok, "ne") == 0)
			ne++;
		else if (strcmp(s_tok, "sw") == 0)
			ne--;
		else if (strcmp(s_tok, "nw") == 0)
			nw++;
		else if (strcmp(s_tok, "se") == 0)
			nw--;

		s_tok = strtok(NULL, ",");
	}

	printf("%d and %d and %d\n", n, ne, nw);
	printf("RESULT: %d\n", n + ne); //Depending on the numbers above the result may vary. See part 2
	return (0);
}
