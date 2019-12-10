/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_09.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:28:19 by kmira             #+#    #+#             */
/*   Updated: 2019/12/09 15:27:01 by kmira            ###   ########.fr       */
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

void	operation_01(long *process, long *reg, long *ptr, long relative_base);
void	operation_02(long *process, long *reg, long *ptr, long relative_base);
void	operation_05(long *process, long *reg, long *ptr, long relative_base);
void	operation_06(long *process, long *reg, long *ptr, long relative_base);
void	operation_07(long *process, long *reg, long *ptr, long relative_base);
void	operation_08(long *process, long *reg, long *ptr, long relative_base);

void	clear_reg(long *registers, long size);
long	get_value(long *memory, long mode, long value, long relative_base);
void	reset(void);

extern long		g_output[];
extern long		g_halts[];
extern long		g_first[];
extern long		g_ptr[];
extern long		g_phase_setting[];

#endif
