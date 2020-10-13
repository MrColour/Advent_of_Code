/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_02_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:52:51 by home              #+#    #+#             */
/*   Updated: 2020/10/12 21:48:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		l, w, h;
	int		total_paper;
	char	*str_file;

	total_paper = 0;
	str_file = extract_file("input.txt");

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &l);
		_tok += fetch_int(_tok, &w);
		_tok += fetch_int(_tok, &h);

		total_paper += (2 * l * w) + (2 * w * h) + (2 * h * l);
		total_paper += MIN(MIN((l * w), (w * h)), (h * l));
	)

	answer(d, total_paper);
	return (0);
}
