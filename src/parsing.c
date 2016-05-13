/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:28:03 by pabril            #+#    #+#             */
/*   Updated: 2016/05/13 12:20:12 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "get_next_line.h"

int		get_ant(t_env *env, char *str)
{
	int nb_ant;

	if (env->lst_ants == NULL)
		env->lst_ants = &(new_ant());
	if (!(ft_isnumeric(str)))
		return (PARSE_ERROR);
	nb_ant = ft_atoi(str);
	if (nb_ant <= 0)
		return (PARSE_ERROR);
	return (PARSE_ROOM);
}

int		get_room(t_env *env, char *str)
{
	int		type;
	t_room	tempo;

	if (ft_strncmp(str, "##", 2))// traite les cas des types de salles
	{
		if (ft_strncmp(str, "##start", 7))
			type = DEBUT;
		else if (ft_strncmp(str, "##end", 5))
			type = FIN;
		else
			return (PARSE_ERROR);
	}
	if ()
	parse_room(env, &tempo, str);

	return ();
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
		else if (status == PARSE_LINK)
			status = get_link(env, str);
		if (status == PARSE_ERROR)
			exit();
	}
	return (0);
}
