/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:50:20 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 19:59:18 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*get_fd(t_file **head, int fd)
{
	t_file	*elem;

	elem = *head;
	while (elem != NULL)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	elem = (t_file*)ft_lstnew("", 1);
	elem->fd = fd;
	elem->next = *head;
	*head = elem;
	return (elem);
}

static int		fill_buffer(t_file *elem, char *str)
{
	char	*temp;

	temp = elem->buffer;
	if (!(elem->buffer = str))
		return (-1);
	free(temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head;
	t_file			*elem;
	char			buf[BUFF_SIZE + 1];
	int				bytes;
	int				i;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	elem = get_fd(&head, fd);
	while (!ft_strchr(elem->buffer, '\n') && (bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (fill_buffer(elem, ft_strnjoin(elem->buffer, buf, bytes)) == -1)
			return (-1);
	}
	i = 0;
	while ((elem->buffer)[i] != '\0' && ((elem->buffer)[i]) != '\n')
		i++;
	*line = ft_strndup(elem->buffer, i);
	if ((elem->buffer)[i] == '\n')
		i++;
	if (fill_buffer(elem, ft_strdup(elem->buffer + i)) == -1)
		return (-1);
	return (i ? 1 : 0);
}
