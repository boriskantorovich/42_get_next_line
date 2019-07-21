/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:04:37 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 17:54:59 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the file descriptor fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
		ft_putchar_fd(*s++, fd);
}
