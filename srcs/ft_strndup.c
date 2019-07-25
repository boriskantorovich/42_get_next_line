/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:36:15 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/21 19:40:29 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*s1_copy;
	unsigned int	i;

	i = 0;
	if (!(s1_copy = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		s1_copy[i] = s1[i];
		i++;
	}
	return (s1_copy);
}
