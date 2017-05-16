#include "vm.h"

void		vm_sti(t_process *process, t_vm *vm)
{
	int	pc;
	int	param2;
	int	param3;
	int	sum;
	int	storage;

	pc = vm_read_register(process->pc);
	if( vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param2 = vm_param_to_int_idx(process, vm, 1);
		param3 = vm_param_to_int_idx(process, vm, 2);
		sum = param2 + param3;
		storage = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		vm_store_in_memory_int(vm, MOD(pc + sum % IDX_MOD), storage);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | sti r%hhd %d %d\n       | -> store to %d + %d = \
%d (with pc and mod %d)\n", process->no, process->instruction.params[0].uch,
param2, param3, param2, param3, sum, pc + sum % IDX_MOD);
	}
	vm_advance_pc(process, vm);
}

/*
static short			get_parameter(t_process *process, t_vm *vm, int pc, int i)
{
	short				parameter;
	int				no_register;

	parameter = 0;
	if ((i == 3 && process->instruction.second_type == T_REG) ||
		(i == 5 && process->instruction.third_type == T_REG))
	{
		no_register = vm->memory[MOD(pc + i)];

		//	tester ce qui se passe si no_register ne repond pas a ces conditions
		// 	Est-ce que l'index vaut 0 ou bien l'instruction n'est pas effectuee?
		if (no_register > 0 && no_register <= REG_NUMBER)
			parameter = vm_read_register(process->registers[no_register]);
	}
	else
		parameter = vm_read_memory_short(vm, MOD(pc + i));
	return (parameter);
}

static void		store_register(t_process *process, t_vm *vm, int pc)
{
	short		no_register;
	short			first_index;
	short			second_index;
	int			value;

	no_register = vm->memory[MOD(pc + 2)];
	if (no_register > 0 && no_register <= REG_NUMBER)
	{
		value = vm_read_register(process->registers[no_register]);
		first_index = get_parameter(process, vm, pc, 3);
		if (process->instruction.second_type == T_REG)
			second_index = get_parameter(process, vm, pc, 4);
		else
			second_index = get_parameter(process, vm, pc, 5);
		vm_fill_cells(vm, pc + (first_index + second_index), process->player_no);
		vm_store_in_memory_int(vm, pc + (first_index + second_index), value);
	}
}

void			vm_sti(t_process *process, t_vm *vm)
{
	int		pc;

	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) == 1)
		store_register(process, vm, pc);
	vm_advance_pc(process, vm);
}
*/
