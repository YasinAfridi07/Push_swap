/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:49:14 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 19:08:29 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

int	smallnumber(t_stack *a)
{
	int i;
	int min_index;
	int min_val;

	if (!a->size)
		return (-1);
	i = 1;
	min_index = 0;
	min_val = a->data[0];
	while (i < a->size)
	{
		if (a->data[i] < min_val)
		{
			min_val = a->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	bignumber(t_stack *stack)
{
	int	max_val;
	int max_index;
	int i;

	i = 0;
	max_index = 0;
	max_val = INT_MIN;
	while (i < stack->size)
	{
		if (stack->data[i] > max_val)
		{
			max_val = stack->data[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	secound(t_stack *stack)
{
	int i;
	int large_index;
	int second_index;

	large_index = bignumber(stack);
	second_index = 0;
	i = 0;

	while (i <= stack->size)
	{
		if (i != large_index && stack->data[i] > stack->data[second_index])
		{
			second_index = i;
		}
		i++;
	}
	return second_index;
}
