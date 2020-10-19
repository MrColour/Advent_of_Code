/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2018_08_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:22:54 by home              #+#    #+#             */
/*   Updated: 2020/10/19 00:13:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		recurse(char *str, int *index)
{
	int		i;
	int		children;
	int		meta_data;
	int		result;
	int		*childs_res;
	int		tmp;

	*index += fetch_int(&str[*index], &children);
	*index += fetch_int(&str[*index], &meta_data);

	childs_res = calloc(children, sizeof(*childs_res));

	i = 0;
	while (i < children)
	{
		childs_res[i] = recurse(str, index);
		i++;
	}

	i = 0;
	result = 0;
	while (i < meta_data)
	{
		*index += fetch_int(&str[*index], &tmp);
		if (children == 0)
			result += tmp;
		else if (bound(1, tmp, children))
			result += childs_res[tmp - 1];

		i++;
	}
	return (result);
}

int		main(void)
{
	char	*str_file;
	int		result;
	int		index;

	str_file = extract_file("input.txt");

	index = 0;
	result = recurse(str_file, &index);
	answer(d, result)
	return (0);
}
