/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc++.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 00:21:00 by home              #+#    #+#             */
/*   Updated: 2020/09/28 03:55:00 by home             ###   ########.fr       */
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
	char *str; FILE *fh = fopen(file, "r"); fseek(fh, 0L, SEEK_END); long l = ftell(fh); str = malloc(l + 1), rewind(fh); fread(str, l, 1, fh); return (str);
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
int		_min(int a, int b) {return ((a < b) ? a : b);}
int		_max(int a, int b) {return ((a > b) ? a : b);}

// Rank: * * • • •
// left <= x <= right
bool	bound(int l, int x, int r) {return ((l <= x && x <= r) ? true : false);}
bool	bound_box(int l, int x, int r, int b, int y, int t) {return (((l <= x && x <= r) && (b <= y && y <= t)) ? true : false);}

// Rank: • • • • •
bool	unique_int(int num) {
	int set[10] = { 0 }; int temp; while (num != 0) { temp = num % 10; temp = (temp < 0 ? -1 * temp : temp); set[temp]++; if (set[temp] >= 2) break ; num /= 10; } return ((set[temp] <= 1) ? true : false);
}

# define SWAP(first, second, type) type __LINE__##__FILE__##_temp = first; first = second; second = __LINE__##__FILE__##_temp;

// The below is a macro so that the variable itself can be dereferenced.
// If it were a function, one would have to pass sizeof(*var) and sizeof(**var)
//
// One could however argue that on most modern architechtures the size of pointers
// themselves are always 8. But this can be side stepped with macros so why not.


typedef	struct	_alloc_meta
{
	void		**iter_addr;	// The address of where the iter is, not the iter itself.
	int			*index;			// What index is currently bieng used.

	void		*s_delim;		// Information about the start condition of the delimit.
	void		*e_delim;		// Information about the end condition of the delimit.
}				t_alloc_meta;

t_alloc_meta g_ameta = {
	.iter_addr = NULL,
	.index = NULL,

	.s_delim =  NULL,
	.e_delim = NULL,
};

void	*calloc_wrapper(t_alloc_meta *alloc_info __attribute__((unused)), size_t count, size_t elem_size)
{ return (calloc(count, elem_size)); }

void	*strtok_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{	char *s_tok;

	s_tok = *(char **)(alloc_info->iter_addr);
	*(alloc_info->iter_addr) = strtok(NULL, alloc_info->s_delim);
	return (s_tok);}

void	*strsplit_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{
	char *str_s; char *str_e;

	if (alloc_info->s_delim == NULL) { str_s = *(char **)alloc_info->iter_addr; }
	else {
		str_s = strpbrk(*(alloc_info->iter_addr), alloc_info->s_delim) + 1;
		str_s[-1] = '\0';
	}

	str_e = strpbrk(str_s, alloc_info->e_delim);
	str_e[0] = '\0';

	*(alloc_info->iter_addr) = str_e + 1;
	(*alloc_info->index)++;
	return (str_s);}

# define ALLOC_2D(name, row, col, alloc_func, alloc_data)			\
	name = calloc(row + 1, sizeof(*name));							\
	for (int i = 0; i < row; i++) {									\
		name[i] = alloc_func(alloc_data, col, sizeof(**name));		\
	};																\

# define NEWLINE_SPLIT(dst, src, len)								\
	STR_SPLIT(dst, src, NULL, "\n", len)							\

// Variables that a macro has to make need to become global so that
// macros may re-use the same symbol name. It may be possible to
// sidestep this with the usage of __LINE__ and __FILE__ however
// to ensure a unique symbol name.

char	*_internal__src_cpy;
int		_internal__alloc_index;

# define STR_SPLIT(dst, src, s_lim, e_lim, len)						\
	_internal__src_cpy = src;										\
	_internal__alloc_index = 0;										\
	len = count_occur(e_lim, _internal__src_cpy);					\
																	\
	g_ameta.iter_addr = (void **)(&_internal__src_cpy);				\
	g_ameta.index = &_internal__alloc_index;						\
	g_ameta.s_delim = s_lim;										\
	g_ameta.e_delim = e_lim;										\
	ALLOC_2D(dst, len, 0, strsplit_alloc, &g_ameta);				\
	len = *g_ameta.index;											\

#endif
