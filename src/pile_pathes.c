/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_pathes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:51:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 13:17:23 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*new_path(void)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(*path));
	if (path == NULL)
		return (NULL);
	path->len = 0;
	path->next_path = NULL;
	path->prev_path = NULL;
	path->first = NULL;
	path->last = NULL;
	return (path);
}

int		append_path(t_path_pile *pile_path, t_path *path)
{
	if (pile_path->first != NULL)
	{
		path->prev_path = pile_path->last;
		pile_path->last->next_path = path;
		pile_path->last = path;
	}
	else
	{
		path->prev_path = NULL;
		pile_path->first = path;
		pile_path->last = path;
	}
	pile_path->nb_path++;
	return (1);
}

int		append_node_path(t_path *path, t_room *room)
{
	t_node_path	*node;

	node = (t_node_path *)malloc(sizeof(*node));
	node->room = room;
	node->next = NULL;
	if (path->first != NULL)
	{
		node->prev = path->last;
		path->last->next = node;
		path->last = node;
	}
	else
	{
		node->prev = NULL;
		path->first = node;
		path->last = node;
	}
	path->len++;
	return (1);
}
