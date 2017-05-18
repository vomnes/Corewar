/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_introduction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:18:57 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:18:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_introduce_contestants(t_vm *vm)
{
	int			player_no;
	t_player	*player;

	ft_printf("Introducing contestants...\n");
	player_no = 1;
	while (player_no <= vm->nb_players)
	{
		if ((player = vm_get_player(vm, player_no)))
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			player->number, player->size_player, player->name, player->comment);
		player_no++;
	}
}
