/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_09_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:18:45 by home              #+#    #+#             */
/*   Updated: 2020/09/17 20:46:38 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int		main(void)
{
	int		i;
	int		len;

	int		forward;
	int		times;
	char	*str_file;

	str_file = extract_file("input.txt");

	i = 0;
	len = 0;
	while (str_file[i] != '\0' && str_file[i] != '\n')
	{
		if (str_file[i] == '(')
		{
			i += fetch_int(&str_file[i], &forward);
			i += fetch_int(&str_file[i], &times);

			len += (forward * times);
			i += forward;
		}
		else
			len++;
		i++;
	}
	printf("RESULT: %d\n", len);
	return (0);
}
