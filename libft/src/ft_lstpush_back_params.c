/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:11:48 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/10 11:12:19 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_back_params(int ac, char **av)
{
	t_list	*lst;
	int		i;
	t_list	*new;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		if ((new = ft_lstnew(av[i], (ft_strlen(av[i]) + 1) * sizeof(char))))
			ft_lstadd_end(&lst, new);
		i++;
	}
	return (lst);
}
