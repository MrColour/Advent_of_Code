/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_07.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:28:19 by kmira             #+#    #+#             */
/*   Updated: 2019/12/07 17:25:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAY_07_H
# define DAY_07_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PHASE_A 0
# define PHASE_B 1
# define PHASE_C 2
# define PHASE_D 3
# define PHASE_E 4

# define VIRTUAL_MEMORY_SIZE 10000

# define EXPECTED 19690720
# define STD_OUT 0
# define STD_IN 1


# define READ 0
# define PHASE 1

void	operation_01(int *process, int *reg, int *ptr);
void	operation_02(int *process, int *reg, int *ptr);
void	operation_05(int *process, int *reg, int *ptr);
void	operation_06(int *process, int *reg, int *ptr);
void	operation_07(int *process, int *reg, int *ptr);
void	operation_08(int *process, int *reg, int *ptr);

void	clear_reg(int *registers, int size);
int		get_value(int *memory, int mode, int value);
int		get_input(int op, int amp);

extern int		g_output[];
extern int		g_halts[];
extern int		g_first[];
extern int		g_ptr[];
extern int		g_phase_setting[];

#endif
