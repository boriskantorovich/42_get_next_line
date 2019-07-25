/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 21:25:56 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft.h"
/*
** Get optimal buff_size running
** $> diskutil info / | grep "Block Size"
*/

# define BUFF_SIZE 9999
# define ENDL '\n'
/*exclude this includes for release */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_file
{
	char			*content;
	int				fildes;
	int				flag:1;
	struct s_file	*next;
}					t_file;

typedef struct	s_gnl
{
	char		*buf;
	int			count;
	int			i;
	int			nl;
	int			fd;
}				t_gnl;

typedef struct	s_f
{
	int				d;
	int				s;
	char			*b;
	char			*t;
	char			r[BUFF_SIZE];
	int				i;
	int				j;
	int				k;
	struct s_f		*n;
}				t_f;

/*
** Get max value of filedescriptor running
** $> launchctl limit maxfiles
** in bash
*/

# define MAX_FILDES 256

int	get_next_line(const int fd, char **line);

#endif