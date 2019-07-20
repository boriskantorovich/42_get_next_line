/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:36 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:49:48 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters
** are searched.
** Characters that appear after a `\0' character are not searched.
** If needle is an empty string, haystack is returned; if needle occurs nowhere
** in haystack, NULL is returned;
** otherwise a pointer to the first character of the first occurrence of needle
** is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	needle_len;
	int diff;
	int i;
	int j;

	if (!*needle)
		return ((char*)haystack);
	else if (!len)
		return (NULL);
	needle_len = ft_strlen(needle);
	i = 0;
	diff = (haystack == NULL) ? len - needle_len + 1 : len - needle_len;
	while (i <= diff)
	{
		if (*(haystack + i) == '\0')
			return (NULL);
		j = -1;
		while (++j < needle_len)
			if (*(haystack + i + j) != *(needle + j))
				break ;
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
