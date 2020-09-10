/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_2015_21_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:03:28 by home              #+#    #+#             */
/*   Updated: 2020/09/10 03:38:16 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_2015_21_01.h"

t_item	*fetch_value_items(t_item *weapons, int w_size, t_item *rings, int r_size, int end_att)
{
	int			i;
	int			w_i;
	int			r_i;
	bool		found;

	int			finding;
	int			lowest_cost;
	t_item	curr_weapon;
	t_item	*value_weapons;

	i = 0;
	finding = weapons[0].stat;
	value_weapons = calloc(end_att, sizeof(*value_weapons));
	while (finding <= end_att)
	{

		w_i = 0;
		found = false;
		lowest_cost = INT32_MAX;
		while (w_i < w_size && weapons[w_i].stat <= finding)
		{
			r_i = 0;
			while (r_i < r_size && rings[r_i].stat + weapons[w_i].stat <= finding)
			{
				curr_weapon.cost = weapons[w_i].cost + rings[r_i].cost;
				curr_weapon.stat = weapons[w_i].stat + rings[r_i].stat;

				if (curr_weapon.stat == finding && curr_weapon.cost < lowest_cost)
				{
					found = true;
					lowest_cost = curr_weapon.cost;
				}
				r_i++;
			}
			w_i++;
		}

		if (found == true)
		{
			value_weapons[i].stat = finding;
			value_weapons[i].cost = lowest_cost;
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

	t_item	*value_weapons;
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
	value_weapons = fetch_value_items(weapons, 5, a_rings, 4, 11);

	t_item	*value_armour;
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
	value_armour = fetch_value_items(armour, 6, d_rings, 4, 8);

	int		w_i;
	int		a_i;
	int		lowest_cost;
	int		temp;

	w_i = 0;
	lowest_cost = INT32_MAX;
	while (w_i < 11)
	{
		a_i = 0;
		while (a_i < 8)
		{
			if (value_armour[a_i].valid == true && value_weapons[w_i].valid == true)
			{
				temp = value_armour[a_i].cost + value_weapons[w_i].cost;
				if (viable_strategy(value_armour[a_i], value_weapons[w_i], boss) == true && temp < lowest_cost)
					lowest_cost = temp;
			}
			a_i++;
		}
		w_i++;
	}
	printf("RESULT: %d\n", lowest_cost);
	return (0);
}