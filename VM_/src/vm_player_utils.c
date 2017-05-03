#include "vm.h"

char 	*vm_get_player_name(t_vm *vm, int player_nb)
{
	int i;

	i = 1;
	while (i <= vm->nb_players)
	{
		if ((vm->players[i]).number == player_nb)
			return ((vm->players[i]).name);
		i++;
	}
	return (NULL);
}
