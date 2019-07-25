/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:26 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 12:17:41 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc) and returns a “fresh” string end- ing with ’\0’.
** Each character of the string is initialized at ’\0’. If the allocation fails
** the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char *result;

	if ((size + 1) == 0)
		return (NULL);
	if (!(result = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(result, '\0', size + 1);
	return (result);
}
