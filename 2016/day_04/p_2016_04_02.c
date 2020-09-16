/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2016_04_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:26:58 by home              #+#    #+#             */
/*   Updated: 2020/09/15 22:45:36 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

bool	is_str_decoy(char *str, char *checksum)
{
	bool	decoy;
	int		i;
	int		j;
	int		occur;
	int		place;
	char	hash[256] = { 0 };

	i = 0;
	while (str[i] != '\0')
	{
		hash[(int)str[i]]++;
		i++;
	}

	i = 0;
	decoy = false;
	while (checksum[i] != '\0' && decoy == false)
	{
		j = 0;
		place = 0;
		occur = hash[(int)checksum[i]];
		while (j < (int)sizeof(hash))
		{
			if (isalpha(j) && j != checksum[i])
			{
				if (hash[j] > occur)
					place++;
				if (hash[j] == occur && j < checksum[i])
					place++;
			}
			j++;
		}

		if (place > 4)
			decoy = true;
		i++;
	}

	return (decoy);
}

void	decrypt(char *str, int rotate)
{
	int		i;
	int		l_rot;

	i = 0;
	l_rot = rotate % 26;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
		{
			str[i] += l_rot - 'a';
			str[i] %= 26;
			str[i] += 'a';
		}
		else
		{
			if (rotate % 2 == 1)
			{
				if (str[i] == '-')
					str[i] = ' ';
				else
					str[i] = '-';
			}
		}
		i++;
	}
}

int		main(void)
{
	char	*str_file;
	char	*s_tok;
	char	*ptr;
	bool	decoy;
	int		num;
	int		result;

	result = 0;
	str_file = extract_file("input.txt");
	s_tok = strtok(str_file, "\n");
	while (s_tok != NULL)
	{
		ptr = s_tok;

		s_tok += strcspn(s_tok, "1234567890");
		s_tok[-1] = '\0';
		s_tok += fetch_int(s_tok, &num);
		s_tok++;
		s_tok[5] = '\0';

		// printf("E: %s, N: %d, C: %s\n", ptr, num, s_tok);
		decoy = is_str_decoy(ptr, s_tok);
		if (decoy == false)
		{
			decrypt(ptr, num);
			if (strncmp(ptr, "north", 5) == 0)
			{
				result = num;
				break ;
			}
		}

		s_tok = strtok(NULL, "\n");
	}

	// decoy = is_str_decoy("totally-real-room", "decoy");
	// if (decoy == false)
	// 	printf("Not a decoy\n");
	// else
	// 	printf("IS decoy\n");

	printf("RESULT: %d\n", result);
	return (0);
}
