/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:15:13 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:29:59 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** RETURN VALUES:
** The memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example).  Zero-length strings are always identical.  This behavior
** is not required by C and portable code should only depend on the
** sign of the returned value.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_c++ != *s2_c++)
			return ((*(--s1_c) > *(--s2_c)) ? \
			(*s1_c - *s2_c) : ((-1) * (*s2_c - *s1_c)));
	}
	return (0);
}
