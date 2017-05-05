#include "vm.h"

int			check_parameters_xorand(t_process *process)
{
	if ((process->instruction.first_type == T_REG ||
		process->instruction.first_type == T_IND ||
		process->instruction.first_type == T_DIR) &&
		(process->instruction.second_type == T_REG ||
		process->instruction.second_type == T_DIR ||
		process->instruction.second_type == T_IND) &&
		(process->instruction.third_type == T_REG))
		return (1);
	return (0);
}

int			get_parameters_xorand(t_process *process, t_vm *vm, char type, int *pc)
{
	int		parameter;
	int		no_register;

	parameter = 0;
	no_register = 0;
	if (type == T_REG)
	{
		no_register = vm->memory[MOD(*pc + 2)];
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
	int		real_pc;
	int		first_param;
	int		second_param;
	int		third_param;


	pc = vm_read_register(process->pc);
	real_pc = pc;
	vm_decode_parameter_byte(process, vm);
	if (check_parameters_xorand(process))
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
	vm_store_in_register(&process->pc, move_pc(process, real_pc));
}
