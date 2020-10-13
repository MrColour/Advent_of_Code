/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_12_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:49:15 by home              #+#    #+#             */
/*   Updated: 2020/10/13 00:40:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		array(char *str, int *i);

int		curly(char *str, int *i)
{
	int		result;
	bool	red;

	red = false;
	result = 0;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != '}')
	{
		if (str[*i] == 'r' && str[*i + 1] == 'e' && str[*i + 2] == 'd')
			red = true;

		if (str[*i] == '-' || isdigit(str[*i]))
		{
			result += atoi(&str[*i]);
			*i += strspn(&str[*i], DIGITS) - 1;
		}
		else if (str[*i] == '{')
			result += curly(str, i);
		else if (str[*i] == '[')
			result += array(str, i);
		(*i)++;
	}

	if (red == true)
		return (0);
	else
		return (result);
}

int		array(char *str, int *i)
{
	int	result;

	result = 0;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != ']')
	{
		if (str[*i] == '-' || isdigit(str[*i]))
		{
			result += atoi(&str[*i]);
			*i += strspn(&str[*i], DIGITS) - 1;
		}
		else if (str[*i] == '{')
			result += curly(str, i);
		else if (str[*i] == '[')
			result += array(str, i);
		(*i)++;
	}
	return (result);
}

int		main(void)
{
	int		i;
	int		result;
	char	*str_file;

	str_file = extract_file("input.txt");

	i = 0;
	result = 0;
	while (str_file[i] != '\0')
	{
		if (str_file[i] == '-' || isdigit(str_file[i]))
		{
			result += atoi(&str_file[i]);
			i += strspn(&str_file[i], DIGITS) - 1;
		}
		else if (str_file[i] == '{')
			result += curly(str_file, &i);
		else if (str_file[i] == '[')
			result += array(str_file, &i);

		i++;
	}
	answer(d, result);
	return (0);
}