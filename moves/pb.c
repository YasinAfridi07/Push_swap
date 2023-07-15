/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:12:14 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:18:18 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	b->size++;
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	i = 0;
	while (i < a->size)
	{
		i++;
		a->data[i - 1] = a->data[i];
	}
	a->size--;
	ft_printf("pb\n");
}
