/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:09:08 by pabril            #+#    #+#             */
/*   Updated: 2016/05/11 15:01:38 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <stdlib.h>

# define NORMAL 0
# define DEBUT 1
# define FIN 2

typedef struct	s_ant
{
	int	id;
	int	location;
}				t_ant;

/*
** pile links qui va contenir tout ce qu'il faut pour connaitre les connections
** des autres salles. chaque element est une struct node.
*/

typedef struct	s_links
{
	int				lenght;
	struct s_node	*first;
	struct s_node	*last;
}				t_links;

/*
** maillon de la pile links avec un pointeur sur une salle connecte a la notre
** et deux pointeurs sur le maillon precedent et le suivant.
*/

typedef struct	s_node
{
	struct s_room	*room;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/*
** structure contenant toutes les infos relatives a une salle dont une pile
** contenant toutes ses connections avec les autres salles.
*/

typedef struct	s_room
{
	char			*name;
	int				id;
	int				type;
	int				coordx;
	int				coordy;
	int				id_ant;
	struct s_links	*links;
}				t_room;

typedef struct	s_env
{
	int		nb_ants;

}				t_env;


t_links			*new_pile(void);
int				pile_append(t_links *pile, t_room *room);
int				pile_prepend(t_links *pile, t_room *room);
int				free_pile(t_links **pile);
int				show_pile(t_links *pile);

#endif
