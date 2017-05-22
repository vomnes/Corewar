/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:54 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:07:59 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_memory_dump(t_vm vm)
{
	size_t		i;

	i = -1;
	ft_printf("0x%04x : ", 0);
	while (++i < MEM_SIZE)
	{
		ft_printf("%02x ", vm.memory[i]);
		if ((i + 1) % 32 == 0)
			ft_putchar('\n');
		if ((i + 1) % 32 == 0 && (i + 1) % MEM_SIZE != 0)
			ft_printf("0x%04x : ", i + 1);
	}
}

void		vm_dump_if_necessary(t_vm *vm)
{
	if (vm->dumps > -1 && vm->dumps == vm->cycle_nbr)
	{
		print_memory_dump(*vm);
		vm_delete_data(vm);
		exit(0);
	}
}
