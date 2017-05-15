#include "vm.h"

void		vm_ldi(t_process *process, t_vm *vm)
{
	int		pc;
	int		param1;
	int		param2;
	int		sum;
	int		load;

	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param1 = vm_param_to_int_idx(process, vm, 0);
		param2 = vm_param_to_int_idx(process, vm, 1);
		sum = param1 + param2;
		load = vm_read_memory_int(vm, MOD(pc + sum % IDX_MOD));
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], load);
		if (vm_verbose_operations(vm))
			ft_printf("P    %d | ldi %d %d r%d\n       | -> load from %d + %d \
= %d (with pc and mod %d)\n", process->no, param1, param2, process->instruction.
params[2].uch, param1, param2, sum, pc + sum % IDX_MOD);
	}
	vm_advance_pc(process, vm);
}

/*
static short	get_param(t_process *process, t_vm *vm, int *index,
						t_arg_type type)
{
	short			indirection;
	unsigned char	reg_number;

	if (type == T_DIR)
	{
		*index = MOD(*index + 2);
		return (vm_read_memory_short(vm, *index - 2));
	}
	else if (type == T_IND)
	{
		indirection = vm_read_memory_short(vm, *index) % IDX_MOD;
		*index = MOD(*index + 2);
		return (vm_read_memory_short(vm,
				MOD(vm_read_register(process->pc) + indirection)));
	}
	else
	{
		reg_number = vm->memory[MOD(*index)];
		*index = MOD(*index + 1);
		if (reg_number > 0 && reg_number <= REG_NUMBER)
		// !!! This will cast an int to a short!! Should we do that??
			return (vm_read_register(process->registers[reg_number]));
		*index = -1;
		return (0);
	}
}

void			vm_ldi(t_process *process, t_vm *vm)
{
	int				index;
	short			param1;
	short			param2;
	unsigned char	reg_number;

	index = vm_read_register(process->pc) + 2;
	if (vm_check_parameter_types(process->instruction))
	{
		param1 = get_param(process, vm, &index, process->instruction.args[0]);
		if (index > 0)
			param2 = get_param(process, vm, &index,
								process->instruction.args[1]);
		if (index > 0)
		{
			reg_number = vm->memory[MOD(index)];
			if (reg_number > 0 && reg_number <= REG_NUMBER)
				vm_store_in_register(&process->registers[reg_number],
						vm_read_memory_int(vm,
							MOD((param1 + param2) % IDX_MOD)));
		}
	}
	vm_advance_pc(process, vm);
}
*/
