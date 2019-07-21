/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:09:37 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 17:28:48 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dst_size;

	dst_size = ft_strlen(dst) + 1;
	if (size < dst_size)
		return (ft_strlen(src) + size);
	i = 0;
	while (size-- != 1 && dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && (j < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + dst_size - 1);
}
