/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:12:11 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 19:13:18 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int i;

	a->size++;
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = b->data[0];
	i = 0;
	while (i < b->size)
	{
		i++;
		b->data[i - 1] = b->data[i];
	}
	b->size--;
	ft_printf("pa\n");
}
