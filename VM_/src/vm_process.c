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
	int			count;

	if (!(new_process = (t_process *)ft_memalloc(sizeof(*new_process))))
		vm_error_exit(vm, "Malloc failed while creating a new process struct");
	count = 1;
	if (!(vm->processes))
		vm->processes = new_process;
	else
	{
		process_list = vm->processes;
		count = 2;
		while (process_list->next)
		{
			process_list = process_list->next;
			count++;
		}
		process_list->next = new_process;
		new_process->prev = process_list;
	}
	new_process->no = count;
	return (new_process);
}
