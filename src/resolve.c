/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:03:04 by pabril            #+#    #+#             */
/*   Updated: 2016/05/23 17:08:48 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

#define LINK current_pos->links

int		possible_to_resolve(t_env *env, t_room *current_pos)
{
	t_node	*current_voisin;

	if (current_pos->type == EXIT)
		return (1);
	current_pos->visite = 1;
	if (LINK != NULL)
	{
		current_voisin = LINK->first;
		while (current_voisin != NULL)
		{
			if (current_voisin->room->visite == 0)
				if (possible_to_resolve(env, current_voisin->room) == 1)
				{
					current_pos->visite = 0;
					return (1);
				}
			current_voisin = current_voisin->next;
		}
	}
	current_pos->visite = 0;
	return (0);
}

int		resolve(t_env *env)
{
	if (env->starting_room == NULL || env->ending_room == NULL)
		wrong_map();
	if (!possible_to_resolve(env, env->starting_room))
		ERROR("impossible a resoudre : bad map");
	init_ants(env);
	set_shortest_path(env, env->starting_room);
	return (1);
}
