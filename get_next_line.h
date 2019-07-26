/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boriskantorovich <boriskantorovich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/26 09:54:11 by boriskantor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define G_CHRS 0x01
# define G_TRIM 0x02
# define G_LIST 0x04
# define G_GREP 0x08
# define G_EXCL 0x10



typedef char* ft_va_list;

/*
 * Amount of space required in an argument list (ie. the stack) for an
 * argument of type t.
 */
#define __ft_va_argsiz(t)	\
	(((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define ft_va_start(ap, pN)	\
	((ap) = ((ft_va_list) (&pN) + __ft_va_argsiz(pN)))

#define ft_va_end(ap)	((void)0)

/*
 * Increment ap to the next argument in the list while returing a
 * pointer to what ap pointed to first, which is of type t.
 *
 * We cast to void* and then to t* because this avoids a warning about
 * increasing the alignment requirement.
 */

#define ft_va_arg(ap, t)					\
	 (((ap) = (ap) + __ft_va_argsiz(t)),		\
	  *((t*) (void*) ((ap) - __ft_va_argsiz(t))))


/*
typedef char *ft_va_list;
#define ft_va_start(ap, param) (ap = &param + sizeof(param))

#define ft_va_end(ap) (void)(ap = NULL)

#define ft_va_copy(dest, src) (dest = src)

#define ft_va_arg(ap, type) (*(type*)((ap = ap + sizeof(type)) - sizeof(type)))

 */

/*
# define STACK_SIZE sizeof(int)
# define T_WIDTH(T) sizeof(T)
//+ STACK_SIZE - 1) & ~(STACK_SIZE - 1))
# define ft_va_start(P, LASTARG) P = (ft_va_list)((char *)&(LASTARG) + T_WIDTH(LASTARG))
# define ft_va_arg(P, T) (P = (char *)(P) + T_WIDTH(T), *((T *)((char *)(P) - T_WIDTH(T))))
# define ft_va_end(PTR) 
 

typedef void *ft_va_list;*/

/*
** Get optimal buff_size running
** $> diskutil info / | grep "Block Size"
*/

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
