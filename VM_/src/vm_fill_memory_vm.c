/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fill_memory_vm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:16:18 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 17:19:10 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			vm_fill_cells(t_vm *vm, int pos, int player_no)
{
	int			i;

	i = -1;
	while (++i < 4)
	{
		vm->cells[MOD(pos + i)].player_no = player_no;
		vm->cells[MOD(pos + i)].recent = 1;
		vm->cells[MOD(pos + i)].count = 25;
	}
}

static void		fill_heart(t_vm *vm)
{
	vm->heart[0] = "     OOOOOOOO:       OOOOOOOO!";
	vm->heart[1] = " oOOOO!!!!;;;;O    OO.......:;!O";
	vm->heart[2] = "'OOO!!!;;;;;;;;O  O.......:   ;!O";
	vm->heart[3] = "OOO!!!!;;::::::.OO........:    ;!O";
	vm->heart[4] = "OO!!!!;;:::::..............:   ;!O";
	vm->heart[5] = "OOO!!!;::::::..............:   ;!O";
	vm->heart[6] = " OO!!;;::::::.............:   ;!O";
	vm->heart[7] = "  OO!;;::::::.............::::!O";
	vm->heart[8] = "    O!!;::::::............:::O";
	vm->heart[9] = "      !!!;:::::..........ooO";
	vm->heart[10] = "         !!;:::::.......O";
	vm->heart[11] = "            ;;::::.....O";
	vm->heart[12] = "              :::..O";
	vm->heart[13] = "                ::.";
	vm->heart[14] = "                 :";
}

void			vm_fill_memory(t_vm *vm, int no_player, size_t pos)
{
	size_t		i;

	i = 0;
	while (i < vm->players[no_player].size_player)
	{
		vm->cells[pos].player_no = no_player;
		vm->memory[pos++] = vm->players[no_player].memory[i++];
	}
}

void			vm_fill_memory_vm(t_vm *vm)
{
	int				number_players;
	unsigned long	size;
	unsigned long	tmp;
	int				no_player;
	t_process		*process;

	size = 0;
	no_player = 2;
	number_players = vm->nb_players;
	tmp = MEM_SIZE / number_players;
	vm_fill_memory(vm, 1, 0);
	process = vm_get_process(vm, 1);
	process->pc = size;
	while (no_player <= MAX_PLAYERS)
	{
		if (vm->players[no_player].number != 0)
		{
			size = size + tmp;
			process = vm_get_process(vm, no_player);
			process->pc = size;
			vm_fill_memory(vm, no_player, size);
		}
		no_player++;
	}
	fill_heart(vm);
}
