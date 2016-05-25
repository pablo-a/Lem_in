/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_pathes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:18 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 18:58:49 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

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

int		print_ant(t_ant *ant, t_room *room, int flag)
{
	if (flag)
		ft_printf("L%d-%s ", ant->id, room->name);
	else
		ft_printf("L%d-%s\n", ant->id, room->name);
	return (1);
}

int		move_ants(t_env *env)
{
	int		nb_path_use;

	nb_path_use = how_many_path_to_use(env);
	while (its_over(env) == 0)
		move_one_turn(env, nb_path_use);
	ft_printf("\n");
	return (1);
}
