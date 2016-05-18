/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:16:23 by pabril            #+#    #+#             */
/*   Updated: 2016/05/18 10:29:31 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

int		main(void)
{
	t_env	env;
	int		i;

	i = 0;
	init_env(&env);
	parse(&env);
	/*
	while (i < 1024)
	{
		if (env.tab_room[i] != NULL)
		{
			ft_printf("room name = %s\n", (env.tab_room[i])->name);
		}
		i++;
	}
	*/
	return (0);
}
