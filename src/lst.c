/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:18:40 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 13:17:25 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

t_links	*new_pile(void)
{
	t_links	*pile;

	pile = (t_links *)malloc(sizeof(*pile));
	if (pile == NULL)
		return (0);
	pile->lenght = 0;
	pile->first = NULL;
	pile->last = NULL;
	return (pile);
}

int		pile_append(t_links *pile, t_room *room)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	node->room = room;
	node->next = NULL;
	if (pile->first != NULL)
	{
		node->prev = pile->last;
		pile->last->next = node;
		pile->last = node;
	}
	else
	{
		node->prev = NULL;
		pile->first = node;
		pile->last = node;
	}
	pile->lenght++;
	return (1);
}

int		pile_prepend(t_links *pile, t_room *room)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	node->room = room;
	node->prev = NULL;
	if (pile->first != NULL)
	{
		pile->first->prev = node;
		node->next = pile->first;
		pile->first = node;
	}
	else
	{
		node->next = NULL;
		pile->first = node;
		pile->last = node;
	}
	pile->lenght++;
	return (1);
}

int		free_pile(t_links **pile)
{
	t_node *temp;
	t_node *del;

	if (*pile != NULL)
	{
		temp = (*pile)->last;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->prev;
			free(del);
		}
	}
	free(*pile);
	*pile = NULL;
	return (1);
}
