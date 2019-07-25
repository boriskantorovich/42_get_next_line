/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:58 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 12:22:34 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will
** be considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’.
** If s has no whites- paces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
*/

static int		ft_isspace_strtrim_mod(int c)
{
	if ((c == 0x09) || (c == 0x0a) || (c == 0x20))
		return (1);
	else
		return (0);
}

static size_t	*ft_get_size_and_offset(char const *s)
{
	size_t		space_counter;
	char const	*s_end;
	size_t		*size_and_offset;

	if (!(size_and_offset = (size_t *)malloc(2 * sizeof(int))))
		return (NULL);
	space_counter = 0;
	size_and_offset[0] = ft_strlen(s) + 1;
	s_end = s + size_and_offset[0] - 2;
	while (ft_isspace_strtrim_mod(*s))
	{
		s++;
		space_counter++;
	}
	size_and_offset[1] = space_counter;
	if (space_counter < (size_and_offset[0] - 1))
		while (ft_isspace_strtrim_mod(*(s_end--)))
			space_counter++;
	size_and_offset[0] -= space_counter;
	return (size_and_offset);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	*size_and_offset;

	if (!s)
		return (NULL);
	i = -1;
	if (!(size_and_offset = ft_get_size_and_offset(s)))
		return (NULL);
	if (!(result = (char *)malloc(size_and_offset[0] * sizeof(char))))
		return (NULL);
	while (++i < (size_and_offset[0] - 1))
		*(result + i) = *(s + size_and_offset[1] + i);
	*(result + i) = '\0';
	return (result);
}
