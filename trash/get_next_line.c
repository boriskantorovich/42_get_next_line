#include "get_next_line.h"
#include "libft.h"

t_list	*check_content(int fd, t_list **list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, &tmp);
	return (tmp);
}

int        line_copy(char **line, char *content, char c)
{
    int        i;
    char    *tmp;

    i = 0;
    tmp = *line;
    while (content[i] && content[i] != c)
        i++;
    if (!(*line = ft_strndup(content, i)))
        return (0);
    return (i);
}

ssize_t	read_fd(int fd, char **content, char **buffer[BUFF_SIZE + 1])
{
	ssize_t read_size;
	//char	*tmp;

	while ((read_size = read(fd, *buffer, BUFF_SIZE)) > 0)
	{
		*buffer[read_size] = '\0';
		//tmp = *content;
		if (!(*content = ft_strjoin(*content, *buffer)))
			return (-1);
		//free(tmp);
		if (ft_strchr(*buffer, ENDL));
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
	read_size = read_fd(fd, &tmp, &buffer);
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
/*
int		get_next_line(const int fd, char **line)
{
	static t_f		*openfiles;
	t_f				*f;
	int				i;

	f = openfiles;
	while (!(i = 0) && f && f->d != fd)
		f = f->n;
	if (fd < 0 || (!f && (!(f = malloc(sizeof(*f))) ||
		((f->n = openfiles) && 0) || (f->d *= 0) || (f->d += fd) < 0 ||
		!(openfiles = f) || (f->i *= 0) || (f->j *= 0))) || (f->s *= 0))
		return (-1);
	while (!(f->k *= 0) && (f->i < f->j || (!(f->i *= 0) && (f->j = read(fd,
		f->r, BUFF_SIZE)) > 0)) && (f->s == 0 || f->r[f->i] != 10 || !(++f->i)))
	{
		if (i + BUFF_SIZE >= f->s && (f->k -= 1) && ((f->t = f->b) || 1)
				&& (f->b = (char *)malloc(sizeof(char) * (i + BUFF_SIZE + 1))))
			while (++(f->k) < i && (f->k) < f->s)
				free(((f->b[f->k] = f->t[f->k]) && (f->k + 1 < i) ? 0 : f->t));
		if (i + BUFF_SIZE >= f->s && ((!f->b && ((f->b = f->t) || 1))
					|| !(f->s = i + BUFF_SIZE + 1)))
			return (-1);
		while (f->i < f->j && f->r[f->i] != '\n')
			f->b[i++] = f->r[f->i++];
	}
	return ((i || f->j > 0) && (*line = f->b) && !(f->b[i] *= 0) ? 1 : f->j);
}
*/
/*
static char		*get_append(t_gnl *gnl)
{
	int i;

	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl));
}

static t_gnl	*get_gnl(t_list **lst, int fd)
{
	t_gnl	gnl;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		if (((t_gnl *)(temp->content))->fd == fd)
			return ((t_gnl *)(temp->content));
		temp = temp->next;
	}
	gnl.buf = ft_strnew(BUFF_SIZE);
	gnl.count = BUFF_SIZE;
	gnl.i = BUFF_SIZE;
	gnl.fd = fd;
	gnl.nl = 1;
	temp = ft_lstnew(&gnl, sizeof(t_gnl));
	ft_lstadd(lst, temp);
	return ((t_gnl *)(temp->content));
}

static void		del_gnl(t_list **lst, int fd, char **str)
{
	t_gnl	*gnl;
	t_list	**temp;
	t_list	*ptr;

	temp = lst;
	while (*temp)
	{
		gnl = (t_gnl *)((*temp)->content);
		if (gnl->fd == fd)
			break ;
		*temp = ((*temp)->next);
	}
	if (*temp)
	{
		ptr = (*temp)->next;
		ft_strdel(&(gnl->buf));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)temp);
		*temp = ptr;
	}
	ft_strdel(str);
}

static int		read_buffer(t_gnl *gnl, t_list **lst, char **temp, char **line)
{
	if (gnl->i == gnl->count)
	{
		gnl->count = read(gnl->fd, gnl->buf, BUFF_SIZE);
		if (gnl->count == -1)
		{
			del_gnl(lst, gnl->fd, temp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->count == 0)
		{
			if (gnl->nl == 0)
			{
				*line = *temp;
				return (1);
			}
		}
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	char			*temp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl = get_gnl(&lst, fd);
	temp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if ((ret = read_buffer(gnl, &lst, &temp, line)) != 0)
			return (ret);
		while (gnl->i < gnl->count)
		{
			temp = ft_strmerge(temp, get_append(gnl));
			if (gnl->nl)
			{
				*line = temp;
				return (1);
			}
		}
	}
	del_gnl(&lst, fd, &temp);
	return (0);
}
*/
/*
void		ft_lstdelete_element(t_list **alst, int fd)
{
	t_list		*tmppre;
	t_list		*tmp;

	tmppre = *alst;
	tmp = *alst;
	while (tmp->content_size != (size_t)fd)
	{
		tmppre = tmp;
		tmp = tmp->next;
	}
	if (tmp == *alst)
		*alst = tmp->next;
	tmppre->next = tmp->next;
	if (tmp->content != NULL)
		free(tmp->content);
	free(tmp);
}

t_list		*find_tmp_fd(t_list *list, int fd)
{
	t_list		*tmp;

	tmp = list;
	while (tmp && tmp->next != NULL && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	return (tmp);
}

int			create_line(t_list **tmp, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (((char *)((*tmp)->content))[i] != '\n' &&
		((char *)((*tmp)->content))[i] != '\0')
		i++;
	*line = ft_strsub((*tmp)->content, 0, i);
	str = (*tmp)->content;
	(*tmp)->content = ft_strsub((*tmp)->content,
		i + 1, ft_strlen((*tmp)->content) - i);
	ft_strdel(&str);
	return (1);
}

t_list		*get_list(int fd, t_list **list, char *buf)
{
	t_list		*tmp;
	char		*str;

	if (!*list)
	{
		*list = ft_lstnew(buf, ft_strlen(buf) + 1);
		(*list)->content_size = fd;
		tmp = list[0];
		return (tmp);
	}
	tmp = find_tmp_fd(*list, fd);
	if (tmp->content_size == (size_t)fd)
	{
		str = tmp->content;
		tmp->content = ft_strjoin(tmp->content, buf);
		ft_strdel(&str);
	}
	else
	{
		tmp->next = ft_lstnew(buf, ft_strlen(buf) + 1);
		tmp = tmp->next;
		tmp->content_size = fd;
	}
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*list = NULL;
	t_list			*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	tmp = find_tmp_fd(list, fd);
	if (tmp && tmp->content_size == (size_t)fd && ft_strchr(tmp->content, '\n'))
		return (create_line(&tmp, line));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = get_list(fd, &list, buf);
		if (ft_strchr(tmp->content, '\n'))
			break ;
	}
	if (tmp && tmp->content_size == (size_t)fd && *((char *)(tmp)->content))
		return (create_line(&tmp, line));
	else
	{
		if (tmp && tmp->content_size == (size_t)fd)
			ft_lstdelete_element(&list, fd);
		return (0);
	}
}
*/
/*
int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
*/
/*
int        line_copy(char **line, char *content, char c)
{
    int        i;
    char    *tmp;

    i = 0;
    tmp = *line;
    while (content[i] && content[i] != c)
        i++;
    if (!(*line = ft_strndup(content, i)))
        return (0);
    return (i);
}

t_list    *get_live(int fd, t_list **hist)
{
    t_list    *tmp;

    if (!hist)
        return (NULL);
    tmp = *hist;
    while (tmp)
    {
        if ((int)tmp->content_size == fd)
            return (tmp);
        tmp = tmp->next;
    }
    tmp = ft_lstnew("", fd);
    ft_lstadd(hist, tmp);
    return (tmp);
}

int        my_read(const int fd, char **content)
{
    int        read_result;
    char    *tmp;
    char    buf[BUFF_SIZE + 1];

    while ((read_result = read(fd, buf, BUFF_SIZE)))
    {
        buf[read_result] = '\0';
        tmp = *content;
        if (!(*content = ft_strjoin(*content, buf)))
            return (-1);
        free(tmp);
        if (ft_strchr(buf, ENDL))
            break ;
    }
    return (read_result);
}

int        get_next_line(const int fd, char **line)
{
    char            buf[BUFF_SIZE + 1];
    size_t            read_result;
    static t_list    *hist;
    t_list            *live;
    char            *tmp;

    if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
            (!(live = get_live(fd, &hist))))
        return (-1);
    tmp = live->content;
    read_result = my_read(fd, &tmp);
    live->content = tmp;
    if (!read_result && !*tmp)
        return (0);
    read_result = line_copy(line, live->content, ENDL);
    tmp = live->content;
    if (tmp[read_result] != '\0')
    {
        live->content = ft_strdup(&((live->content)[read_result + 1]));
        free(tmp);
    }
    else
        tmp[0] = '\0';
    return (1);
}
*/
