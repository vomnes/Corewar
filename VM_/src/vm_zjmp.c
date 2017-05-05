#include "vm.h"

void	vm_zjmp(t_process *process, t_vm *vm)
{
	short	indirection;
	int		pc;

	pc = vm_read_register(process->pc);
	indirection = vm_read_memory_short(vm, pc + 1);
	if (process->carry == 1)
		vm_store_in_register(&process->pc, MOD(pc + indirection % IDX_MOD));
	else
		vm_store_in_register(&process->pc, MOD(pc + 3));
}
