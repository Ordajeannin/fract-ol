/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:08:14 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/04 18:20:27 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*scd;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			scd = ft_lstlast(*(lst));
			scd->next = new;
		}
	}
}
