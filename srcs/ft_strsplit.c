/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:10:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/17 14:29:08 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) ob- tained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL. Example : ft_strsplit("*hello*fellow***students*", ’*’) re- turns the
** array ["hello", "fellow", "students"].
*/

static int	ft_wordscounter(const char *s, char c)
{
	int index;
	int flag;

	index = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (flag == 0)
			{
				flag = 1;
				index++;
			}
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (index);
}

static int	ft_ln(const char *s, char c)
{
	int index;

	index = 0;
	while (*s && *(s++) != c)
		index++;
	return (index);
}

static void	*ft_strdel_strsplit_mode(char **arr, int size)
{
	size -= 1;
	if (arr && *arr)
	{
		while (size >= 0)
		{
			free(arr[size]);
			arr[size] = NULL;
			size--;
		}
		free(arr);
		arr = NULL;
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s || !(result = \
				(char **)malloc((ft_wordscounter(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			j = 0;
			if (!(result[i] = (char *)malloc((ft_ln(s, c) + 1) * sizeof(char))))
				return (ft_strdel_strsplit_mode(result, i));
			while (*s != c && *s)
				*(*(result + i) + j++) = *(s++);
			s--;
			*(*(result + i) + j) = '\0';
			i++;
		}
		s++;
	}
	*(result + i) = NULL;
	return (result);
}
