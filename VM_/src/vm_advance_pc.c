/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_advance_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:56:29 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:34:11 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	calculate_advancement(t_process *process)
{
	int	advancement;
	int	i;

	advancement = 1;
	if (g_op_tab[process->instruction.opcode].param_byte)
		advancement += 1;
	i = g_op_tab[process->instruction.opcode].nb_args - 1;
	while (i >= 0)
	{
		if (process->instruction.args[i] == T_DIR)
		{
			if (g_op_tab[process->instruction.opcode].has_index)
				advancement += 2;
			else
				advancement += 4;
		}
		else if (process->instruction.args[i] == T_IND)
			advancement += 2;
		else if (process->instruction.args[i] == T_REG)
			advancement += 1;
		i--;
	}
	return (advancement);
}

static void	print_advancement(t_vm *vm, int pc1, int advancement)
{
	int i;

	i = 1;
	while (i <= advancement)
	{
		ft_printf("%.2x ", vm->memory[pc1]);
		pc1 = mod(pc1 + 1);
		i++;
	}
}

int			vm_advance_pc(t_process *process, t_vm *vm)
{
	int	pc1;
	int	pc2;
	int	advancement;

	pc1 = process->pc;
	advancement = calculate_advancement(process);
	pc2 = mod(pc1 + advancement);
	process->pc = pc2;
	if (vm_verbose_pc(vm))
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", advancement, pc1,
		pc1 + advancement);
		print_advancement(vm, pc1, advancement);
		ft_printf("\n");
	}
	vm->cells[pc1].present = 0;
	vm->cells[pc2].present = process->player_no;
	return (pc2);
}
