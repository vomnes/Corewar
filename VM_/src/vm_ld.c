#include "vm.h"

/*
static void		print_parameter(t_instruction instruction, int i)
{
	if (instruction.args[i] == T_REG)
		ft_printf(" r%hhd", instruction.params[i].uch);
	else if (instruction.args[i] == T_DIR)
}

static void		vm_print_instruction_if_necess(t_process *process, t_vm *vm,)
{
	int i;

	if (vm_verbose_operations(vm))
	{
		ft_printf("P %d | %s %d r", process->no,
		g_op_tab[process->instruction.opcode].name);
		i = 0;
		while (i < g_op_tab[process->instruction.opcode].nb_args)
		{
			print_parameter(process->instruction, i);
			i++;
		}
	}
}
*/

void			vm_ld(t_process *process, t_vm *vm)
{
	int	load;
	int	pc;

//	pc = vm_read_register(process->pc);
	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		if (process->instruction.first_type == T_DIR)
			load = process->instruction.params[0].in;
		else
			load = vm_read_memory_int(vm, pc +
				process->instruction.params[0].sh % IDX_MOD);
		vm_store_in_register(
			&process->registers[process->instruction.params[1].uch], load);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | ld %d r%hhd\n", process->no, load,
			process->instruction.params[1].uch);
		process->carry = 0;
		if (load == 0)
			process->carry = 1;
	}
	vm_advance_pc(process, vm);
}


// Ancienne version
/*
static void			get_parameters(t_vm *vm, t_process *process, int pc, int i)
{
	int				first_param;
	int				second_param;
	int				tmp;

	tmp = 0;
	first_param = 0;
	second_param = vm->memory[MOD(pc + i)];
	if (i == 6 && second_param > 0 && second_param <= REG_NUMBER)
	{
		first_param = vm_read_memory_int(vm, pc + 2);
		vm_store_in_register(&process->registers[second_param], first_param);
		process->carry = 1;
	}
	else if (i == 4 && second_param > 0 && second_param <= REG_NUMBER)
	{
		first_param = vm_read_memory_short(vm, pc + 2);
		tmp = vm_read_memory_int(vm, (pc + (first_param % IDX_MOD)));
		vm_store_in_register(&process->registers[second_param], tmp);
		process->carry = 1;
	}
	else
		process->carry = 0;
}

void				vm_ld(t_process *process, t_vm *vm)
{
	unsigned int	pc;

	pc = vm_read_register(process->pc);
	if (process->instruction.first_type == T_DIR)
		get_parameters(vm, process, pc, 6);
	else if (process->instruction.first_type == T_IND)
		get_parameters(vm, process, pc, 4);
	else
		process->carry = 0;
	vm_advance_pc(process, vm);
}
*/
