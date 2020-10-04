/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2017_13_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:51:38 by home              #+#    #+#             */
/*   Updated: 2020/10/03 18:23:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	int		size;
	int		(*firewall)[2];

	int		i;
	int		range;

	str_file = extract_file("input.txt");
	size = count_occur("\n", str_file);
	firewall = calloc(size, sizeof(*firewall));

	i = 0;
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		s_tok += fetch_int(s_tok, &(firewall[i][0]));
		s_tok += fetch_int(s_tok, &range);
		firewall[i][1] = (range * 2 - 2);

		s_tok = strtok(NULL, "\n");
		i++;
	}

	int		seconds;
	bool	found;

	seconds = 0;
	while (1)
	{
		i = 0;
		found = false;
		while (i < size)
		{
			if ((seconds + firewall[i][0]) % firewall[i][1] == 0)
			{
				found = true;
				break ;
			}
			i++;
		}
		if (found == false)
			break ;
		seconds++;
	}
	printf("RESULT: %d\n", seconds);
	return (0);
}