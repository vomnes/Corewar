/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_print_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:22:55 by pdady             #+#    #+#             */
/*   Updated: 2017/05/20 13:42:58 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			print_color_w(t_vm vm, WINDOW *window, int color, int pos)
{
	wattron(window, COLOR_PAIR(color));
	wprintw(window, "%02x", vm.memory[pos]);
	wattroff(window, COLOR_PAIR(color));
}

static void			check_cells(t_vm *vm, WINDOW *window, int pos)
{
	if (vm->cells[pos].present != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no + 4, pos);
	else if (vm->cells[pos].recent == 1 && vm->cells[pos].count-- > 0)
		print_color_w(*vm, window, 9, pos);
	else if (vm->cells[pos].player_no != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no, pos);
	else
		print_color_w(*vm, window, 10, pos);
}

void				vis_print_memory(t_vm *vm, WINDOW *window)
{
	static int		count = 0;
	int				i;
	int				color;

	i = -1;
	color = 0;
	wmove(window, 1, 1);
	if (count++ < vm->speed || vm->pause == 1)
		return ;
	else
		count = 0;
	while (++i < MEM_SIZE)
	{
		check_cells(vm, window, i);
		((i + 1) % 64 == 0) ? wprintw(window, "\n ") : wprintw(window, " ");
	}
	box(window, 0, 0);
	wrefresh(window);
}
