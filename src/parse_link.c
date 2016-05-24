/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:25:40 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 12:47:11 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

t_links	*init_links(void)
{
	t_links*link;

	link = (t_links *)		malloc(sizeof(*link));
	if (link == NULL)
		return (0);
	link->lenght = 0;
	link->first = NULL;
	link->last = NULL;
	return (link);
}

int		already_link(t_room *room, char *tofind)
{
	t_node	*tempo;

	tempo = room->links->first;
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
	t_room	*r1;
	t_room	*r2;

	r1 = find_room(s1, env);
	r2 = find_room(s2, env);
	if (ft_strcmp(s1, s2) == 0)
		return (0);
	if (r1 == NULL || r2 == NULL)
		wrong_input();
	if (r1->links == NULL)
		r1->links = init_links();
	if (r2->links == NULL)
		r2->links = init_links();
	if (already_link(r1, s2))
		return (0);
	pile_append(r1->links, r2);
	pile_append(r2->links, r1);
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
