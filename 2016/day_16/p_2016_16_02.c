/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_16_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:53:53 by home              #+#    #+#             */
/*   Updated: 2020/10/15 01:31:25 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

void	replace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
		i++;
	}
}

char	*fill_disk(char *input, int cap)
{
	int		curr_size;
	char	*s_curve;
	char	*r_str;

	s_curve = strdup(input);
	curr_size = strlen(input);
	while (curr_size < cap)
	{
		r_str = strdup(s_curve);
		strr(r_str);
		replace(r_str);

		asprintf(&s_curve, "%s0%s", s_curve, r_str);

		curr_size = strlen(s_curve);
	}

	s_curve[cap] = '\0';
	return (s_curve);
}

char	*checksum(char *disk)
{
	int		i;
	int		j;
	char	*result;

	result = disk;
	while (strlen(result) % 2 == 0)
	{
		i = 0;
		j = 0;
		while (result[i] != '\0' && result[i + 1] != '\0')
		{
			if (result[i] == result[i + 1])
				result[j] = '1';
			else
				result[j] = '0';

			i += 2;
			j++;
		}

		result[j] = '\0';
	}
	return (result);
}

int		main(void)
{
	char	*input;
	char	*disk;
	char	*result;

	input = extract_file("input.txt");
	strchr(input, '\n')[0] = '\0';

	disk = fill_disk(input, 35651584);
	result = checksum(disk);

	printf("%s\n", result);
	return (0);
}
