/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc++.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 00:21:00 by home              #+#    #+#             */
/*   Updated: 2020/10/11 23:30:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC_H
# define AOC_H

#include <ctype.h>
#include <stddef.h> //NULL

#include <stdlib.h> //atoi, bsearch, calloc, malloc, qsort, realloc, system, psort

#include <stdio.h> //fopen, printf (and family), open_memstream. rewind

#include <string.h> //strchr, strcmp, strlen, strncmp, strpbrk, strrchr, strspn,
//					strstr, strtok, strdup, memset_pattern(4, 8, 16), strnstr
//					strsep, strcspn, memset, memmem

#include <stdbool.h> //bool

#include <limits.h> //INT_MIN, INT_MAX

#include <assert.h> //assert

#include <alloca.h> //alloca

#include <math.h>

// Rank: • • • • •

//File functions
// Rank: * * * * *
// char	*extract_file(char *file);
static inline char	*extract_file(char *file) {
	char *str; FILE *fh = fopen(file, "r"); fseek(fh, 0L, SEEK_END); long l = ftell(fh); str = calloc(l + 1, 1), rewind(fh); fread(str, l, 1, fh); return (str);
}

//Compare function to be used with psort and qsort

// Rank: * * * • •
static inline int	int_cmp_asc(const void *a, const void *b) {return ((*(int *)a) < (*(int *)b) ? -1 : 1);}
static inline int	int_cmp_des(const void *a, const void *b) {return ((*(int *)a) > (*(int *)b) ? -1 : 1);}
static inline int	str_cmp(const void *a, const void *b) {return ( strcmp((*(char **)a) , (*(char **)b) ));}
static inline int	char_cmp_asc(const void *a, const void *b) { return ((*(char *)a > *(char *)b) ? 1 : -1); }
static inline int	char_cmp_des(const void *a, const void *b) { return ((*(char *)a < *(char *)b) ? 1 : -1); }

//String utility functions

#define DIGITS "0123456789-"
#define HEX "0123456789abcdef"
#define LOW_ALPHA "abcdefghijklmnopqrstuvwxyz"

// Rank: * * * * *
static inline int	count_occur(char *key, char *src) {int occur = 0; int l = strlen(key); while ((src = strstr(src, key)) != NULL) {occur++; src += l;} return (occur);}
// Rank: * * * * *
static inline int	fetch_int(char *src, int *dest) {
	char *ptr = src; ptr += strcspn(ptr, DIGITS); *dest = atoi(ptr); ptr += strspn(ptr, DIGITS); return (ptr - src);
}
// Rank: • • • • •
static inline int	skip_char(char *src, int times, char c) {
	char *ptr = src - 1; while (times > 0 && ptr != NULL) {times--; ptr = strchr(ptr + 1, c); } return (ptr - src);
}
static inline int	skip_space(char *src, int times) { return (skip_char(src, times, ' '));
}

// Rank: • • • • •
static inline void	strr(char *str) { int i = 0; int j = strlen(str) - 1; char t; while (i < j) { t = str[i]; str[i] = str[j]; str[j] = t; i++; j--;} }
// static inline void	strr(char *str) { int i = 0; int j = strlen(str) - 1; while (i < j) {asm("mov %1, %0" : "=r" (str[i]) : "r" (str[j])); i++; j--;} }

//Other

// Rank: * * * • •
static inline int	MIN(int a, int b) {return ((a < b) ? a : b);}
static inline int	MAX(int a, int b) {return ((a > b) ? a : b);}

// Rank: * * • • •
// left <= x <= right
static inline bool	bound(int l, int x, int r) {return ((l <= x && x <= r) ? true : false);}
static inline bool	bound_box(int l, int x, int r, int b, int y, int t) {return (((l <= x && x <= r) && (b <= y && y <= t)) ? true : false);}

// Rank: * • • • •
// left <= x <= right
static inline int	restrict_val(int l, int val, int u) { if (val < l) return (l); if (val > u) return (u); return (val); }

enum	e_direction
{
	UP =	0,
	DOWN =	1,
	LEFT =	2,
	RIGHT =	3,
};

// Rank: * * • • •
// Keypad: UDLR in this order.
static inline void	direction(char *dir_pad, char key,int *x, int *y)
{
	if		(dir_pad[UP  ] == key)	(*y)++;
	else if (dir_pad[DOWN] == key)	(*y)--;
	else if (dir_pad[LEFT] == key)	(*x)--;
	else if (dir_pad[RIGHT] == key) (*x)++;
}

// Rank: • • • • •
static inline bool	unique_int(int num) {
	int set[10] = { 0 }; int temp; while (num != 0) { temp = num % 10; temp = (temp < 0 ? -1 * temp : temp); set[temp]++; if (set[temp] >= 2) break ; num /= 10; } return ((set[temp] <= 1) ? true : false);
}

//Rank: * * * • •
// Creates a temp variable of type <type> with a unique name, given by
// a tokenization of __LINE__ and __FILE__. Uses this temp variable to
// swap, on the STACK, the information of first and second.
// Warning: need to double check on the temp name, to ensure it is unique, but so far it passes test.
# define SWAP(first, second, type) { type __LINE__##__FILE__##_temp = first; first = second; second = __LINE__##__FILE__##_temp; }

# define answer(type, result) printf("Your puzzle answer is %"#type".\n", result);

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

	void		*meta;			// Meta information, used in case other information needs to be passed along
}				t_alloc_meta;

static t_alloc_meta g_ameta = {
	.iter_addr = NULL,
	.index = NULL,

	.s_delim =  NULL,
	.e_delim = NULL,

	.meta = NULL,
};

static inline void	*calloc_wrapper(t_alloc_meta *alloc_info __attribute__((unused)), size_t count, size_t elem_size)
{ return (calloc(count, elem_size)); }

static inline void	*strtok_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{	char *s_tok;

	s_tok = *(char **)(alloc_info->iter_addr);
	*(alloc_info->iter_addr) = strtok(NULL, alloc_info->e_delim);
	return (s_tok);}

static inline void	*strsplit_alloc(t_alloc_meta *alloc_info, size_t count __attribute__((unused)), size_t elem_size __attribute__((unused)))
{
	char *str_s; char *str_e;

	if (alloc_info->s_delim == NULL) { str_s = *(char **)alloc_info->iter_addr; }
	else {
		str_s = NULL;
		if (*(alloc_info->iter_addr) != NULL)
			str_s = strpbrk(*(alloc_info->iter_addr), alloc_info->s_delim);
		if (str_s != NULL) { str_s[0] = '\0'; str_s++; *alloc_info->iter_addr = str_s;}
	}

	if (*alloc_info->iter_addr != NULL)
	{
		strsep((char **)alloc_info->iter_addr, alloc_info->e_delim);
		(*alloc_info->index)++;
	}
	return (str_s);
}

// Variables that a macro has to make need to become global so that
// macros may re-use the same symbol name. It may be possible to
// sidestep this with the usage of __LINE__ and __FILE__ however
// to ensure a unique symbol name.

static char	*_internal_src_cpy;
static int	_internal_alloc_index;

# define ALLOC_1D(name, row, alloc_func, alloc_data)				\
	name = calloc(row + 1, sizeof(*name));							\
	for (int _iname = 0; _iname < row; _iname++) {					\
	_internal_src_cpy = alloc_func(alloc_data, 1, sizeof(*name));	\
		memmove(&name[_iname], _internal_src_cpy, sizeof(*name));	\
		free(_internal_src_cpy);									\
	};																\

# define ALLOC_2D(name, row, col, alloc_func, alloc_data)			\
	name = calloc(row + 1, sizeof(*name));							\
	for (int _iname = 0; _iname < row; _iname++) {					\
		name[_iname] = alloc_func(alloc_data, col, sizeof(**name));	\
	};																\

// Rank: * * * * •
# define NEWLINE_SPLIT(dst, src, len)								\
	STR_SPLIT(dst, src, NULL, "\n", len)							\

// Rank: * * • • •
# define STR_SPLIT(dst, src, s_lim, e_lim, len)						\
	_internal_src_cpy = src;										\
	_internal_alloc_index = 0;										\
	len = count_occur(e_lim, _internal_src_cpy) + 1;				\
																	\
	g_ameta.iter_addr = (void **)(&_internal_src_cpy);				\
	g_ameta.index = &_internal_alloc_index;							\
	g_ameta.s_delim = s_lim;										\
	g_ameta.e_delim = e_lim;										\
	ALLOC_2D(dst, len, 0, strsplit_alloc, &g_ameta);				\
	len = *g_ameta.index;											\

char	*_tok;
int		_i;

# define FOR_EACH_STRTOK(src, delim, body) 							\
{																	\
	_tok = strtok(src, delim); _i = 0;								\
	while (_tok != NULL) { body; _tok = strtok(NULL, delim); ++_i;}	\
}																	\

# define FOR_EACH(condition, body)									\
{																	\
	_i = 0;															\
	while (condition) { body; ++_i;}								\
}																	\

#endif
