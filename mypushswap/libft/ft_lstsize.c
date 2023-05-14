/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:30:44 by yusman            #+#    #+#             */
/*   Updated: 2022/12/08 17:13:52 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*element;
	int		size;

	size = 0;
	element = lst;
	while (element != NULL)
	{
		element = element->next;
		size++;
	}
	return (size);
}
