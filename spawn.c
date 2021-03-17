/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:53:28 by home              #+#    #+#             */
/*   Updated: 2020/11/30 21:37:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* USAGE:go into the year you are working at and run the compiled file as
* `./a.out YEAR DAY` where YEAR is a number between 2015 and 2019 and
* DAY is a number between 1 or 25.
*/

#include <stdio.h> // asprintf
#include <assert.h> //assert
#include <stdlib.h> //aoti
#include <sys/stat.h> //mkdir
#include <unistd.h> //chdir
#include <fcntl.h> //open

void	make_day(char *s_year, char *s_day)
{
	int		day;
	int		year;
	char	*day_dir;

	day = atoi(s_day);
	year = atoi(s_year);

	assert(0 < day && day <= 25 && "Day argument is out of bounds. Valid range is [1, 25].");
	assert(2015 < year && year <= 2020 && "Year argument is out of bounds. Valid range is [2015, 2019]");

	asprintf(&day_dir, "day_%02d", day);
	mkdir(day_dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	chdir(day_dir);

	int		fd;
	char	*p1_str;
	char	*p2_str;

	asprintf(&p1_str, "p_%d_%02d_01.c", year, day);
	asprintf(&p2_str, "p_%d_%02d_02.c", year, day);
	fd = open(p1_str, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(fd);
	fd = open(p2_str, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(fd);

	char *curl_cmd;

	/* NOTE: requires a file called aoc_cookies.txt that has your aoc account information */
	asprintf(&curl_cmd, "curl --cookie ~/aoc_cookies.txt -o input.txt \"https://adventofcode.com/%d/day/%d/input\"", year, day);
	system(curl_cmd);
}

int		main(int aa, char **args)
{
	assert(aa == 3 && "Insufficient Arguments provided. Please supply a Year and a Day.");
	make_day(args[1], args[2]);
	return (0);
}
