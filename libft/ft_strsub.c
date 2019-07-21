/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:54 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 12:22:19 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc() and returns a “fresh” substring from the string
** given as argument. The substring begins at indexstart and is of size len.
** If start and len aren’t refering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	if ((len + 1) == 0)
		return (NULL);
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s += start;
	i = 0;
	while (len--)
	{
		result[i] = *s++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
