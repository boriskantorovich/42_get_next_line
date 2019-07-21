/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:55:00 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 19:16:34 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
*/

static int	ft_int_to_str_len(int n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_getpower(int n)
{
	int power;

	power = 1;
	while (n > 9)
	{
		power *= 10;
		n /= 10;
	}
	return (power);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		power;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(s = (char *)malloc((ft_int_to_str_len(n) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	power = 1;
	if (n < 0)
	{
		s[i++] = '-';
		n *= -1;
	}
	power = ft_getpower(n);
	while (power > 0)
	{
		s[i++] = n / power + '0';
		n -= (n / power) * power;
		power /= 10;
	}
	s[i] = '\0';
	return (s);
}
