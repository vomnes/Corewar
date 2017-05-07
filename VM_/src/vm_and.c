#include "vm.h"

int			get_parameters_xorand(t_process *process, t_vm *vm, char type, int *pc)
{
	int		parameter;
	int		no_register;

	parameter = 0;
	no_register = 0;
	if (type == T_REG)
	{
		no_register = vm->memory[MOD(*pc + 2)];
		if (no_register > 0 && no_register <= REG_NUMBER)
			parameter = vm_read_register(process->registers[no_register]);
		*pc += 3;
	}
	else if (type == T_IND)
	{
		parameter = vm_read_memory_short(vm, *pc + 2);
		*pc += 4;
	}
	else if (type == T_DIR)
	{
		parameter = vm_read_memory_int(vm, *pc + 2);
		*pc += 6;
	}
	return (parameter);
}

void		vm_and(t_process *process, t_vm *vm)
{
	int		pc;
	int		first_param;
	int		second_param;
	int		third_param;


	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (vm_check_parameter_types(process->instruction) == 1)
	{
		first_param = get_parameters_xorand(process, vm,
		process->instruction.first_type, &pc);
		second_param = get_parameters_xorand(process, vm,
		process->instruction.second_type, &pc);
		third_param = vm->memory[MOD(pc)];
		if (third_param > 0 && third_param <= REG_NUMBER)
			vm_store_in_register(&process->registers[third_param],
								(first_param & second_param));
	}
	else
		process->carry = 0;
	vm_advance_pc(process);
}
