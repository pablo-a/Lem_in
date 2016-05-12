/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:09:14 by pabril            #+#    #+#             */
/*   Updated: 2016/05/12 12:15:20 by pabril           ###   ########.fr       */
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
	int hash;
	int index;

	index = 0;
	hash = hash(str);
	if (tab[hash] == NULL)
		return (hash);
	return (NULL);
}

int		insert_hash(char *str, t_room *room, t_room *tab[SIZE_TAB])
{
	int index;

	if ((index = get_index(str, tab)) != NULL)
	{
		tab[index] = room;
	}
	else
	{
		while ((tab[index])->collision != NULL)
			(tab[index])->collision = (tab[index])->collision->collision;
		(tab[index])->collision = room;
	}
	return (1);
}

t_room	*get_value(char *str, t_room *tab[SIZE_TAB])
{
	int index;

	index = get_index(str);
	if (index != NULL)
		return (tab[index]);
	return (NULL);
}

int		remove(char *str, t_room *tab[SIZE_TAB])
{
	int index;

	index = get_index(str);
	if (index != NULL)
		tab[index] = NULL;
	return (1);
}
