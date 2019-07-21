/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:56:50 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:26:42 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0. If the allocation fails,
** the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void *result;

	if (!(result = (void *)malloc(size)))
		return (NULL);
	ft_bzero(result, size);
	return (result);
}
