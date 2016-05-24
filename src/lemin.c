/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:16:23 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 15:23:28 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

int		show_tab(t_env env)
{
	int		i;
	t_node	*test;

	i = 0;
	while (i < SIZE_TAB)
	{
		if (env.tab_room->tab[i] != NULL)
		{
			ft_printf("room name = %s\n", (env.tab_room->tab[i])->name);
			if ((env.tab_room->tab[i])->links != NULL)
			{
				ft_printf("nb de connections : %d\n", env.tab_room->tab[i]->links->lenght);
				test = env.tab_room->tab[i]->links->first;
				while (test != NULL)
				{
					ft_printf("connecte a la salle %s\n", test->room->name);
					test = test->next;
				}
				ft_printf("visite : %d\n", (env.tab_room->tab[i])->visite);
				if ((env.tab_room->tab[i])->father != NULL)
					ft_printf("fils de : %s\npoids : %d\n", (env.tab_room->tab[i])->father->name, (env.tab_room->tab[i])->poids);
				ft_putstr("\n");
			}
		}
		i++;
	}
	return (1);
}

int		main(void)
{
	t_env	env;

	init_env(&env);
	parse(&env);
	resolve(&env);
	return (0);
}
