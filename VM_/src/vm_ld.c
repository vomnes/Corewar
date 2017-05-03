#include "vm.h"

void				vm_ld(t_process *process, t_vm *vm)
{
	unsigned int	pc;
	int				first_param;
	int				second_param;

	pc = vm_read_from_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (process->instruction.first_type == T_DIR)
		first_param = vm_read_memory_int(vm, pc + 1);
	else if (process->instruction.first_type == T_IND)
		first_param = vm_read_memory_short(vm, pc + 1);
	second_param = MOD(pc + 1);
	vm_store_in_register(&process->registers[second_param], first_param);
}
