/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:08:50 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/17 15:58:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_buffer	*get_buffer(t_list **begin_list, int fd)
{
	t_list		*lst;
	t_buffer	new_buffer;

	lst = *begin_list;
	while (lst)
	{
		if (((t_buffer *)(lst->content))->fd == fd)
			return ((t_buffer *)(lst->content));
		lst = lst->next;
	}
	ft_bzero(&new_buffer, sizeof(new_buffer));
	new_buffer.fd = fd;
	if (!(lst = ft_lstnew(&new_buffer, sizeof(new_buffer))))
		return (NULL);
	ft_lstadd(begin_list, lst);
	return ((t_buffer *)(lst->content));
}

static void		delete_buffer(t_list **begin_list, int fd)
{
	t_list	*current;
	t_list	**prev_next;

	prev_next = begin_list;
	if (begin_list)
	{
		current = *begin_list;
		while (current)
		{
			if (((t_buffer *)(current->content))->fd == fd)
			{
				*prev_next = current->next;
				free(current->content);
				free(current);
				current = *prev_next;
			}
			else
			{
				prev_next = &current->next;
				current = current->next;
			}
		}
	}
}

/*
** Returns 	10 upon successful reading
**			0 if there is nothing to read
**			-1 in case of an error
*/

static int		read_to_buffer(t_buffer *buffer)
{
	int		ret;

	ret = read(buffer->fd, buffer->buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	(buffer->buff)[ret] = '\0';
	buffer->curseur = 0;
	buffer->end = ret;
	if (ret == 0)
		return (0);
	return (10);
}

/*
** Returns 	10 if the buffer needs to be renewed
**			1 if the \n was found
**			-1 if there is an error
*/

static int		read_from_buffer(t_buffer *buffer, char **line)
{
	int		i;
	char	*to_add;
	int		output;

	output = 10;
	i = buffer->curseur - 1;
	while (++i < buffer->end)
	{
		if ((buffer->buff)[i] == '\n')
		{
			(buffer->buff)[i] = '\0';
			output = 1;
			break ;
		}
	}
	if (!(to_add = ft_strjoin(*line, &(buffer->buff)[buffer->curseur])))
		return (-1);
	free(*line);
	*line = to_add;
	buffer->curseur = i + 1;
	return (output);
}

/*
**	Returns	1 if the line was read
**			0 if reading is done
**			-1 if there is an error
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*buffer_list = NULL;
	t_buffer		*buffer;
	int				status;

	if (line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(buffer = get_buffer(&buffer_list, fd)))
		return (-1);
	*line = NULL;
	status = 10;
	while (status == 10)
	{
		status = read_from_buffer(buffer, line);
		if (status == 10)
			status = read_to_buffer(buffer);
	}
	if (status == 0)
	{
		delete_buffer(&buffer_list, fd);
		if (ft_strlen(*line) > 0)
			status = 1;
	}
	return (status);
}
