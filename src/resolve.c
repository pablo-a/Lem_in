/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:03:04 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 15:48:30 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"

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

int		get_marked_path(t_env *env, t_room *current_pos)
{
	t_path	*path;

	path = new_path();
	append_node_path(path, current_pos);
	while (current_pos->type != ENTRY)
	{
		append_node_path(path, current_pos);
		current_pos = PERE(current_pos);
	}
	append_node_path(path, current_pos);
	append_path(env->pathes, path);
	return (1);
}

int		show_pathes(t_env *env)
{
	t_path		*path;
	t_node_path	*node;

	ft_printf("%d path trouvees.\n", env->pathes->nb_path);
	path = env->pathes->first;
	while (path != NULL)
	{
		node = path->last;
		while (node->prev != NULL)
		{
			ft_printf(" ==> %s", node->room->name);
			node = node->prev;
		}
		ft_printf("\n");
		path = path->next_path;
	}
	return (1);
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
			if (VISITE(current_voisin->room) < num && (POIDS(current_pos) + 1 <
			POIDS(current_voisin->room) || POIDS(current_voisin->room) == -1))
			{
				POIDS(current_voisin->room) = POIDS(current_pos) + 1;
				PERE(current_voisin->room) = current_pos;
			}
			if ((next_room == NULL || (POIDS(current_voisin->room) <
				POIDS(next_room))) && VISITE(current_voisin->room) < num)
				next_room = current_voisin->room;
			current_voisin = current_voisin->next;
		}
		if (next_room != NULL)
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
		wrong_map();
	init_ants(env);
	init_pathes(env);
	while (mark_path(env, numero_path, env->starting_room) &&
			(size_t)env->ending_room->visite == numero_path)
	{
		get_marked_path(env, env->ending_room);
		numero_path++;
	}
	show_tab(*env);
	show_pathes(env);
	return (1);
}
