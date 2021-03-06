/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_label_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:25:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 18:26:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_is_label_chars(int c)
{
	if (ft_strchr(LABEL_CHARS, (char)c) != NULL)
		return (0);
	else
		return (1);
}
