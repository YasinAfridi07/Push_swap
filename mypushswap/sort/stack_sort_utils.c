/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2023/05/21 23:14:37 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_arr(int *a, int value, int n)
{
	int		i;

	if (!a || n <= 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	move_top_stack(int index, t_psinfo *info, int on_b)
{
	int		i;
	int		size;

	if (on_b)
		size = info->b.size;
	else
		size = info->a.size;
	if (index <= (size / 2))
	{
		i = 0;
		while (i++ < index)
		{
			if (on_b)
				rb(&info->b);
			else
				ra(&info->a);
		}
		return ;
	}
	i = size - 1;
	while (i-- >= index)
	{
		if (on_b)
			rrb(&info->b);
		else
			rra(&info->a);
	}
}

int	get_pivot(int *a, int size, int index)
{
	int	pivot;
	int	*sorted;

	sorted = new_quicksort(a, size);
	if (!sorted)
		exit(1);
	pivot = sorted[index];
	free(sorted);
	return (pivot);
}
