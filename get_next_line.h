/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 23:27:11 by dfisher          ###   ########.fr       */
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


/* STDARG.H*/
/* Assume: width of stack == width of int. */

#define	STACK_WIDTH	sizeof(int)

/* Round up object width so it's an even multiple of STACK_WIDTH.
Using AND for modulus here, so STACK_WIDTH must be a power of 2. */
#define	TYPE_WIDTH(TYPE)				\
	((sizeof(TYPE) + STACK_WIDTH - 1) & ~(STACK_WIDTH - 1))

/* point the va_list pointer to LASTARG,
then advance beyond it to the first variable arg */
#define	ft_va_start(PTR, LASTARG)				\
	PTR = (ft_va_list)((char *)&(LASTARG) + TYPE_WIDTH(LASTARG))

/* Increment the va_list pointer, then "return"
(evaluate to, actually) the previous value of the pointer. */
#define ft_va_arg(PTR, TYPE)	(			\
	PTR = (char *)(PTR) + TYPE_WIDTH(TYPE)		\
				,			\
	*((TYPE *)((char *)(PTR) - TYPE_WIDTH(TYPE)))	\
				)
#define ft_va_end(PTR)	/* nothing */

typedef void *ft_va_list;
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


