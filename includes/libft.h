/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:30:14 by pabril            #+#    #+#             */
/*   Updated: 2016/04/20 11:57:04 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct	s_struct
{
	void			*content;
	size_t			content_size;
	struct s_struct	*next;
}				t_struct;

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);

int				ft_atoi(const char *str);
long			ft_atol(const char *str);
char			*ft_itoa(int n);

int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);
int				ft_isnumeric(const char *str);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

t_struct		*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_struct **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_struct **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_struct **alst, t_struct *news);
void			ft_lstpushback(t_struct **alst, t_struct *news);
void			ft_lstiter(t_struct *lst, void (*f)(t_struct *elem));
t_struct		*ft_lstmap(t_struct *lst, t_struct *(*f)(t_struct *elem));

int				ft_abs(int nb);
long			ft_labs(long nb);
double			ft_fabs(double nb);
double			ft_ceil(double x);
double			ft_floor(double x);
double			ft_cos(double nb);
double			ft_degtorad(double x);
double			ft_radtodeg(double x);
size_t			ft_fact(size_t nb);
double			ft_pow(double nb, long pow);
double			ft_modf(double x, double *ent);
double			ft_fmod(double x, double mod);
double			ft_sin(double x);
double			ft_tan(double x);

#endif
