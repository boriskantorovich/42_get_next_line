/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:30:14 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/20 18:49:20 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_arr_of_str(char **arr)
{
	int		size;
	char	**ptr_arr;

	ptr_arr = arr;
	size = -1;
	while (*ptr_arr++)
	{
		size++;
	}
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
}

static t_list	*ft_del_and_nulreturn(t_list *root_ptr)
{
	ft_lstdel(&root_ptr, ft_bzero);
	return (NULL);
}

static t_list	*ft_lst_from_charr(char **arr)
{
	t_list	*lst_iter;
	t_list	*root_ptr;
	t_list	*last_ptr;

	lst_iter = NULL;
	root_ptr = NULL;
	last_ptr = NULL;
	while (*arr)
	{
		if (!lst_iter)
		{
			if (!(lst_iter = ft_lstnew(*arr, ft_strlen(*arr) + 1)))
				return (ft_del_and_nulreturn(root_ptr));
			if (!root_ptr)
				root_ptr = lst_iter;
			if (last_ptr)
				last_ptr->next = lst_iter;
		}
		last_ptr = lst_iter;
		lst_iter = lst_iter->next;
		arr++;
	}
	return (root_ptr);
}

t_list			*ft_strsplit_lst(char const *s, char c)
{
	t_list	*result;
	char	**arr;

	if (!s)
		return (NULL);
	if (!(arr = ft_strsplit(s, c)))
		return (NULL);
	result = ft_lst_from_charr(arr);
	ft_free_arr_of_str(arr);
	return (result);
}
