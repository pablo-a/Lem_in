/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:09:08 by pabril            #+#    #+#             */
/*   Updated: 2016/05/13 14:27:18 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>

# define SIZE_TAB 1024

# define NORMAL 0
# define DEBUT 1
# define FIN 2

# define PARSE_ERROR 0
# define PARSE_ANT 1
# define PARSE_ROOM 2
# define PARSE_LINK 3

# define ROOM(key) env->tab_room[key]

typedef struct	s_ant
{
	int				id;
	int				location;
	struct s_ant	*next;
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
	int				type;
	int				coordx;
	int				coordy;
	int				id_ant;
	struct s_room	*collision;
	struct s_links	*links;
}				t_room;

/*
** structure principale, contient une table de hash avec une salle dans
** chaque case. contient les fourmis.
*/

typedef struct	s_env
{
	int				nb_ants;
	struct s_room	*tab_room[SIZE_TAB];
	struct s_ant	**lst_ants;

}				t_env;

/*
****************************** fonctions lemin *********************************
*/

int				parse(t_env *env);
int				get_ant(t_env *env, char *str);
int				get_room(t_env *env, char *str);
int				get_link(t_env *env, char *str);

int				init_env(t_env *env);
t_ant			*new_ant(void);

t_links			*new_pile(void);
int				pile_append(t_links *pile, t_room *room);
int				pile_prepend(t_links *pile, t_room *room);
int				free_pile(t_links **pile);

/*
**fonctions propre a la table de hash
*/

int				hash(char *str);
int				get_index(char *str, t_room *tab[SIZE_TAB]);
int				insert_hash(char *str, t_room *room, t_room *tab[SIZE_TAB]);
t_room			*get_value(char *str, t_room *tab[SIZE_TAB]);
int				remove_hash(char *str, t_room *tab[SIZE_TAB]);

#endif
