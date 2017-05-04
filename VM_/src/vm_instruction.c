#include "vm.h"


t_instruction	vm_read_opcode(t_vm *vm, unsigned int pc)
{
	static const t_instruction	op_tab[17] =
	{
		{0, vm_null_op, 1, 0, 0, 0, {0, 0, 0, 0}},
		{1, vm_live, 10, 0, 0, 0, {0, 0, 0, 0}},
		{2, vm_ld, 5, 0, 0, 0, {0, 0, 0, 0}},
		{3, vm_st, 5, 0, 0, 0, {0, 0, 0, 0}},
		{4, vm_add, 10, 0, 0, 0, {0, 0, 0, 0}},
		{5, vm_sub, 10, 0, 0, 0, {0, 0, 0, 0}},
		{6, vm_and, 6, 0, 0, 0, {0, 0, 0, 0}},
		{7, vm_or, 6, 0, 0, 0, {0, 0, 0, 0}},
		{8, vm_xor, 6, 0, 0, 0, {0, 0, 0, 0}},
		{9, vm_zjmp, 20, 0, 0, 0, {0, 0, 0, 0}},
		{10, vm_ldi, 25, 0, 0, 0, {0, 0, 0, 0}},
		{11, vm_sti, 25, 0, 0, 0, {0, 0, 0, 0}},
		{12, vm_fork, 800, 0, 0, 0, {0, 0, 0, 0}},
		{13, vm_lld, 10, 0, 0, 0, {0, 0, 0, 0}},
		{14, vm_lldi, 50, 0, 0, 0, {0, 0, 0, 0}},
		{15, vm_lfork, 1000, 0, 0, 0, {0, 0, 0, 0}},
		{16, vm_aff, 2, 0, 0, 0, {0, 0, 0, 0}}
	};

	if (vm->memory[pc] > 16)
		return (op_tab[0]);
	else
		return (op_tab[vm->memory[pc]]);
}

void			vm_advance_processes_one_cycle(t_vm *vm)
{
	unsigned int	pc;
	t_process		*process;

	process = vm->processes;
	while (process && process->next)
		process = process->next;
	while (process)
	{
		if (process->alive)
		{
			pc = vm_read_from_register(process->pc);
			if (!process->instruction)
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
