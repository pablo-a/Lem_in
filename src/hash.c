/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:09:14 by pabril            #+#    #+#             */
/*   Updated: 2016/05/18 11:13:10 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		hash(char *str)
{
	return (ft_strhash(str) % SIZE_TAB);
}

int		get_index(char *str, t_room *tab[SIZE_TAB])
{
	int index;

	index = 0;
	index = hash(str);
	if (tab[index] == NULL)
		return (index);
	return (-1);
}

int		insert_hash(char *str, t_room *room, t_room *tab[SIZE_TAB])
{
	int index;

	ft_putendl("entre dans la fonction d'insertion hash");
	index = get_index(str, tab);
	if (index != -1)
	{
		ft_putendl("case vide");
		tab[index] = room;
	}
	else
	{
		ft_putendl("case pleine");
		while ((tab[index])->collision != NULL)
			(tab[index])->collision = (tab[index])->collision->collision;
		(tab[index])->collision = room;
	}
	return (1);
}

t_room	*get_value(char *str, t_room *tab[SIZE_TAB])
{
	int index;

	index = get_index(str, tab);
	if (index != -1)
		return (tab[index]);
	return (NULL);
}

int		remove_hash(char *str, t_room *tab[SIZE_TAB])
{
	int index;

	index = get_index(str, tab);
	if (index != -1)
		tab[index] = NULL;
	return (1);
}
