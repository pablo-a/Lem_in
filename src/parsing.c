/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:28:03 by pabril            #+#    #+#             */
/*   Updated: 2016/05/19 12:14:34 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include "lemin.h"

int		get_ant(t_env *env, char *str)
{
	int nb_ant;

	if (str[0] == '#' && str[1] != '#')
		return (PARSE_ANT);
	if (env->lst_ants == NULL)
		env->lst_ants = new_ant();
	if (!(ft_isnumeric(str)))
		return (PARSE_ERROR);
	nb_ant = ft_atoi(str);
	if (nb_ant <= 0)
		return (PARSE_ERROR);
	env->nb_ants = nb_ant;
	ft_printf("number of ants = %d\n", nb_ant);
	return (PARSE_ROOM);
}

int		check_room(char *str)
{
	size_t	i;
	char	**tab;

	tab = ft_strsplit(str, ' ');
	i = ft_tablen(tab);
	if (tab[0][0] == '#' && tab[0][1] == '#')
		return (1);
	if (i == 3)
	{
		if (ft_strchr(str, '-') != NULL || !ft_isnumeric(tab[1]) ||
				!ft_isnumeric(tab[2]))
			return (0);
		return (1);
	}
	else if (i == 1 && ft_strchr(tab[0], '-') != NULL)//enlever les rooms sans coord
		return (1);
	else
		return (0);
}

int		get_room(t_env *env, char *str)
{
	int		type;

	type = NORMAL;
	if (str[0] == '#' && str[1] != '#')
		return (PARSE_ROOM);
	if (check_room(str) == 0)
		wrong_input();
	if (ft_strchr(str, '-') && str[0] != '#')
		return (PARSE_LINK);
	if (ft_strncmp(str, "##", 2) == 0)// traite les cas des types de salles
	{
		if (ft_strcmp(str, "##start") == 0)
			type = ENTRY;
		else if (ft_strcmp(str, "##end") == 0)
			type = EXIT;
		else
			return (PARSE_ROOM);
		get_next_line(0, &str);
		while (str[0] == '#' && str[1] != '#')
			get_next_line(0, &str);
	}
	ft_printf("type de salle : %d\n", type);
	parse_room(env, str, type);
	return (PARSE_ROOM);
}

int		already_link(int index1, char *tofind, t_env *env)
{
	t_node		*tempo;

	tempo = ROOM(index1)->links->first;
	while (tempo != NULL)
	{
		if (ft_strcmp(tempo->room->name, tofind) == 0)
			return (1);
		tempo = tempo->next;
	}
	return (0);
}

int		add_link(char *s1, char *s2, t_env *env)
{
	int		index1;
	int		index2;

	index1 = hash(s1);
	index2 = hash(s2);
	if (ft_strcmp(s1, s2) == 0)
		return (0);
	if (ROOM(index1) == NULL || ROOM(index2) == NULL)
		wrong_input();
	if (ROOM(index1)->links == NULL)
		ROOM(index1)->links = init_links();
	if (ROOM(index2)->links == NULL)
		ROOM(index2)->links = init_links();
	if (already_link(index1, s2, env))
		return (0);
	pile_append(ROOM(index1)->links, ROOM(index2));
	pile_append(ROOM(index2)->links, ROOM(index1));
	return (1);
}

int		get_link(t_env *env, char *str)
{
	char	*name1;
	char	*name2;
	int		i;

	i = 0;
	if (str[0] == '#')
		return (PARSE_LINK);
	while (str[i] != '-')
		i++;
	name1 = ft_strnew(i + 1);
	name2 = ft_strnew(ft_strlen(str) - i);
	ft_strncpy(name1, str, i);
	name2 = ft_strchr(str, '-') + 1;
	add_link(name1, name2, env);
	return (PARSE_LINK);
}

int		parse(t_env *env)
{
	char	*str;
	int		status;

	status = PARSE_ANT;
	while (get_next_line(0, &str) > 0)
	{
		if (status == PARSE_ANT)
			status = get_ant(env, str);
		else if (status == PARSE_ROOM)
			status = get_room(env, str);
		if (status == PARSE_LINK)
			status = get_link(env, str);
		if (status == PARSE_ERROR)
			incomplete_input();
	}
	if (status < PARSE_LINK)
		incomplete_input();
	return (0);
}
