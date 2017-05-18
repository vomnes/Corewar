/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_register_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:40:36 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:40:36 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_read_register(unsigned char reg[REG_SIZE])
{
	int	value;
	int	mask;
	int	i;

	value = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		value = value << 8;
		mask = (int)(reg[i]);
		value = value | mask;
		i++;
	}
	return (value);
}

void	vm_store_in_register(unsigned char (*reg)[REG_SIZE], int value)
{
	int				i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		(*reg)[i] = (unsigned char)value;
		value = value >> 8;
		i--;
	}
}

void	vm_print_register(unsigned char reg[REG_SIZE])
{
	int i;
	int started;

	i = 0;
	started = 0;
	while (i < REG_SIZE)
	{
		if (started)
			ft_printf(" ");
		started = 1;
		ft_printf("%.2hhx", reg[i]);
		i++;
	}
}

int		vm_valid_registers(t_instruction instruction)
{
	int i;

	i = 0;
	while (i < g_op_tab[instruction.opcode].nb_args)
	{
		if (instruction.args[i] == T_REG)
			if (instruction.params[i].uch < 1 ||
				instruction.params[i].uch > REG_NUMBER)
				return (0);
		i++;
	}
	return (1);
}
