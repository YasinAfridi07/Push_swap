/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:12:19 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 18:47:42 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack *b)
{
	int	data[0];
	int	i;

	data[0] = b->data[0];
	i = 1;
	while (i < b->size)
	{
		b->data[i - 1] = b->data[i];
		i++;
	}
	b->data[i - 1] = data[0];
	ft_printf("rb\n");
}