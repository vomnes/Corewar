#include "vm.h"

void		vm_st(t_process *process, t_vm *vm)
{
	int	pc;
	int	storage;

	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		storage = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		if (process->instruction.second_type == T_REG)
			vm_store_in_register(
			&process->registers[process->instruction.params[1].uch], storage);
		else
		{
			vm_store_in_memory_int(vm,
			MOD(pc + process->instruction.params[1].sh % IDX_MOD), storage);
			vm_fill_cells(vm, MOD(pc + process->instruction.params[1].sh %
			IDX_MOD), process->player_no);
		}
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | st r%hhd %d\n", process->no, process->
			instruction.params[0].uch, process->instruction.params[1].sh);
	}
	vm_advance_pc(process, vm);
}


/*
static void		get_parameters(t_process *process, t_vm *vm, int pc)
{
	int			first_param;
	int			second_param;
	int			value;

	first_param = vm->memory[MOD(pc + 2)];
	second_param = 0;
	if (first_param <= 0 || first_param > REG_NUMBER)
		return ;
	if (process->instruction.second_type == T_IND)
	{
		second_param = vm_read_memory_short(vm, pc + 3);
		second_param = MOD(second_param);
		value = vm_read_register(process->registers[first_param]);
		vm_fill_cells(vm, pc + (second_param % IDX_MOD), process->player_no);
		vm_store_in_memory_int(vm, pc + ((second_param % IDX_MOD)), value);// Check if second_param <= 0 ?
	}
	else if (process->instruction.second_type == T_REG)
	{
		second_param = vm->memory[MOD(pc + 3)];
		if (second_param > 0 && second_param <= REG_NUMBER)
		{
			value = vm_read_register(process->registers[first_param]);
			vm_store_in_register(&process->registers[second_param], value);
		}
	}
}

void			vm_st(t_process *process, t_vm *vm)
{
	int			pc;

	pc = vm_read_register(process->pc);
	if (process->instruction.first_type == T_REG)
		get_parameters(process, vm, pc);
	vm_advance_pc(process, vm);
}
*/
