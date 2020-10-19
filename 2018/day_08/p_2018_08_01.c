/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_08_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:22:54 by home              #+#    #+#             */
/*   Updated: 2020/10/19 00:03:55 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	recurse(char *str, int *index, int *result)
{
	int		i;
	int		children;
	int		meta_data;
	int		tmp;

	*index += fetch_int(&str[*index], &children);
	*index += fetch_int(&str[*index], &meta_data);

	i = 0;
	while (i < children)
	{
		recurse(str, index, result);
		i++;
	}

	i = 0;
	while (i < meta_data)
	{
		*index += fetch_int(&str[*index], &tmp);
		*result += tmp;
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	int		result;
	int		index;

	str_file = extract_file("input.txt");

	index = 0;
	recurse(str_file, &index, &result);
	answer(d, result)
	return (0);
}
