#include "vm.h"

t_instruction	vm_read_opcode(t_vm *vm, unsigned int pc)
{
	static t_instruction	op_tab[17] =
	{
		{0, vm_null_op, 1},
		{1, vm_live, 10},
		{2, vm_ld, 5},
		{3, vm_st, 5},
		{4, vm_add, 10},
		{5, vm_sub, 10},
		{6, vm_and, 6},
		{7, vm_or, 6},
		{8, vm_xor, 6},
		{9, vm_zjump, 20},
		{10, vm_ldi, 25},
		{11, vm_sti, 25},
		{12, vm_fork, 800},
		{13, vm_lld, 10},
		{14, vm_lldi, 50},
		{15, vm_lfork, 1000},
		{16, vm_aff, 2}
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
		pc = vm_read_from_register(process->pc);
		if (!process->instruction)
			process->instruction = vm_read_opcode(vm, pc);
		process->instruction.cycles_to_execution -= 1;
		if (process->instruction.cycles_to_execution == 0)
		{
			pc = process->instruction.op(process, vm);
			vm_store_in_register(&process->pc, pc);
			ft_bzero(&process->instruction, sizeof(t_instruction));
		}
		process = process->prev;
	}
}
