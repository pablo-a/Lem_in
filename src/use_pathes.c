/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_pathes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:18 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 12:14:47 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		reset_poids(t_env *env)
{
	t_path		*path;
	t_node_path	*node;

	path = env->pathes->first;
	while (path != NULL)
	{
		node = path->last;
		while (node != NULL)
		{
			if (POIDS(node->room) != 0)
				POIDS(node->room) = -1;
			if (node->room->type != EXIT)
				VISITE(node->room)++;
			node = node->prev;
		}
		path = path->next_path;
	}
	return (1);
}

int		how_many_path_to_use(t_env *env)
{
	int		result;

	result = 0;
	return (result);
}

int		its_over(t_env *env)
{
	t_ant	*lst_ant;

	lst_ant = env->lst_ants;
	while (lst_ant != NULL)
	{
		if (lst_ant->location->type != EXIT)
			return (0);
		lst_ant = lst_ant->next;
	}
	return (1);
}

int		move_one_turn(t_env *env, int nb)
{
	return (0);
}

int		move_ants(t_env *env)
{
	int		nb_path_use;

	nb_path_use = how_many_path_to_use(env);
	while (!its_over(env))
		move_one_turn(env, nb_path_use);
	return (1);
}
