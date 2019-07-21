/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:05:29 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 20:23:51 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() function locates the first occurrence of c (converted to a char)
** in the string pointed to by s.The terminating null character is considered to
** be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)(s + len));
	while (len--)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
