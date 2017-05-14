/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:08:06 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/14 14:50:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_H
# define REVERSE_H

# include "asm.h"

# define MEMORY_SIZE 10000

void			rev_process_reverse_binary(int argc, char **argv);
unsigned int	rev_parse_header(size_t size, unsigned char buf[size]);
void			rev_transform_instructions(unsigned int memory[MEMORY_SIZE], \
size_t size_prog);

#endif
