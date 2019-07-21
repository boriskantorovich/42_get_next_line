/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:15 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/04 12:49:24 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s1_uc;
	const unsigned char *s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	while (n-- && (*s1_uc || *s2_uc))
	{
		if (*s1_uc != *s2_uc)
		{
			if (((*s1_uc > 128)) && (*s2_uc == '\0'))
				return (0);
			return (*s1_uc > *s2_uc) ? \
			(*s1_uc - *s2_uc) : \
			((-1) * (*s2_uc - *s1_uc));
		}
		s1_uc++;
		s2_uc++;
	}
	return (0);
}
