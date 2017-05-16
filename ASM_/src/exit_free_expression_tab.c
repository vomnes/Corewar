/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_expression_tab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:42:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/16 16:03:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	exit_free_expression_tab(char **expression_tab)
{
	ft_strtab_free(expression_tab);
	return (-1);
}
