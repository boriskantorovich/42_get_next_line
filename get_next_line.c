/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:29:11 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/21 20:01:21 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_file	*ft_newfile(int fildes, t_file **head)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->content = "";
	new->fildes = fildes;
	new->next = *head;
	return (new);
}

t_file	*ft_makefile(int fildes, t_file **head)
{
	t_file	*checkpoint;

	if (!head)
		return (NULL);
	checkpoint = *head;
	while (checkpoint)
	{
		if (checkpoint->fildes == fildes)
			return (checkpoint);
		checkpoint = checkpoint->next;
	}
	checkpoint = ft_newfile(fildes, head);
	return (checkpoint);
}

static int		ft_readln(int fildes, char *buffer, char **content)
{
	int	read_size;

	while ((read_size = read(fildes, buffer, BUFF_SIZE)) > 0)
		{
			buffer[read_size] = '\0';
			*content = ft_strjoin(*content, buffer);
			if (ft_strchr(buffer, ENDL))
				break ;
		}
	return (read_size);
}

/*
** 1. If fd < 0 => error while open(const char *path,..)
** 2. If line == NULL
** 3.
*/
int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_file	*head;
	t_file			*current;
	int				read_size;
	char			*ptr_buf;
	int				i;

	printf("\nin gnl\n");
	ptr_buf = buffer;
	if (!line || fd < 0 || fd > MAX_FILDES || BUFF_SIZE < 1
		|| (read(fd, buffer, 0)) < 0 || !(current = ft_makefile(fd, &head)))
		return (-1);
	read_size = ft_readln(fd, ptr_buf, &current->content);
		printf("\n???		%d\n", read_size);
	i = 0;
	printf("\nso what happens\n");
    while (current->content[i] && current->content[i] != ENDL)
        i++;
	*line = ft_strndup(current->content, i);
	if (!read_size && !*current->content)
	{
		printf("\nAM i right?\n");
		return (0);
	}
	if (1)
		return (1);
	return (1);
}
