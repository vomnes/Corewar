#include "vm.h"

void	vm_lfork(t_process *process, t_vm *vm)
{
	int			pc;
	int			indirection;
	t_process	*duplicate;

	pc = vm_read_register(process->pc);
	duplicate = vm_create_process(vm);
	vm_copy_process(process, duplicate);
	indirection = vm_read_memory_int(vm, pc + 1, 2);
	vm_store_in_register(&process->pc, MOD(pc + 3));
	vm_store_in_register(&duplicate->pc, MOD(pc + indirection));
}
