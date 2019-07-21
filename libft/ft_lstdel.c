/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:21:35 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/13 18:04:10 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the adress of a pointer to a link and frees the
** memory of this link and every successors of that link using the functions
** del and free(3). Finally the pointer to the link that was just freed must
** be set to NULL (quite similar to the function ft_memdel from the mandatory
** part).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst && *alst && del)
	{
		while (alst && *alst && del)
		{
			next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
		*alst = NULL;
	}
}
