/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:09:08 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 13:36:48 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>

# define SIZE_TAB 10000

# define NORMAL 0
# define ENTRY 1
# define EXIT 2

# define PARSE_ERROR 0
# define PARSE_ANT 1
# define PARSE_ROOM 2
# define PARSE_LINK 3

# define ROOM(key) env->tab_room->tab[key]
# define VISITE(room) room->visite
# define POIDS(room) room->poids
# define PERE(room) room->father

# define ERROR(str) ft_putendl(str); exit(0)

typedef struct	s_ant
{
	int				id;
	struct s_room	*location;
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
	int				poids;
	int				type;
	int				coordx;
	int				coordy;
	int				visite;
	struct s_ant	*id_ant;
	struct s_room	*collision;
	struct s_room	*father;
	struct s_links	*links;
}				t_room;

typedef struct	s_hashtable
{
	int				size;
	struct s_room	**tab;
}				t_hashtable;

typedef struct	s_path_pile
{
	int				nb_path;
	struct s_path	*first;
	struct s_path	*last;
}				t_path_pile;

typedef struct	s_path
{
	int					len;
	struct s_path		*next_path;
	struct s_path		*prev_path;
	struct s_node_path	*first;
	struct s_node_path	*last;
}				t_path;

typedef struct	s_node_path
{
	struct s_room		*room;
	struct s_node_path	*next;
	struct s_node_path	*prev;
}				t_node_path;

/*
** structure principale, contient une table de hash avec une salle dans
** chaque case. contient les fourmis.
*/

typedef struct	s_env
{
	int					nb_ants;
	struct s_room		*starting_room;
	struct s_room		*ending_room;
	struct s_hashtable	*tab_room;
	struct s_ant		*lst_ants;
	struct s_path_pile	*pathes;

}				t_env;

/*
****************************** FUNCTIONS LEMIN *********************************
*/

/*
**************************** PARSING *******************************************
*/

int				parse(t_env *env);
int				get_ant(t_env *env, char *str);

int				parse_room(t_env *env, char *str, int type);
int				get_room(t_env *env, char *str);
int				check_room(char *str);

t_links			*init_links(void);
int				get_link(t_env *env, char *str);
int				add_link(char *s1, char *s2, t_env *env);
int				already_link(t_room *room, char *tofind);

/*
** ********************* INIT ENV AND ERRORS ***********************************
*/

int				new_ant(int id, t_env *env);
int				init_ants(t_env *env);
int				init_env(t_env *env);
int				init_pathes(t_env *env);
int				get_next_space(char *str);

int				incomplete_input(void);
int				wrong_input(void);
int				wrong_map(void);

t_links			*new_pile(void);
int				pile_append(t_links *pile, t_room *room);
int				pile_prepend(t_links *pile, t_room *room);
int				free_pile(t_links **pile);

t_path			*new_path(void);
int				append_path(t_path_pile *pile_path, t_path *path);
int				append_node_path(t_path *path, t_room *room);

/*
** *********************** HASH TABLE ******************************************
*/

int				hash(char *str);
t_hashtable		*create_table(int size);
int				insert_tab(char *key, t_room *room, t_env *env);
t_room			*find_room(char *key, t_env *env);

/*
** ************************** RESOLVE FUNCTIONS ********************************
*/

int				mark_path(t_env *env, int num, t_room *current_pos);
int				get_marked_path(t_env *env, t_room *current_pos);
int				possible_to_resolve(t_env *env, t_room *current_pos);
int				resolve(t_env *env);

#endif
