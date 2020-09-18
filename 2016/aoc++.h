/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc++.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 00:21:00 by home              #+#    #+#             */
/*   Updated: 2020/09/18 02:00:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC_H
# define AOC_H

#include <ctype.h>
#include <stddef.h> //NULL

#include <stdlib.h> //atoi, bsearch, calloc, malloc, qsort, realloc, system, psort

#include <stdio.h> //fopen, printf (and family), open_memstream

#include <string.h> //strchr, strcmp, strlen, strncmp, strpbrk, strrchr, strspn,
//					strstr, strtok, strdup, memset_pattern(4, 8, 16), strnstr
//					strsep, strcspn, memset, memmem
#include <unistd.h> //close, read, write, mkstemp, lseek, rewind

#include <stdbool.h> //bool

#include <limits.h> //INT_MIN, INT_MAX

#include <math.h>

// Rank: • • • • •

//File functions
// Rank: * * * * *
char	*extract_file(char *file) {
	char *str; FILE *fh = fopen(file, "r"); fseek(fh, 0L, SEEK_END); long l = ftell(fh); str = malloc(l), rewind(fh); fread(str, l, 1, fh); return (str);
}

//Compare function to be used with psort and qsort

// Rank: * * * • •
int		int_cmp_asc(const void *a, const void *b) {return ((*(int *)a) < (*(int *)b) ? -1 : 1);}
int		int_cmp_des(const void *a, const void *b) {return ((*(int *)a) > (*(int *)b) ? -1 : 1);}
int		str_cmp(const void *a, const void *b) {return ( strcmp((*(char **)a) , (*(char **)b) ));}

//String utility functions

#define DIGITS "0123456789-"
#define HEX "0123456789abcdef"

// Rank: * * * * *
int		count_occur(char *key, char *src) {int occur = 0; int l = strlen(key); while ((src = strstr(src, key)) != NULL) {occur++; src += l;} return (occur);}
// Rank: * * * * *
int		fetch_int(char *src, int *dest) {
	char *ptr = src; ptr += strcspn(ptr, DIGITS); *dest = atoi(ptr); ptr += strspn(ptr, DIGITS); return (ptr - src);
}
// Rank: • • • • •
int		skip_char(char *src, int times, char c) {
	char *ptr = src - 1; while (times > 0 && ptr != NULL) {times--; ptr = strchr(ptr + 1, c); } return (ptr - src);
}
int		skip_space(char *src, int times) { return (skip_char(src, times, ' '));
}

//Other

// Rank: * * • • •
int		min(int a, int b) {return ((a < b) ? a : b);}
int		max(int a, int b) {return ((a > b) ? a : b);}

// Rank: • • • • •
bool	bound(int l, int c, int r) {return ((l <= c && c <= r) ? true : false);}
bool	bound_box(int l, int x, int r, int b, int y, int t) {return (((l <= x && x <= r) && (b <= y && y <= t)) ? true : false);}

// Rank: • • • • •
bool	unique_int(int num) {
	int set[10] = { 0 }; int temp; while (num != 0) { temp = num % 10; temp = (temp < 0 ? -1 * temp : temp); set[temp]++; if (set[temp] >= 2) break ; num /= 10; } return ((set[temp] <= 1) ? true : false);
}

#endif
