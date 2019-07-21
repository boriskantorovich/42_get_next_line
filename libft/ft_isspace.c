/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:54:43 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/04 13:05:20 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isspace() function tests for the white-space characters. For any
** locale, this includes the following standard characters:
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
*/

#include "libft.h"

int		ft_isspace(int c)
{
	if (c < 9 || (c > 13 && c != 32))
		return (0);
	else
		return (1);
}
