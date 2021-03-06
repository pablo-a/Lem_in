/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:09:14 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 12:51:45 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			hash(char *str)
{
	return (ft_strhash(str) % SIZE_TAB);
}

t_hashtable	*create_table(int size)
{
	t_hashtable	*table;
	int			i;

	i = 0;
	if ((table = (t_hashtable *)malloc(sizeof(*table))) == NULL)
		return (NULL);
	if ((table->tab = (t_room **)malloc(sizeof(t_room *) * size)) == NULL)
		return (NULL);
	table->size = size;
	while (i < SIZE_TAB)
	{
		table->tab[i] = NULL;
		i++;
	}
	return (table);
}

int			insert_tab(char *key, t_room *room, t_env *env)
{
	int		index;
	t_room	*tempo;

	index = hash(key);
	if (ROOM(index) == NULL)
		ROOM(index) = room;
	else
	{
		tempo = ROOM(index);
		while (tempo->collision != NULL && ft_strcmp(tempo->name, key) != 0)
			tempo = tempo->collision;
		if (ft_strcmp(tempo->name, key) == 0)
			return (0);
		tempo->collision = room;
	}
	return (1);
}

t_room		*find_room(char *key, t_env *env)
{
	int		index;
	t_room	*tempo;

	index = hash(key);
	if (ROOM(index) == NULL)
		return (NULL);
	tempo = ROOM(index)->collision;
	if (ft_strcmp(ROOM(index)->name, key) == 0)
		return (ROOM(index));
	else
	{
		while (ft_strcmp(tempo->name, key) != 0)
			tempo = tempo->collision;
		return (tempo);
	}
}
