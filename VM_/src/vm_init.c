/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:18:45 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 18:12:14 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	This function assumes that all player numbers are used between 1 and
**	nb_players
*/

void	vm_init(t_vm *vm)
{
	int			i;
	t_process	*process;

	i = 1;
	if (vm->nb_players < 1 || vm->nb_players > 4)
		vm_error_exit(vm, "You must load between 1 and 4 players");
	while (i <= vm->nb_players)
	{
		vm_create_process(vm);
		process = vm_get_process(vm, i);
		process->player_no = i;
		vm->players[i].nb_alive_processes += 1;
		vm_store_in_register(&process->registers[1], -i);
		i++;
	}
	vm->cycle_to_die = CYCLE_TO_DIE;
}
