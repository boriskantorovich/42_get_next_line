/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:19 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:52:17 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  strncpy() function copies at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled with
** `\0' characters.  Otherwise, dst is not terminated.
** The source and destination strings should not overlap, as the behavior is
** undefined.
** RETURN VALUES
** The strcpy() and strncpy() functions return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
