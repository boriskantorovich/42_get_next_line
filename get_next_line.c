/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:30:26 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 21:43:28 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_list	*check_content(int fd, t_list **list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

ssize_t	read_fd(int fd, char **content, char buffer[BUFF_SIZE + 1])
{
	ssize_t read_size;
	char	*tmp;

	while ((read_size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buffer)))
			return (-1);
		free(tmp);
		if (ft_strchr(buffer, ENDL))
			break ;
	}
	return (read_size);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*current;
	char			*tmp;
	ssize_t			read_size;

	if (fd < 0 || fd > MAX_FILDES || !line || read(fd, buffer, 0) < 0 ||\
	!(current = check_content(fd, &head)))
		return (-1);
	tmp = current->content;
	read_size = read_fd(fd, &tmp, buffer);
	if (read_size <= 0 && !*tmp)
		return (0);
	current->content = tmp;
	read_size = line_copy(line, current->content, ENDL);
	tmp = current->content;
	if (tmp[read_size] != '\0')
	{
		current->content = ft_strdup(&((current->content)[read_size + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
