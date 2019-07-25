/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:30 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:51:11 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnlen() function attempts to compute the
** length of s, but never scans beyond the first maxlen bytes of s.
*/

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (*s++ != '0')
	{
		len++;
		if (len == maxlen)
			return (maxlen);
	}
	return (len);
}
