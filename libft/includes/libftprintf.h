/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:35 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/17 14:47:11 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

typedef enum		e_length_flag
{
	NONE, HH, H, L, LL, J, Z
}					t_length_flag;

typedef struct		s_stringl
{
	char			*text;
	ssize_t			length;
}					t_stringl;

typedef struct		s_conversion
{
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				flag_sharp;
	int				flag_zero;
	int				width;
	int				period;
	int				precision;
	t_length_flag	length;
	char			specifier;
}					t_conversion;

typedef struct		s_specifier
{
	char			spec;
	t_stringl		*(*function)(t_conversion *, va_list);
}					t_specifier;

int					ft_printf(const char *format, ...);
int					ft_asprintf(char **ret, const char *format, ...);

const char			*parse_character(const char *format, t_stringl *output,
					va_list args);
const char			*parse_flags(const char *ptr, t_conversion *conversion);
const char			*parse_width_precision(const char *ptr,
					t_conversion *conversion, va_list args);
const char			*parse_length(const char *ptr, t_conversion *conversion);
const char			*parse_specifier(const char *ptr, t_conversion *conversion);

t_stringl			*convert_percent(t_conversion *conversion, va_list args);
t_stringl			*convert_di(t_conversion *conversion, va_list args);
t_stringl			*convert_u(t_conversion *conversion, va_list args);
t_stringl			*convert_o(t_conversion *conversion, va_list args);
t_stringl			*convert_x(t_conversion *conversion, va_list args);
t_stringl			*convert_p(t_conversion *conversion, va_list args);
t_stringl			*convert_c(t_conversion *conversion, va_list args);
t_stringl			*convert_s(t_conversion *conversion, va_list args);
t_stringl			*convert_b(t_conversion *conversion, va_list args);
t_stringl			*convert_undefined(t_conversion *conversion);

char				*uintmaxtoa_hexa(uintmax_t number, char specifier);

char				*handle_sharp_o(t_conversion *conversion, char *output);
char				*handle_sharp_x(t_conversion *conversion, char *output);
char				*handle_sharp_b(t_conversion *conversion, char *output);
char				*handle_precision_numeric(t_conversion *conversion,
											char *output);
char				*handle_zero(t_conversion *conversion, char *output);
t_stringl			*handle_zero_stringl(t_conversion *conversion,
					t_stringl *output);
char				*handle_zero_plus_space(t_conversion *conversion,
											char *output);

intmax_t			handle_length_decimal(t_conversion *conversion,
											va_list args);
uintmax_t			handle_length_unsigned(t_conversion *conversion,
											va_list args);
char				*handle_width(t_conversion *conversion, char *output);
t_stringl			*handle_width_stringl(t_conversion *conversion,
											t_stringl *output);

char				*convert_wchar(wchar_t character);
char				*convert_wstring(wchar_t *wstring);

t_stringl			*str_to_stringl(char *str);
void				delete_stringl(t_stringl *stringl);
t_stringl			*append_stringl(t_stringl *strl1, t_stringl *strl2);
t_stringl			*stringlappend_char(t_stringl *strl, char character);
t_stringl			*stringlappend_char_before(t_stringl *strl, char character);

#endif
