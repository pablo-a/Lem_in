/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:28:03 by pabril            #+#    #+#             */
/*   Updated: 2016/05/23 10:31:41 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
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
