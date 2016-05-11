/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:27:16 by pabril            #+#    #+#             */
/*   Updated: 2016/04/19 13:54:58 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

# define RED "\033[31m"
# define BLACK "\033[30m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define GRAY "\033[37m"
# define YELLOW "\033[33m"
# define END "\033[0m"

typedef struct		s_list
{
	int				diese;
	int				zero;
	int				minus;
	int				plus;
	int				blanck;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				size;
	int				modified_precision;
	int				precision;
	char			type;
	int				result;
}					t_list;

int					ft_initialize(t_list **lst);
int					ft_store_options(const char *format, int *i, t_list *lst,
							va_list *ap);
int					ft_subprintf(const char *format, int *i,
									t_list *lst, va_list *ap);
int					ft_printf(const char *format, ...);

int					ft_check_flags(const char *str, int i, t_list **lst);
int					ft_check_lenght(const char *str, int i, t_list **lst,
					va_list *ap);
int					ft_check_precision(const char *str, int i, t_list **lst,
					va_list *ap);
int					ft_check_modifiers(const char *str, int i, t_list **lst);
int					ft_check_type(const char *str, int i, char *c);

int					ft_print_char(char c);
void				ft_putcharn_fd(char c, size_t number, int file_descriptor);
int					ft_print_str(char *str);
int					ft_print_space(int i);
int					ft_print_sign(long long int i);
int					ft_print_number(unsigned long long int n);
int					ft_print_zeros(int secure, int len);

int					ft_char_case(t_list *lst, va_list *ap);
int					ft_string_case(t_list *lst, va_list *ap);
int					ft_string_case2(t_list *lst, char *str, size_t len);
int					ft_aff_str(char *str, t_list *lst, int len);

int					ft_ptr_case(t_list *lst, va_list *ap);

int					ft_handle_signed(long long a, t_list *lst);
int					ft_noflag(long long a, t_list *lst, int flag);
int					ft_noflag2(long long a, t_list *lst);
int					ft_zero(long long a, t_list *lst);
int					ft_blanck(long long a, t_list *lst);
void				ft_plus_case(long long a, t_list *lst, int flag);
int					ft_print_precision(long long a, t_list *lst);

int					ft_handle_unsigned(unsigned long long b, t_list *lst);
char				*ft_conv(unsigned long long n, t_list *lst, int base);
int					ft_try(char *str, t_list *lst, int flag);
int					ft_printxo_flag0(t_list *lst, int base,
					unsigned long long nb);
int					ft_printxo(t_list *lst, int base, unsigned long long nb
					, int spaces);
int					ft_printxo2(t_list *lst, int base, unsigned long long nb,
					int spaces);
int					ft_print_u(t_list *lst, unsigned long long b);
int					ft_baselen(unsigned long long nb, int size, int base);
int					ft_putbase(unsigned long long n, int size, int base,
					t_list *lst);
int					ft_put_base(unsigned long long nbr, int base, t_list *lst);

int					ft_len_number(long long int n);
int					ft_len_uns_number(unsigned long long n);
int					ft_putnbr_signed(long long int n);
long long			ft_get_signed_number(t_list *lst, long long a, va_list *ap);
unsigned long long	ft_get_unsigned_nb(t_list *lst, unsigned long long b,
										va_list *ap);
int					ft_number_case(t_list *lst, va_list *ap);

int					ft_percent_case(t_list *lst);

int					print_chars(void *memory, int size, t_list *lst);
void				print_wint(wint_t wint, t_list *lst);
int					print_wchar(wint_t wint, t_list *lst);
int					print_wide_chars(wchar_t *string, t_list *lst);
size_t				count_wide_chars(t_list *lst, wchar_t *string,
					size_t *lenght);
int					place_padding(char padder, size_t width, t_list *lst);

char				*fake_itoa(long long a);
unsigned long long	ft_power_unsigned(int a, int pow);
size_t				ft_strlen_wide(const wchar_t *original);

char				*change_lenght(char *str, int len, int size);
char				*flag_0(char *str);
char				*goto_left(char *str);
char				*blank_flag(char *str);
int					diese_flag(t_list *lst);

int					ft_n_case(t_list *lst, va_list *ap);
int					ft_color(const char *format);

#endif
