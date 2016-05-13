/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/13 13:57:47 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		init_env(t_env *env)
{
	t_room	*tab_room[SIZE_TAB];

	env->nb_ants = 0;
	ft_memcpy(env->tab_room, tab_room, sizeof(tab_room));
	env->lst_ants = NULL;
	return (0);
}

/*
** parse la ligne definissant la salle, stocke les donnees dans la struct
** puis la stocke dans la table de hash.
*/

int		get_next_space(char *str)
{
	int len;

	len = 0;
	while (str[len] != ' ')
		len++;
	return (len);
}

int		parse_room(t_env *env, t_room *room, char *stri, int type)
{
	int		len;

	len = get_next_space(str);
	ft_strncpy(room->name, str, len);
	room->type = type;
	room->coordx = 0;
	room->coordy = 0;
	room->id_ant = -1;
	room->collision = NULL;
	room->links = NULL;
	insert_hash(room->name, room, env->tab_room);
	return (1);
}

t_links	*init_links(void)
{
	t_links	*link;

	link = (t_links)malloc(sizeof(*link));
	if (link == NULL)
		return (0);
	link->lenght = 0;
	link->first = NULL;
	link->last = NULL;
	return (link);
}

t_ant	*new_ant(void)
{
	t_ant *ant;

	ant = (t_ant)malloc(sizeof(*ant));
	ant->id = 0;
	ant->location = 0;
	ant->next = NULL;
	return (ant);
}
