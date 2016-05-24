/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 10:40:00 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		init_env(t_env *env)
{
	env->nb_ants = 0;
	env->tab_room = create_table(SIZE_TAB);
	env->lst_ants = NULL;
	env->pathes = NULL;
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

t_links	*init_links(void)
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

int		new_ant(int id, t_env *env)
{
	t_ant	*ant;
	t_ant	*tempo;

	ant = (t_ant *)malloc(sizeof(*ant));
	ant->id = id;
	ant->location = env->starting_room;
	ant->next = NULL;
	tempo = env->lst_ants;
	if (env->lst_ants == NULL)
	{
		env->lst_ants = ant;
		return (1);
	}
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = ant;
	return (1);
}

int			init_ants(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_ants)
	{
		new_ant(i, env);
		i++;
	}
	env->starting_room->id_ant = env->lst_ants;
	return (1);
}
