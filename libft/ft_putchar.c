/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:59:49 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 17:53:04 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the character c to the standard output.
*/

void	ft_putchar(char c)
{
	unsigned char c_u;

	c_u = (unsigned char)c;
	write(1, &c, 1);
}
