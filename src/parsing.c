/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:28:03 by pabril            #+#    #+#             */
/*   Updated: 2016/05/13 14:03:48 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "get_next_line.h"

int		get_ant(t_env *env, char *str)
{
	int nb_ant;
	t_ant	ant;

	if (env->lst_ants == NULL)
		env->lst_ants = &(new_ant(&ant));
	if (!(ft_isnumeric(str)))
		return (PARSE_ERROR);
	nb_ant = ft_atoi(str);
	if (nb_ant <= 0)
		return (PARSE_ERROR);
	env->nb_ant = nb_ant;
	return (PARSE_ROOM);
}

int		get_room(t_env *env, char *str)
{
	int		type;
	t_room	tempo;

	if (ft_strchr(str, "-"))
		return (PARSE_LINK);
	if (ft_strncmp(str, "##", 2))// traite les cas des types de salles
	{
		if (ft_strncmp(str, "##start", 7))
			type = DEBUT;
		else if (ft_strncmp(str, "##end", 5))
			type = FIN;
		else
			return (PARSE_ERROR);
	}
	else if (ft_strncmp(str, "#", 1))
		return (PARSE_ROOM);
	parse_room(env, &tempo, str, type);
	return (PARSE_ROOM);
}

int		add_link(char *s1, char *s2, t_env *env)
{
	int		index1;
	int		index2;

	index1 = hash(s1);
	index2 = hash(s2);
	if (ROOM(index1)->links == NULL)
		ROOM(index1)->links = init_links();
	if (ROOM(index2)->links == NULL)
		ROOM(index2)->links = init_links();
	pile_append(ROOM(index1)->links, ROOM(index2));
	pile_append(ROOM(index1)->links, ROOM(index1));
}

int		get_link(t_env *env, char *str);
{
	char	*name1;
	char	*name2;
	int		i;

	i = 0;
	while (str[i] != '-')
		i++;
	ft_strncpy(name1, str, i);
	name2 = ft_strchr(str, '-') + 1;
	add_link(name1, name2, env);
	return (PARSE_LINK);
}

int		parse(t_env *env)
{
	char	*str;
	int		status = PARSE_ANT;

	while (get_next_line(0, &str) > 0)
	{
		if (status == PARSE_ANT)
			status = get_ant(env, str);
		else if (status == PARSE_ROOM)
			status = get_room(env, str);
		if (status == PARSE_LINK)
			status = get_link(env, str);
		if (status == PARSE_ERROR)
			exit();
	}
	return (0);
}
