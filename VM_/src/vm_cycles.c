/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:28 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 10:59:29 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_advance_processes_one_cycle(t_vm *vm)
{
	unsigned int	pc;
	t_process		*process;

	process = vm->last_process;
	while (process)
	{
		if (process->alive)
		{
			pc = process->pc;
			if (!process->instruction.opcode)
				process->instruction = vm_read_opcode(vm, pc);
			process->instruction.cycles_to_execution -= 1;
			if (process->instruction.cycles_to_execution == 0)
			{
				vm_decode_parameter_byte(process, vm);
				process->instruction.op(process, vm);
				ft_bzero(&process->instruction, sizeof(t_instruction));
			}
		}
		process = process->prev;
	}
}

static void	vm_decrement_cycle_to_die(t_vm *vm)
{
	vm->cycle_to_die -= CYCLE_DELTA;
	if (vm_verbose_cycles(vm))
		ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
}

static void	vm_check_lives_and_kill(t_vm *vm)
{
	t_process	*current;

	vm->check_count += 1;
	current = vm->last_process;
	while (current)
	{
		if (vm->cycle_nbr - current->last_live_cycle >= vm->cycle_to_die)
		{
			if (vm_verbose_deaths(vm))
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
	current->no, vm->cycle_nbr - current->last_live_cycle, vm->cycle_to_die);
			current = vm_delete_process(current, vm);
		}
		else
		{
			current->nb_lives = 0;
			current = current->prev;
		}
	}
	if (vm->lives_since_last_check >= NBR_LIVE || vm->check_count >= MAX_CHECKS)
	{
		vm_decrement_cycle_to_die(vm);
		vm->check_count = 0;
	}
	vm->lives_since_last_check = 0;
}

static int	vm_check_alive_processes(t_vm *vm)
{
	t_process	*current;

	current = vm->processes;
	while (current)
	{
		if (current->alive)
			return (1);
		current = current->next;
	}
	return (0);
}

/*
**	Does one cycle in the game.
**	Returns 1 if the game is still running after the cycle.
**	Returns 0 if the game is over (i.e. all processes are dead);
*/

int			vm_do_one_cycle(t_vm *vm)
{
	vm_dump_if_necessary(vm);
	vm->cycle_nbr += 1;
	if (vm_verbose_cycles(vm))
		ft_printf("It is now cycle %d\n", vm->cycle_nbr);
	vm->cycles_since_last_check += 1;
	vm_advance_processes_one_cycle(vm);
	if (vm->cycles_since_last_check >= vm->cycle_to_die)
	{
		vm_check_lives_and_kill(vm);
		vm->cycles_since_last_check = 0;
	}
	return (vm_check_alive_processes(vm));
}
