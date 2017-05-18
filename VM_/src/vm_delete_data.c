/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_delete_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:00:45 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:06:07 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_delete_data(t_vm *vm)
{
	t_process *current;

	current = vm->last_process;
	while (current)
		current = vm_delete_process(current, vm);
}
