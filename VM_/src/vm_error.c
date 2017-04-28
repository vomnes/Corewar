#include "vm.h"

void vm_error_exit(t_vm *vm, char *message)
{
	ft_putendl_fd(message, 2);
	//delete data in vm
	exit(-1);
}
