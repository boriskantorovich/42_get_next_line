/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:30:26 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/26 17:35:32 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>

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

int		line_copy(char **line, char *content, int *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *line;
	while (content[i] && content[i] != str[j])
	{
		j = 0;
		while (content[i] && content[i] != str[j] && str[j])
			j++;
		i++;
	}
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

ssize_t	read_fd(int fd, char **content, char buffer[BUFF_SIZE + 1], int *str)
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
		if (ft_strchr(buffer, (char)*str))
			break ;
	}
	return (read_size);
}
/*
int		*get_args(int	flag, ...)
{
	va_list	tmp;
	int		*args;
	va_start(tmp, flag);
	int	i;

	i = 0;
	if (!(args = (int *)malloc(sizeof(int) * flag)))
		return (NULL);
	while (i < flag)
	{
		args[i] = va_arg(tmp, int);
		printf("%d:	%d\n", i, args[i]);
		ft_putchar(ENDL);
		i++;
	}
	va_end(tmp);
	return (args);
}
*/
int		get_next_line_core(const int fd, char **line, int mark, int flag, ...)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*current;
	char			*tmp;
	ssize_t			read_size;



	va_list	tmpr;
	int		*args;
	va_start(tmpr, flag);
	int	i;

	i = 0;
	if (!(args = (int *)malloc(sizeof(int) * flag)))
		return (0);
	while (i < flag)
	{
		args[i] = va_arg(tmpr, int);
		printf("%d:	%c\n", i, args[i]);
		ft_putchar(ENDL);
		i++;
	}

	ft_putnbr(mark);
	if (fd < 0 || fd > MAX_FILDES || !line || read(fd, buffer, 0) < 0 ||\
	!(current = check_content(fd, &head)))
		return (-1);
	tmp = current->content;
	read_size = read_fd(fd, &tmp, buffer, &flag);
	printf("HMMMM %s\n", tmp);
	if (read_size <= 0 && !*tmp)
		return (0);
	current->content = tmp;
	read_size = line_copy(line, current->content, &flag);
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

int		get_next_line(const int fd, char **line)
{
	return (get_next_line_core(fd, line, G_CHRS, 3, 'a', 'b', 'c'));
}
