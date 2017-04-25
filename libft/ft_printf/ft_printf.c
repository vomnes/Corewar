/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:34:05 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 15:00:37 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_manage_parsing(const char *s, t_args *elem)
{
	if (ft_parsing_start(s, elem) == -1)
		return (-1);
	if (ft_parsing_flag(s, elem) == -1)
		return (-1);
	if (ft_parsing_width(s, elem) == -1)
		return (-1);
	if (ft_parsing_precision(s, elem) == -1)
		return (-1);
	if (ft_parsing_length(s, elem) == -1)
		return (-1);
	ft_parsing_type(s, elem);
	return (0);
}

static int	ft_run(char const *format, t_args *elem, va_list *args, int *len)
{
	int i;
	int k;
	int ret;

	i = 0;
	k = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (i == elem[k].start && elem[k].ok_start == 1)
		{
			if ((ret = ft_check_type(elem, &k, args)) == -1)
				return (-1);
			*len += ret;
			i = elem[k].end;
			ft_init_struct(elem, &k);
			k++;
		}
		else
			ft_putchar_len(format[i], len);
		i++;
	}
	return (*len);
}

static int	ft_run_all(const char *format, t_args *elem, \
va_list *args, int *len)
{
	if (ft_manage_parsing(format, elem) == -1)
	{
		free(elem);
		return (0);
	}
	if (ft_run(format, elem, args, len) == -1)
	{
		free(elem);
		return (-1);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_args	*elem;
	int		nb_pct;
	int		len;
	int		ret;

	if (format == NULL || *format == '\0')
		return (0);
	if ((nb_pct = ft_nb_pct(format)) == 0)
	{
		ft_putstr(format);
		return ((int)ft_strlen(format));
	}
	if (!(elem = ft_memalloc(sizeof(t_args) * nb_pct)))
		return (-1);
	ret = 0;
	len = 0;
	va_start(args, format);
	if ((ret = ft_run_all(format, elem, &args, &len)) <= 0)
		return (ret);
	va_end(args);
	free(elem);
	return (len);
}
