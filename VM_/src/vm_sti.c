#include "vm.h"

static int			get_parameter(t_process *process, t_vm *vm, int pc, int i)
{
	int				parameter;
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
	int		first_index;
	int		second_index;
	long long			value;

	no_register = vm->memory[MOD(pc + 2)];
	if (no_register > 0 && no_register <= REG_NUMBER)
	{
		value = vm_read_register(process->registers[no_register]);
		first_index = get_parameter(process, vm, pc, 3);
		if (process->instruction.second_type == T_REG)
			second_index = get_parameter(process, vm, pc, 4);
		else
			second_index = get_parameter(process, vm, pc, 5);
		vm_store_in_memory_int(vm, pc + (first_index + second_index), value);
	}
}

void			vm_sti(t_process *process, t_vm *vm)
{
	int		pc;

	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) == 1)
		store_register(process, vm, pc);
	vm_advance_pc(process);
}
