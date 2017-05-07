#include "vm.h"

void		vm_or(t_process *process, t_vm *vm)
{
	int		pc;
	int		first_param;
	int		second_param;
	int		third_param;


	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (vm_check_parameter_types(process->instruction) == 1)
	{
		first_param = vm_get_parameters_xorand(process, vm,
		process->instruction.first_type, &pc);
		second_param = vm_get_parameters_xorand(process, vm,
		process->instruction.second_type, &pc);
		third_param = vm->memory[MOD(pc)];
		if (third_param > 0 && third_param <= REG_NUMBER)
			vm_store_in_register(&process->registers[third_param],
								(first_param | second_param));
	}
	else
		process->carry = 0;
	vm_advance_pc(process);
}
