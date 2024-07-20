/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:47:20 by rtaboada          #+#    #+#             */
/*   Updated: 2024/01/24 19:50:47 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;

	if (!lst)
		return (NULL);
	mapped = (t_list *)malloc(sizeof(t_list));
	if (!mapped)
		return (NULL);
	mapped->content = f(lst->content);
	mapped->next = ft_lstmap(lst->next, f, del);
	if (errno == ENOMEM)
	{
		ft_lstclear(&mapped, del);
		return (NULL);
	}
	return (mapped);
}
