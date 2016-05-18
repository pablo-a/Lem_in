/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:28:03 by pabril            #+#    #+#             */
/*   Updated: 2016/05/18 11:58:26 by pabril           ###   ########.fr       */
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

int		get_room(t_env *env, char *str)
{
	int		type;

	type = NORMAL;
	if (ft_strchr(str, '-'))
		return (PARSE_LINK);
	if (ft_strncmp(str, "##", 2) == 0)// traite les cas des types de salles
	{
		if (ft_strncmp(str, "##start", 7) == 0)
			type = ENTRY;
		else if (ft_strncmp(str, "##end", 5) == 0)
			type = EXIT;
		else
			return (PARSE_ERROR);
		ft_printf("type de salle : %d\n", type);
		return (PARSE_ROOM);
	}
	else if (ft_strncmp(str, "#", 1) == 0)
		return (PARSE_ROOM);
	parse_room(env, str, type);
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
	return (1);
}

int		get_link(t_env *env, char *str)
{
	char	*name1;
	char	*name2;
	int		i;

	i = 0;
	while (str[i] != '-')
		i++;
	name1 = ft_strnew(20);
	name2 = ft_strnew(20);
	ft_strncpy(name1, str, i);
	name2 = ft_strchr(str, '-') + 1;
	add_link(name1, name2, env);
	return (PARSE_LINK);
}

int		parse(t_env *env)
{
	char	*str;
	int		status = PARSE_ANT;

	ft_printf("entree dans la boucle\n");
	while (get_next_line(0, &str) > 0)
	{
		ft_printf("status debut de boucle = %d\n", status);
		if (status == PARSE_ANT)
			status = get_ant(env, str);
		else if (status == PARSE_ROOM)
			status = get_room(env, str);
		if (status == PARSE_LINK)
			status = get_link(env, str);
		ft_printf("status fin de boucle = %d\n", status);
		if (status == PARSE_ERROR)
			exit(1);
	}
	return (0);
}
