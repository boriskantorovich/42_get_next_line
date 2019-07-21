/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:19:28 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:38:36 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcmp() and strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2.
** The strncmp() function compares not more than n characters.
** Because strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
** RETURN VALUES
** The strcmp() and strncmp() functions return an integer greater than, equal
** to, or less than 0, according as the string s1 is greater than, equal to,
** or less than the string s2.  The comparison is done using unsigned
** characters, so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, (ft_strlen(s2) + 1)));
}
