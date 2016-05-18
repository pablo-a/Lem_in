/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/18 14:18:41 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			init_env(t_env *env)
{
	env->nb_ants = 0;
	env->tab_room = create_table(SIZE_TAB);
	env->lst_ants = NULL;
	return (0);
}

/*
** parse la ligne definissant la salle, stocke les donnees dans la struct
** puis la stocke dans la table de hash.
*/

int			get_next_space(char *str)
{
	int len;

	len = 0;
	while (str[len] != ' ')
		len++;
	return (len);
}

int			parse_room(t_env *env, char *str, int type)
{
	int		len;
	t_room	*room;

	len = get_next_space(str);
	room = (t_room *)malloc(sizeof(*room));
	room->name = ft_strnew(len + 1);
	ft_strncpy(room->name, str, len);
	room->type = type;
	room->coordx = 0;
	room->coordy = 0;
	room->id_ant = -1;
	room->collision = NULL;
	room->links = NULL;
	insert_tab(room->name, room, env);
	return (1);
}

t_links		*init_links(void)
{
	t_links	*link;

	link = (t_links *)malloc(sizeof(*link));
	if (link == NULL)
		return (0);
	link->lenght = 0;
	link->first = NULL;
	link->last = NULL;
	return (link);
}

t_ant		*new_ant(void)
{
	t_ant *ant;

	ant = (t_ant *)malloc(sizeof(*ant));
	ant->id = 0;
	ant->location = 0;
	ant->next = NULL;
	return (ant);
}
