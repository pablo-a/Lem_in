/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:25 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 18:53:58 by pabril           ###   ########.fr       */
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

int		init_pathes(t_env *env)
{
	t_path_pile	*pile_path;

	pile_path = (t_path_pile *)malloc(sizeof(*pile_path));
	pile_path->nb_path = 0;
	pile_path->first = NULL;
	pile_path->last = NULL;
	env->pathes = pile_path;
	return (1);
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

int		init_ants(t_env *env)
{
	int		i;

	i = 1;
	while (i <= env->nb_ants)
	{
		new_ant(i, env);
		i++;
	}
	env->starting_room->id_ant = env->lst_ants;
	return (1);
}
