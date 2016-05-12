/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:16:23 by pabril            #+#    #+#             */
/*   Updated: 2016/05/12 12:19:53 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"
#include "get_next_line.h"

int		init_env(t_env *env)
{
	t_room	*tab_room[SIZE_TAB];
	t_ant	*ant;

	env->nb_ants = 0;
	env->tab_room = tab_room;
	env->ants = ant;
	return (0);
}

int		main(void)
{
	t_env	env;
	char	*str;

	init_env(&env);
	while (get_next_line(0, &str) > 0)
	{
		printf("%s\n", str);
	}
	return (0);
}
