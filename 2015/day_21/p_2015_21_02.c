/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_21_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:03:28 by home              #+#    #+#             */
/*   Updated: 2020/09/10 03:41:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_2015_21_01.h"

t_item	*fetch_worst_items(t_item *weapons, int w_size, t_item *rings, int r_size, int end_att)
{
	int			i;
	int			w_i;
	int			r_i;
	bool		found;

	int			finding;
	int			highest_cost;
	t_item	curr_weapon;
	t_item	*value_weapons;

	i = 0;
	finding = weapons[0].stat;
	value_weapons = calloc(end_att, sizeof(*value_weapons));
	while (finding <= end_att)
	{

		w_i = 0;
		found = false;
		highest_cost = INT32_MIN;
		while (w_i < w_size && weapons[w_i].stat <= finding)
		{
			r_i = 0;
			while (r_i < r_size && rings[r_i].stat + weapons[w_i].stat <= finding)
			{
				curr_weapon.cost = weapons[w_i].cost + rings[r_i].cost;
				curr_weapon.stat = weapons[w_i].stat + rings[r_i].stat;

				if (curr_weapon.stat == finding && curr_weapon.cost > highest_cost)
				{
					found = true;
					highest_cost = curr_weapon.cost;
				}
				r_i++;
			}
			w_i++;
		}

		if (found == true)
		{
			value_weapons[i].stat = finding;
			value_weapons[i].cost = highest_cost;
			value_weapons[i].valid = true;
		}
		finding++;
		i++;
	}
	return (value_weapons);
}

bool		viable_strategy(t_item armour, t_item weapon, t_boss boss)
{
	int		i;
	int		hp;
	int		temp;

	i = 0;
	hp = 100;
	while (boss.hp > 1 && hp > 1)
	{
		if (i % 2 == 0)
		{
			temp = weapon.stat - boss.def;
			boss.hp -= ((temp > 0) ? temp : 1);
		}
		else
		{
			temp = boss.att - armour.stat;
			hp -= ((temp > 0) ? temp : 1);
		}
		i++;
	}

	if (boss.hp <= 0)
		return (true);
	else
		return (false);
}

int		main(void)
{
	t_boss	boss;
	char	*str_file;
	char	*s_tok;

	str_file = extract_file("input.txt");

	s_tok = strpbrk(str_file, "1234567890-");
	boss.hp = atoi(s_tok);

	s_tok += strspn(s_tok, "1234567890-");
	s_tok = strpbrk(s_tok, "1234567890-");
	boss.att = atoi(s_tok);

	s_tok += strspn(s_tok, "1234567890-");
	s_tok = strpbrk(s_tok, "1234567890-");
	boss.def = atoi(s_tok);

	t_item	*worst_weapons;
	t_item	weapons[5];
	t_item	a_rings[4];

	weapons[0] = (t_item){ 8, 4, true};
	weapons[1] = (t_item){10, 5, true};
	weapons[2] = (t_item){25, 6, true};
	weapons[3] = (t_item){40, 7, true};
	weapons[4] = (t_item){74, 8, true};

	a_rings[0] = (t_item){ 0,  0, true};
	a_rings[1] = (t_item){25,  1, true};
	a_rings[2] = (t_item){50,  2, true};
	a_rings[3] = (t_item){100, 3, true};
	worst_weapons = fetch_worst_items(weapons, 5, a_rings, 4, 11);

	t_item	*worst_armour;
	t_item	armour[6];
	t_item	d_rings[4];

	armour[0] = (t_item){ 0,  0, true};
	armour[1] = (t_item){13,  1, true};
	armour[2] = (t_item){31,  2, true};
	armour[3] = (t_item){53,  3, true};
	armour[4] = (t_item){75,  4, true};
	armour[5] = (t_item){102, 5, true};

	d_rings[0] = (t_item){ 0, 0, true};
	d_rings[1] = (t_item){20, 1, true};
	d_rings[2] = (t_item){40, 2, true};
	d_rings[3] = (t_item){80, 3, true};
	worst_armour = fetch_worst_items(armour, 6, d_rings, 4, 8);

	int		w_i;
	int		a_i;
	int		highest_cost;
	int		temp;

	w_i = 0;
	highest_cost = INT32_MIN;
	while (w_i < 11)
	{
		a_i = 0;
		while (a_i < 8)
		{
			if (worst_armour[a_i].valid == true && worst_weapons[w_i].valid == true)
			{
				temp = worst_armour[a_i].cost + worst_weapons[w_i].cost;
				if (viable_strategy(worst_armour[a_i], worst_weapons[w_i], boss) == false && temp > highest_cost)
					highest_cost = temp;
			}
			a_i++;
		}
		w_i++;
	}
	printf("RESULT: %d\n", highest_cost);
	return (0);
}