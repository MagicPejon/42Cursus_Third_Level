/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:03:06 by amalbrei          #+#    #+#             */
/*   Updated: 2022/02/14 16:40:30 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*point;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			point = ft_lstlast(*lst);
			point -> next = new;
		}
	}
}
