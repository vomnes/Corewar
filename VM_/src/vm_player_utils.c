/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:39:06 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:39:24 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*vm_get_player(t_vm *vm, int player_nb)
{
	int i;

	i = 1;
	while (i <= vm->nb_players)
	{
		if ((vm->players[i]).number == player_nb)
			return (&vm->players[i]);
		i++;
	}
	return (NULL);
}
