/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2019/07/21 19:36:15 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/21 19:40:29 by dfisher          ###   ########.fr       */
=======
/*   Created: 2019/06/25 11:09:10 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 22:00:14 by dfisher          ###   ########.fr       */
>>>>>>> 5e9830d... trying to make gnl variadic
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strndup(const char *s1, size_t n)
{
	char			*s1_copy;
	unsigned int	i;

	i = 0;
	if (!(s1_copy = ft_strnew(n)))
		return (NULL);
	while (i < n)
=======
/*
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns apointer to it.  The pointer may subsequently
** be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned and errno is set to
** 	ENOMEM.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*s1_copy;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(s1_copy = (char *)malloc(len * sizeof(char))))
		return (NULL);
	while (n-- && s1[i] != '\0')
>>>>>>> 5e9830d... trying to make gnl variadic
	{
		s1_copy[i] = s1[i];
		i++;
	}
<<<<<<< HEAD
=======
	s1_copy[i] = '\0';
>>>>>>> 5e9830d... trying to make gnl variadic
	return (s1_copy);
}
