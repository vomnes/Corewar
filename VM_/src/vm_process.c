#include "vm.h"

/*
**	This function creates a new process, adds it to the VM's list of processes,
**	initializes all its fields to 0, except the process number which is
**	automatically assigned. All other fields will have to be initialized
**	manually.
**	Returns a pointer to the new process created.
*/

t_process	*vm_create_process(t_vm *vm)
{
	t_process	*new_process;
	t_process	*process_list;
	static int	count = 0;

	if (!(new_process = (t_process *)ft_memalloc(sizeof(*new_process))))
		vm_error_exit(vm, "Malloc failed while creating a new process struct");
	count++;
	if (!(vm->processes))
		vm->processes = new_process;
	else
	{
		process_list = vm->processes;
		while (process_list->next)
			process_list = process_list->next;
		process_list->next = new_process;
		new_process->prev = process_list;
	}
	new_process->no = count;
	new_process->alive = 1;
	vm->nb_processes += 1;
	vm->nb_alive_processes += 1;
	vm->last_process = new_process;
	return (new_process);
}

/*
**	Deletes "process" from the list (in vm->processes).
**	Returns a pointer to the next process in the list.
*/

t_process	*vm_delete_process(t_process *process, t_vm *vm)
{
	t_process	*next;

	if (process)
	{
		if (process->next)
			process->next->prev = process->prev;
		else
			vm->last_process = process->prev;
		if (process->prev)
			process->prev->next = process->next;
		else
			vm->processes = process->next;
		next = process->next;
		vm->nb_alive_processes -= 1;
		free(process);

		return (next);
	}
	return (NULL);
}

void 		vm_copy_process(t_process *parent, t_process *child, t_vm *vm)
{
	int i;

	i = 1;
	while (i <= REG_NUMBER)
	{
		vm_store_in_register(&child->registers[i],
			vm_read_register(parent->registers[i]));
		i++;
	}
	child->player_no = parent->player_no;
	child->alive = parent->alive;
	child->carry = parent->carry;
	child->last_live_cycle = vm->cycle_nbr;
}

/*
**	Returns a pointer to the t_process that corresponds to the number specified
**	as a parameter. If there are less than "no" processes in the VM, an ERROR
**	message is written and a NULL pointer is returned.
*/

t_process	*vm_get_process(t_vm *vm, int no)
{
	int			i;
	t_process	*current;

	i = 0;
	if (no >= 1)
	{
		if ((current = vm->processes))
			i = 1;
		while (current && current->next && i < no)
		{
			current = current->next;
			i++;
		}
		if (i == no)
			return (current);
	}
	ft_dprintf(2, "ERROR: Unable to reach process no %d\n", no);
	return (NULL);
}

// A enlever

void		vm_print_process(t_process *process)
{
	int i;

	ft_printf("Process no %d\n", process->no);
	ft_printf("Belongs to player no %d\n", process->player_no);
	if (process->alive)
		ft_printf("This process is alive\n");
	else
		ft_printf("This process is dead\n");
	ft_printf("Carry: %d\n", process->carry);
	ft_printf("PC : ");
	vm_print_register(process->pc);
	ft_printf("\n");
	ft_printf("Registers:\n");
	i = 1;
	while (i <= REG_NUMBER)
	{
		ft_printf("\tRegister %d: ", i);
		vm_print_register(process->registers[i]);
		ft_printf("\n");
		i++;
	}

	ft_printf("Instruction: %hhd\n", process->instruction.opcode);
}
