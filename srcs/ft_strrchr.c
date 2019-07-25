/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:40 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:50:38 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() function locates the last occurrence of c (converted to a char)
** in the string pointed to by s.The terminating null character is considered to
** be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	const char	*s_end;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	s_end = s + len - 1;
	if (s == NULL)
		return (NULL);
	while (len--)
	{
		if (*s_end == (char)c)
			return ((char *)s_end);
		s_end--;
	}
	return (NULL);
}
