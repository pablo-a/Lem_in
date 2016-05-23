/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/23 10:24:57 by pabril           ###   ########.fr       */
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
