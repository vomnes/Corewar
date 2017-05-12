#include "vm.h"

void			vm_xor(t_process *process, t_vm *vm)
{
	int			pc;
	long long	first_param;
	long long	second_param;
	long long	third_param;

	process->carry = 1;
	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) == 1)
	{
		pc += 2;
		first_param = vm_get_parameters_xorand(process, vm,
		process->instruction.first_type, &pc);
		second_param = vm_get_parameters_xorand(process, vm,
		process->instruction.second_type, &pc);
		third_param = vm->memory[MOD(pc)];
		if (process->carry == 1 && third_param > 0 && third_param <= REG_NUMBER)
			vm_store_in_register(&process->registers[third_param],
								(first_param ^ second_param));
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	vm_advance_pc(process);
}
