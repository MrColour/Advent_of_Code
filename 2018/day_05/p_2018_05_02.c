/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_05_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:36:12 by home              #+#    #+#             */
/*   Updated: 2020/10/17 23:22:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		destroyed_amount(char *mol, int size)
{
	int		i;
	int		j;
	int		destroyed;

	i = 0;
	j = 1;
	destroyed = 0;
	while (i < size)
	{
		if (mol[i] + ('a' - 'A') == mol[j] || mol[i] + ('A' - 'a') == mol[j])
		{
			// printf("Removed %c and %c\n", mol[i], mol[j]);
			mol[i] = '\0';
			mol[j] = '\0';
			while (i > 0 && mol[i] == '\0')
				i--;
			j++;
			i--;
			destroyed++;
		}

		i++;
		if (i < 0)
			i = 0;
		if (j == i)
			j++;
	}
	return (destroyed);
}

int		new_mol(char **dest, char *src, int remove)
{
	int	i;
	int	j;

	*dest = strdup(src);

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (src[i] != remove && src[i] != remove + ('A' - 'a'))
		{
			(*dest)[j] = src[i];
			j++;
		}
		i++;
	}
	(*dest)[j] = '\0';
	// printf("%s\n", *dest);
	return (j);
}

int		main(void)
{
	char	*str_file;
	char	*mol;
	int		i;
	int		size;
	int		min;

	str_file = extract_file("input.txt");
	strchr(str_file, '\n')[0] = '\0';

	i = 'a';
	min = INT_MAX;
	while (i <= 'z')
	{
		size = new_mol(&mol, str_file, i);
		min = MIN(size - destroyed_amount(mol, size) * 2, min);
		i++;
	}

	answer(d, min)
	return (0);
}
