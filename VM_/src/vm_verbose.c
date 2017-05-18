/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:42:32 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:42:33 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_verbose_lives(t_vm *vm)
{
	if (vm->verbose & 1)
		return (1);
	else
		return (0);
}

int		vm_verbose_cycles(t_vm *vm)
{
	if (vm->verbose & 2)
		return (1);
	else
		return (0);
}

int		vm_verbose_operations(t_vm *vm)
{
	if (vm->verbose & 4)
		return (1);
	else
		return (0);
}

int		vm_verbose_deaths(t_vm *vm)
{
	if (vm->verbose & 8)
		return (1);
	else
		return (0);
}

int		vm_verbose_pc(t_vm *vm)
{
	if (vm->verbose & 16)
		return (1);
	else
		return (0);
}
