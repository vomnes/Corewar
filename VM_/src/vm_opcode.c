/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_opcode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:27:57 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:27:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_instruction	vm_read_opcode(t_vm *vm, unsigned int pc)
{
	static const t_instruction	op_tab[17] = {
		{0, vm_null_op, 1, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{1, vm_live, 10, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{2, vm_ld, 5, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{3, vm_st, 5, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{4, vm_add, 10, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{5, vm_sub, 10, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{6, vm_and, 6, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{7, vm_or, 6, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{8, vm_xor, 6, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{9, vm_zjmp, 20, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{10, vm_ldi, 25, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{11, vm_sti, 25, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{12, vm_fork, 800, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{13, vm_lld, 10, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{14, vm_lldi, 50, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{15, vm_lfork, 1000, 0, 0, 0, {0, 0, 0, 0}, {{0}}},
		{16, vm_aff, 2, 0, 0, 0, {0, 0, 0, 0}, {{0}}}
	};

	if (vm->memory[pc] > 16)
		return (op_tab[0]);
	else
		return (op_tab[vm->memory[pc]]);
}
