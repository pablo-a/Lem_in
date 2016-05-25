/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_pathes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:51:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 17:21:39 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

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

int		path_compare(t_path *p1, t_path *p2)
{
	t_node_path	*n1;
	t_node_path	*n2;
	int			cpt;

	cpt = 0;
	if (p1->len != p2->len)
		return (0);
	n1 = p1->last;
	n2 = p2->last;
	while (n1 != NULL && n2 != NULL)
	{
		if (ft_strcmp(n1->room->name, n2->room->name) == 0)
			cpt++;
		else
			return (0);
		n1 = n1->prev;
		n2 = n2->prev;
	}
	if (cpt == p1->len)
		return (1);
	return (0);
}

int		same_pathes(t_env *env)
{
	t_path		*path_to_compare;
	t_path		*temp;

	if (env->pathes->nb_path == 0 || env->pathes->nb_path == 1)
		return (0);
	path_to_compare = env->pathes->last;
	temp = env->pathes->first;
	while (temp != path_to_compare)
	{
		if (path_compare(path_to_compare, temp) == 1)
			return (1);
		temp = temp->next_path;
	}
	return (0);
}
