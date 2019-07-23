/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:29:11 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/23 21:02:16 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		ln_cpy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	//printf("LINE IS %s\n", *line);
	return (i);
}

static t_file	*ft_lstnew_s(void const *content, size_t content_size)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->fildes = 0;
	}
	else
	{
		if (!(new->content = (char *)malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memmove(new->content, content, content_size);
		new->fildes = content_size;
	}
	new->next = NULL;
	return (new);
}


static void	ft_lstadd_s(t_file **alst, t_file *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_file    *makefile(int fd, t_file **hist)
{
    t_file    *tmp;

    if (!hist)
        return (NULL);
    tmp = *hist;
    while (tmp)
    {
        if ((int)tmp->fildes == fd)
            return (tmp);
        tmp = tmp->next;
    }
    tmp = ft_lstnew_s("", fd);
    ft_lstadd_s(hist, tmp);
    return (tmp);
}

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

//	printf("# try to read me\n");
	while ((read_size = read(fildes, buffer, BUFF_SIZE)) > 0)
		{
			//printf("# there is something to read\n");
			buffer[read_size] = '\0';
			if (!(*content = ft_strjoin(*content, buffer)))
				return (-1);
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
	size_t			read_size;
	char			*ptr_buf;
	char			*tmp;

//	printf("\n===============in gnl===============\n");
	ptr_buf = buffer;
	if (!line || fd < 0 || fd > MAX_FILDES || BUFF_SIZE < 1 || BUFF_SIZE > 10000
		|| (read(fd, buffer, 0)) < 0 || !(current = makefile(fd, &head)))
		return (-1);
	read_size = ft_readln(fd, ptr_buf, &current->content);
	//printf("\nread_size nb		%zu\n", read_size);
	//printf("%s\n", current->content);
	if (!read_size && !*current->content)
		return (0);
	read_size = ln_cpy(line, current->content, ENDL);
	//printf("\nread_size nb		%zu\n", read_size);
//	printf("\nline				%s\n", *line);
	tmp = current->content;
	/* breakpoint */
    if (tmp[read_size] != '\0')
    {
        current->content = ft_strdup(&((current->content)[read_size + 1]));
        free(tmp);
    }
    else
        tmp[0] = '\0';
    return (1);
}
