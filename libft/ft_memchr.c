/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:14:52 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/21 15:50:48 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_uc;
	unsigned char c_uc;

	s_uc = (unsigned char *)s;
	c_uc = (unsigned char)c;
	while (n--)
	{
		if (*(s_uc++) == c_uc)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
