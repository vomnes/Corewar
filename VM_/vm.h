/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:19:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/25 19:57:30 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

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
