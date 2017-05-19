/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:21:41 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/19 11:21:17 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_live(t_process *process, t_vm *vm)
{
	int			pc;
	int			player_nb;
	t_player	*player;

	process->instruction.first_type = T_DIR;
	process->instruction.args[0] = T_DIR;
	pc = process->pc;
	player_nb = vm_read_memory_int(vm, pc + 1);
	player = vm_get_player(vm, -player_nb);
	if (vm_verbose_operations(vm))
		ft_printf("P% 5d | live %d\n", process->no, player_nb);
	if (player)
	{
		if (vm_verbose_lives(vm))
			ft_printf("Player %d (%s) is said to be alive\n",
		-player_nb, player->name);
		vm->last_live_player_no = -player_nb;
		player->cycle_of_last_live = vm->cycle_nbr;
	}
	vm->lives_since_last_check += 1;
	process->nb_lives += 1;
	process->last_live_cycle = vm->cycle_nbr;
	vm_advance_pc(process, vm);
}
