/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:09:32 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/23 16:40:36 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (((size < (ft_strlen(s1)) || (size < (ft_strlen(s2))))))
		return (NULL);
	if (!(result = ft_strnew(size)))
		return (NULL);
	result = ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
