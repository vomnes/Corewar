#include "vm.h"

int			vm_decode_index(t_vm *vm, t_process *process, int head)
{
	short	address;
	int		pc;

	address = vm_read_memory_short(vm, head);
	address = address % IDX_MOD;
	pc = vm_read_register(process->pc);
	return (vm_read_memory_int(vm, MOD(pc + address)));
}
