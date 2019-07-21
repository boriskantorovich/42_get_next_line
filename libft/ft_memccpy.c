/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:14:31 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 20:24:57 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.  Otherwise, n bytes are copied, and a NULL pointer
** is returned.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

static void	*ft_mempccpy(void *dst, const void *src, size_t n)
{
	return (ft_memcpy(dst, src, n) + n);
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *result;

	if (dst == NULL && src == NULL && n)
		return (NULL);
	result = (unsigned char *)ft_memchr(src, c, n);
	if (result != NULL)
		return (ft_mempccpy(dst, src, result - (unsigned char *)src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
