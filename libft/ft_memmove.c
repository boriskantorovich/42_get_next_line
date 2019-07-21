/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:59:05 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:54:18 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the
** copy is always done in a non-destructive manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	unsigned char	*dst_end;
	unsigned char	*src_end;

	dst_uc = (unsigned char*)dst;
	src_uc = (unsigned char*)src;
	dst_end = (unsigned char *)dst + (len - 1);
	src_end = (unsigned char *)src + (len - 1);
	if (dst == NULL && src == NULL && len)
		return (NULL);
	if (src_uc < dst_uc)
		while (len--)
			*(dst_end--) = *(src_end--);
	else
		while (len--)
			*(dst_uc++) = *(src_uc++);
	return (dst);
}
