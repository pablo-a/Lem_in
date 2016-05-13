/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/13 12:19:17 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		init_env(t_env *env)
{
	t_room	*tab_room[SIZE_TAB];

	env->nb_ants = 0;
	ft_memcpy(env->tab_room, tab_room, sizeof(tab_room));
	env->lst_ants = NULL;
	return (0);
}

t_ant	*new_ant(void);
{
	t_ant ant;

	ant.id = 0;
	ant.location = 0;
	ant.next = NULL;
	return (&ant);
}
