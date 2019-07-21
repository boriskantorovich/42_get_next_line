/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:52:15 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 11:09:37 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fills a string (\0 - terminated) with char c, except from the last character
*/

void	ft_strset(char *b, int c, size_t len)
{
	if (!b || !len)
		return ;
	ft_memset(b, c, len - 1);
}
