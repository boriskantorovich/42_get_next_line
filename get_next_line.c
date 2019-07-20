/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:29:11 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/20 21:25:40 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(int fd, t_list **old)
{
	t_list	*tmp;

	if (!old)
		return (NULL);
	tmp = *old;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(old, tmp);
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	char buffer[BUFF_SIZE + 1];
	static t_list	*old;
	t_list	*list;

	/* how to read from file */
	if (fd < 0 || !line || !(list = get_list(fd, &old)))
		return (-1);
	//printf("# ");
	if (read(fd, buffer, BUFF_SIZE) != sizeof(buffer))
		printf("# Read errors\n");
	size_t i = 0;
	printf("%zu\n", sizeof(buffer));
	while (i < sizeof(buffer))
	{
		if (buffer[i] == EOF)
			break ;
		printf("# %c", buffer[i]);
		i++;
	}
	line--;
	if (1 && i)
		return (1);
	else if (1)
		return (-1);
	return (0);
}


