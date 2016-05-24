/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:03:04 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 11:37:39 by pabril           ###   ########.fr       */
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

int		mark_path(t_env *env, int num, t_room *current_pos)
{
	t_node	*current_voisin;
	t_room	*next_room;

	next_room = NULL;
	VISITE(current_pos) = num;
	if (LINK != NULL)
	{
		current_voisin = LINK->first;
		while (current_voisin != NULL)
		{
			if (VISITE(current_voisin->room) == 0 && (POIDS(current_pos) + 1
				< POIDS(current_voisin) || POIDS(current_voisin == -1)))
			{
				POIDS(current_voisin) = POIDS(current_pos) + 1;
				PERE(current_voisin) = current_pos;
			}
			if (next_room == NULL || (POIDS(current_voisin) < POIDS(next_room)))
				next_room = current_voisin;
			current_voisin = current_voisin->next;
		}
		mark_path(env, num, next_room);
	}
	return (1);
}

int		resolve(t_env *env)
{
	size_t	numero_path;

	numero_path = 1;
	if (env->starting_room == NULL || env->ending_room == NULL)
		wrong_map();
	if (!possible_to_resolve(env, env->starting_room))
		ERROR("impossible a resoudre : bad map");
	init_ants(env);
	while (mark_path(env, numero_path, env->starting_room) == 1)
		get_marked_path(env, &numero_path, env->starting_room);
	return (1);
}
