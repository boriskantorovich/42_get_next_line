/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 23:03:09 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define G_CHRS 0x01
# define G_TRIM 0x02
# define G_LIST	0x04
# define G_GREP	0x08
# define G_EXCL	0x10

typedef char* t_va_list;

#define __va_argsiz(t)	\
	(((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
#define va_start(ap, pN)	\
	((ap) = ((va_list) (&pN) + __va_argsiz(pN)))
#define va_end(ap)	((void)0)
#define va_arg(ap, t)					\
	 (((ap) = (ap) + __va_argsiz(t)),		\
	  *((t*) (void*) ((ap) - __va_argsiz(t))))

/*
** Get optimal buff_size running
** $> diskutil info / | grep "Block Size"
*/

#include <stdio.h>
# define BUFF_SIZE 4096
# define ENDL '\n'

/*
** Get max value of filedescriptor running
** $> launchctl limit maxfiles
** in bash
*/

# define MAX_FILDES 256

int	get_next_line(const int fd, char **line);

#endif


