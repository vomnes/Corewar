/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:15:12 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:15:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_error_exit(t_vm *vm, char *message)
{
	ft_putendl_fd(message, 2);
	vm_delete_data(vm);
	(void)vm;
	exit(-1);
}
