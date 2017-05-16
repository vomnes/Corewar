#include "vm.h"

void		vm_and(t_process *process, t_vm *vm)
{
	int	pc;
	int	param1;
	int	param2;
	int	result;

	pc = vm_read_register(process->pc);
	process->carry = 0;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param1 = vm_param_to_int_idx(process, vm, 0);
		param2 = vm_param_to_int_idx(process, vm, 1);
		if ((result = param1 & param2) == 0)
			process->carry = 1;
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], result);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | and %d %d r%hhd\n", process->no, param1,
			param2, process->instruction.params[2].uch);
	}
	vm_advance_pc(process, vm);
}


int			vm_get_parameters_xorand(t_process *process, t_vm *vm, char type,\
									int *pc)
{
	int		parameter;
	int		no_register;

	parameter = 0;
	no_register = 0;
	if (type == T_REG)
	{
		no_register = vm->memory[MOD(*pc)];
		if (no_register > 0 && no_register <= REG_NUMBER)
			parameter = vm_read_register(process->registers[no_register]);
		else
			process->carry = 0;
		*pc += 1;
	}
	else if (type == T_IND)
	{
		parameter = vm_decode_index(vm, process, *pc);
		*pc += 2;
	}
	else if (type == T_DIR)
	{
		parameter = vm_read_memory_int(vm, *pc);
		*pc += 4;
	}
	return (parameter);
}
/*
void			vm_and(t_process *process, t_vm *vm)
{
	int			pc;
	int			first_param;
	int			second_param;
	int			third_param;

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
								(first_param & second_param));
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	vm_advance_pc(process, vm);
}
*/
