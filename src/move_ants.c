/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_pathes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:18 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 19:01:50 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

int		how_many_path_to_use(t_env *env)
{
	int		result;

	result = 1;
	return (result);
}

int		move_one_turn(t_env *env, int nb)
{
	t_path		*curr_path;
	t_node_path	*node;
	int			flag;

	curr_path = env->pathes->first;
	while (nb > 0)
	{
		node = curr_path->first;
		flag = 1;
		while (node->room->type != ENTRY)
		{
			if (nb == 1 && NEXT_ROOM(node)->type == ENTRY)
				flag = 0;
			if (NEXT_ROOM(node)->type == ENTRY && ANT(NEXT_ROOM(node)) != NULL
					&& (ANT(node->room) == NULL || node->room->type == EXIT))
			{
				ANT(node->room) = ANT(NEXT_ROOM(node));
				ANT(NEXT_ROOM(node))->location = node->room;
				ANT(NEXT_ROOM(node)) = ANT(NEXT_ROOM(node))->next;
				print_ant(node->room->id_ant, node->room, flag);
			}
			else if (NEXT_ROOM(node)->id_ant != NULL && (ANT(node->room) ==
						NULL || node->room->type == EXIT))
			{
				ANT(node->room) = ANT(NEXT_ROOM(node));
				ANT(NEXT_ROOM(node))->location = node->room;
				ANT(NEXT_ROOM(node)) = NULL;
				print_ant(ANT(node->room), node->room, flag);
			}
			node = node->next;
		}
		nb--;
		curr_path = curr_path->next_path;
	}
	return (0);
}
