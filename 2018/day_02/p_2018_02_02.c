/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:23:55 by home              #+#    #+#             */
/*   Updated: 2020/10/17 18:42:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool	one_diff(char *a, char *b)
{
	int		i;
	int		diff;
	bool	one;

	i = 0;
	one = false;
	while (a[i] != '\0')
	{
		diff = (a[i] ^ b[i]);
		if (one == true && diff != 0)
			return (false);
		if (one == false && diff != 0)
			one = true;
		i++;
	}
	return (true);
}

int		main(void)
{
	char	*str_file;
	char	**boxIDs;
	int		size;

	str_file = extract_file("input.txt");
	NEWLINE_SPLIT(boxIDs, str_file, size)

	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (one_diff(boxIDs[i], boxIDs[j]) == true)
			{
				printf("%s\n%s\n", boxIDs[i], boxIDs[j]);
				break ;
			}
			j++;
		}
		if (j < size)
			break ;
		i++;
	}
	return (0);
}
