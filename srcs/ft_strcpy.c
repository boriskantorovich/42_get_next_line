/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:19:33 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:51:53 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcpy() functions copies the string src to dst (including the
** terminating `\0' character.
** The source and destination strings should not overlap, as the behavior is
** undefined.
** RETURN VALUES
** The strcpy() and strncpy() functions return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	return (ft_strncpy(dst, src, (ft_strlen(src) + 1)));
}
