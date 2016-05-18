/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:16:23 by pabril            #+#    #+#             */
/*   Updated: 2016/05/18 13:17:19 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

int		main(void)
{
	t_env	env;
	int		i;
	t_node	*test;

	i = 0;
	init_env(&env);
	parse(&env);
	while (i < 1024)
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
				ft_printf("\n");
			}
		}
		i++;
	}
	return (0);
}
