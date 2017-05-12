#include "vm.h"

long long			vm_decode_index(t_vm *vm, t_process *process, int head)
{
	int		address;
	int		pc;

	address = vm_read_memory_int(vm, head, 2);
	address = address % IDX_MOD;
	pc = vm_read_register(process->pc);
	return (vm_read_memory_int(vm, MOD(pc + address), 4));
}
