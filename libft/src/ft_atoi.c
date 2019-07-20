/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:51:15 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 17:32:09 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	nb;
	int			sign;

	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*(str++) == '-') ? (-1) : (1);
	while (ft_isdigit(*str))
	{
		if ((sign * (nb * 10 + (*(str) - '0')) / 10) != sign * nb)
			return (sign == 1 ? (-1) : (0));
		nb = nb * 10 + (*(str++) - '0');
	}
	return (sign * nb);
}
