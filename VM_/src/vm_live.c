#include "vm.h"

static void	vm_initialize_cycle_delta_alive(t_vm *vm)
{
	t_process	*current_process;

	current_process = vm->processes;
	while (current_process)
	{
		if (current_process->alive)
			current_process->cycle_delta_alive = 1;
		current_process = current_process->next;
	}
}

static void	vm_erase_cycle_delta_alive(t_vm *vm)
{
	t_process	*current_process;

	current_process = vm->processes;
	while (current_process)
	{
		current_process->cycle_delta_alive = 0;
		current_process = current_process->next;
	}
}

static void	vm_cycle_delta(t_vm *vm)
{
	static int	delta_lives = 0;
	int			all_alive;
	t_process	*current_process;

	if (delta_lives == 0)
		vm_initialize_cycle_delta_alive(vm);
	delta_lives += 1;
	if (delta_lives >= NBR_LIVE)
	{
		all_alive = 1;
		current_process = vm->processes;
		while (current_process)
		{
			if (current_process->cycle_delta_alive && !current_process->alive)
				all_alive = 0;
			current_process = current_process->next;
		}
		if (all_alive)
			vm->cycle_to_die -= CYCLE_DELTA;
		vm_erase_cycle_delta_alive(vm);
		delta_lives = 0;
	}
}

static void	vm_add_live(t_vm *vm, int player_no)
{
	t_live	*new_live;
	t_live	*live_lst;

	if (!(new_live = (t_live *)ft_memalloc(sizeof(*new_live))))
		vm_error_exit(vm, "Malloc failed while creating a live struct");
	if (!vm->lives)
		vm->lives = new_live;
	else
	{
		live_lst = vm->lives;
		while (live_lst->next)
			live_lst = live_lst->next;
		live_lst->next = new_live;
	}
	new_live->player_no = player_no;
}

void		vm_live(t_process *process, t_vm *vm)
{
	int			pc;
 	int			player_nb;
	t_player	*player;

	pc = vm_read_register(process->pc);
	player_nb = vm_read_memory_int(vm, pc + 1);
	player= vm_get_player(vm, player_nb);
	if (player)
	{
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
		player_nb, player->name);
		player->nb_lives += 1;
		vm_add_live(vm, player_nb);
		vm_cycle_delta(vm);
	}
	vm_store_in_register(&process->pc, MOD(pc + 5));
}
