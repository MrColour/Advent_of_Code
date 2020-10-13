/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_02_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:52:51 by home              #+#    #+#             */
/*   Updated: 2020/10/12 21:50:54 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../aoc++.h"

int	main(void)
{
	int		l, w, h;
	int		total_ribbon;
	char	*str_file;

	total_ribbon = 0;
	str_file = extract_file("input.txt");

	FOR_EACH_STRTOK(str_file, "\n",
		_tok += fetch_int(_tok, &l);
		_tok += fetch_int(_tok, &w);
		_tok += fetch_int(_tok, &h);

		total_ribbon += (l * w * h);
		total_ribbon += (MIN(MIN((l + w), (w + h)), (h + l))) * 2;
	)

	answer(d, total_ribbon);
	return (0);
}
