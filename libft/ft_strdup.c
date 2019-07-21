/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:09:10 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/21 19:38:58 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns apointer to it.  The pointer may subsequently
** be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned and errno is set to
** 	ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s1_copy;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(s1_copy = ft_strnew(len)))
		return (NULL);
	while (s1[i] != '\0')
	{
		s1_copy[i] = s1[i];
		i++;
	}
	return (s1_copy);
}
