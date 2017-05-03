#include "vm.h"

void	vm_null_op(t_process *process, t_vm *vm)
{
	int	pc;

	(void)vm;
	pc = vm_read_register(process->pc);
	vm_store_in_register(&process->pc, MOD(pc + 1));
}
