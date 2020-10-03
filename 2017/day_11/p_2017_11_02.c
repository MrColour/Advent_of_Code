/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_11_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:22:35 by home              #+#    #+#             */
/*   Updated: 2020/10/02 23:22:20 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		convert(int nw, int n, int ne)
{
	int	result;
	int	compass[6];
	int	side1;
	int	side2;
	int	mid;

	compass[0] = nw;
	compass[1] = n;
	compass[2] = ne;
	compass[3] = -nw;
	compass[4] = -n;
	compass[5] = -ne;

	int i = 0;
	while (i < 6)
	{
		side1 = compass[i];
		mid = compass[(i + 1) % 6];
		side2 = compass[(i + 2) % 6];

		if (side1 > 0 && side2 > 0)
			return (mid + MAX(side1, side2));
		if (side1 == 0 && side2 == 0 && mid > 0)
			return (mid);
		i++;
	}
	return (0);
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		n;
	int		ne;
	int		nw;
	int		max;

	str_file = extract_file("input.txt");
	strchr(str_file, '\n')[0] = '\0';

	n = 0;
	ne = 0;
	nw = 0;
	max = INT_MIN;
	s_tok = strtok(str_file, ",");
	while (s_tok != NULL)
	{
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

		max = MAX(convert(nw, n, ne), max);

		s_tok = strtok(NULL, ",");
	}

	printf("RESULT: %d\n", max);
	return (0);
}
