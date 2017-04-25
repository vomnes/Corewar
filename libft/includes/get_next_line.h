/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:21:58 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 17:58:18 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE	 128

typedef struct		s_buffer
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	int				curseur;
	int				end;
}					t_buffer;

int					get_next_line(const int fd, char **line);
int					ft_skip_characters(char **str, char *characters);
int					get_next_int(char **line, int *int_ptr);
int					get_next_string(char **line, char **str);

#endif
