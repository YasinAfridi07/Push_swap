/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertsort_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:07:49 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:07:53 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	optimize_move_on_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->b.size;
	if (index < stack_size / 2)
		rb(&info->b);
	else
		rrb(&info->b);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, info->b.data[0], size);
	second = find_index_arr(sorted, info->b.data[1], size);
	if (first != -1 && second != -1 && first - 1 == second)
		sb(&info->b);
}

static int	move_to_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (info->b.data[0] != sorted[0])
	{
		if (size > 1 && info->b.data[0] == sorted[1])
		{
			pa(&info->a, &info->b);
			counter++;
		}
		else
			optimize_move_on_b(info, sorted, size, index);
	}
	pa(&info->a, &info->b);
	if (counter)
		sa(&info->a);
	return (++counter);
}

void	insertsort_on_b(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = bignumber(&info->b);
		i += move_to_a(info, &sorted[i], size - i, index);
	}
}
