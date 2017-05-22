/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_null_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:27:40 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:39:00 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_null_op(t_process *process, t_vm *vm)
{
	int	pc1;
	int	pc2;

	pc1 = process->pc;
	pc2 = mod(pc1 + 1);
	process->pc = pc2;
	vm->cells[pc1].present = 0;
	vm->cells[pc2].present = process->player_no;
}
