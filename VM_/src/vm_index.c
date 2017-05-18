/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:17:37 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:17:37 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

long long			vm_decode_index(t_vm *vm, t_process *process, int head)
{
	short	address;
	int		pc;

	address = vm_read_memory_short(vm, head);
	address = address % IDX_MOD;
	pc = process->pc;
	return (vm_read_memory_int(vm, MOD(pc + address)));
}
