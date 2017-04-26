/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:19:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/26 17:06:35 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <fcntl.h>
#include <stdio.h>
typedef	struct		s_player
{
	char			*name;
	int				nb_lives;
}					t_player;

typedef struct		s_vm
{
	unsigned char	*memory;
	t_player		*players;
	int				cycle_nbr;
	
}					t_vm;

#endif
