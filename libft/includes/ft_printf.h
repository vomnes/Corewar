/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:13:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/25 18:50:51 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"

typedef enum		e_length
{
	no,
	hh,
	h,
	ll,
	l,
	j,
	z
}					t_length;

typedef	struct		s_args
{
	int				start;
	int				ok_start;
	int				end;
	int				new_start;
	int				nb_arg;
	int				pre_hash;
	int				pre_zero;
	int				end_space;
	int				pre_sign;
	int				pre_blank;
	int				ok_width;
	int				width;
	int				wildcard_width;
	int				ok_precision;
	int				precision;
	int				wildcard_precision;
	t_length		length;
	char			type;
	int				size;
	int64_t			i_nb;
	int				neg;
	int				arg_len;
}					t_args;

int					ft_printf(const char *format, ...);

int					ft_parsing_start(const char *s, t_args *elem);
int					ft_parsing_flag(const char *s, t_args *elem);
int					ft_parsing_width(const char *s, t_args *elem);
int					ft_parsing_precision(const char *s, t_args *elem);
int					ft_parsing_length(const char *s, t_args *elem);
void				ft_parsing_type(const char *s, t_args *elem);
int					ft_manage_parsing(const char *s, t_args *elem);
int					ft_check_errors(const char *s, int *i, int num_check);

void				ft_hex_basic_one(const char *value, t_args *elem, int *k);
void				ft_hex_basic_two(const char *value, t_args *elem, int *k);
void				ft_hex_hash(const char *value, t_args *elem, int *k);
void				ft_hex_zero_one(const char *value, t_args *elem, int *k);
size_t				ft_count_ho(unsigned long long int nb, int base);
int					ft_itoa_hex(unsigned long long int nb, char a, int *k,
								t_args *elem);
int					ft_manage_hex(const char *value, t_args *elem,
								const char *prefix, int *k);

int					ft_adapt_octal(const char *value, t_args *elem, int *k);
void				ft_octal_basic_one(const char *value, t_args *elem, int *k);
void				ft_octal_basic_two(const char *value, t_args *elem, int *k);
void				ft_octal_hash(const char *value, t_args *elem, int *k);
void				ft_octal_zero_one(const char *value, t_args *elem, int *k);
void				ft_octal_zero_two(const char *value, t_args *elem, int *k);
void				ft_octal_end_space(const char *value, t_args *elem, int *k);
int					ft_itoa_octal(unsigned long long int nb, t_args *elem,
					int *k);
int					ft_manage_octal(const char *value, t_args *elem,
									const char *prefix, int *k);

void				ft_ptr_basic_one(const char *value, t_args *elem, int *k);
void				ft_ptr_basic_two(const char *value, t_args *elem, int *k);
void				ft_ptr_zero_one(const char *value, t_args *elem, int *k);
int					ft_itoa_ptr(unsigned long long int nb, int *k,
					t_args *elem);

int					ft_itoa_unsigned(unsigned long long int nb, int *k,
					t_args *elem);

void				ft_signed_end_space(char const *value, t_args *elem,
					int *k);
void				ft_put_signed_zeroes(char const *value, t_args *elem,
					int *k);
void				ft_put_signed_space(char const *value, int *k,
					t_args *elem);
void				ft_put_signed_end_space(char const *value, int *k,
					t_args *elem);
int					ft_itoa_signed(long long int nb, int *k, t_args *elem);

int					ft_print_string(char *value, int *k, t_args *elem);
int					ft_print_char(int value, int *k, t_args *elem);
size_t				ft_sizewchar(wchar_t wc);
int					ft_putwchar_all(wchar_t wc);
void				ft_putnwstr(const wchar_t *wc, size_t n);
int					ft_print_wchar(wchar_t value, int *k, t_args *elem);
void				ft_putwstr_size(const wchar_t *wc, size_t n);
int					ft_wstrnlen(const wchar_t *wc, size_t n);
int					ft_print_wstr(const wchar_t *value, int *k, t_args *elem);

int					ft_manage_hex(const char *value, t_args *elem,
					const char *prefix, int *k);
int					ft_itoa_b(unsigned long long int nb, int *k, t_args *elem);
void				ft_put_h(int *date, char x, t_args *elem, int *v);
void				ft_put_d(int *date, char x, t_args *elem, int *v);
int					ft_put_date(const char *format, int *v, t_args *elem);

int					ft_check_type(t_args *elem, int *k, va_list *args);

int					ft_adapt_length(t_args *elem, int *k, int *nb);

void				ft_putchar_len(char c, int *up);
void				ft_putstr_len(const char *value, int *up);

void				ft_init_struct(t_args *elem, int *k);
void				ft_printf_struct(t_args *elem, int *k);

int					ft_is_type(int c);
int					ft_is_type_less_pct(int c);
int					ft_is_flag(int c);
int					ft_is_signed(int c);
int					ft_is_length(int c);
int					ft_nb_pct(const char *s);

#endif
