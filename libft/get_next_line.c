/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:25:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/04 11:02:02 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 1
#define NB_MAX_FD 4864

static int	get_remain_line(char **remain, char **line)
{
	char *new_remain;

	if ((new_remain = ft_strchr(*remain, '\n')))
	{
		new_remain[0] = '\0';
		if (!(*line = ft_strdup(*remain)))
			return (-1);
		if (!(*remain = ft_strdup(new_remain + 1)))
			return (-1);
		ft_strddel(new_remain);
		return (1);
	}
	return (0);
}

static int	get_line(char *buf, char **remain, char **line)
{
	char *new_remain;
	char *tmp;

	if (!(*remain))
		if (!(*remain = ft_strdup("\0")))
			return (-1);
	if ((new_remain = ft_strchr(buf, '\n')))
	{
		new_remain[0] = '\0';
		tmp = *remain;
		if (!(*line = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
		if (!(*remain = ft_strdup(new_remain + 1)))
			return (-1);
		ft_strddel(new_remain);
		return (1);
	}
	tmp = *remain;
	if (!(*remain = ft_strjoin(tmp, buf)))
		return (-1);
	free(tmp);
	return (0);
}

static int	last_line(char **remain, char **line)
{
	if ((*line = ft_strdup(*remain)))
	{
		if (*line[0] == '\0')
			return (0);
		ft_strdel(remain);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*remain[NB_MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (BUFF_SIZE <= 0 || fd < 0 || fd > NB_MAX_FD ||
		!line || (read(fd, NULL, 0) == -1))
		return (-1);
	if (remain[fd])
		if (get_remain_line(&(remain[fd]), line))
			return (1);
	while ((ret = read(fd, (void*)buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (get_line(buf, &(remain[fd]), line))
			return (1);
	}
	if (ret == -1)
		return (-1);
	if (remain[fd] == 0)
		return (0);
	return (last_line(&(remain[fd]), line) ? 1 : 0);
}
