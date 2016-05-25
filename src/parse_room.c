/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:14:11 by pabril            #+#    #+#             */
/*   Updated: 2016/05/25 11:21:38 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

int		parse_room(t_env *env, char *str, int type)
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
	room->visite = 0;
	room->id_ant = NULL;
	room->collision = NULL;
	room->links = NULL;
	room->father = NULL;
	room->poids = (type == ENTRY ? 0 : -1);
	insert_tab(room->name, room, env);
	if (type == ENTRY)
		env->starting_room = find_room(room->name, env);
	if (type == EXIT)
		env->ending_room = find_room(room->name, env);
	return (1);
}

int		check_room(char *str)
{
	size_t		i;
	char		**tab;

	tab = ft_strsplit(str, ' ');
	i = ft_tablen(tab);
	if (tab[0][0] == '#' && tab[0][1] == '#' && tab[0][2] != '#')
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
	parse_room(env, str, type);
	return (PARSE_ROOM);
}
