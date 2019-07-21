/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:57:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/06/25 10:57:49 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_sdigit() function tests for a decimal digit character.
** Regardless of locale, this includes the following characters only:
** ``0''         ``1''         ``2''         ``3''         ``4''
** ``5''         ``6''         ``7''         ``8''         ``9'
** The ft_isdigit() returns zero if the character test
** false and return non-zero if the character tests true.
*/

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c < 58 && c > 47)
		return (1);
	else
		return (0);
}
