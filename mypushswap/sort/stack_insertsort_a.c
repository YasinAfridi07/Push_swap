/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertsort_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2023/05/21 23:55:19 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	optimize_move_on_a(t_psinfo *info, int *sorted, int size, int index)
{
	int	stack_size;
	int	first;
	int	second;

	stack_size = info->a.size;
	if (index < stack_size / 2)
		ra(&info->a);
	else
		rra(&info->a);
	if (size < 2)
		return ;
	first = find_index_arr(sorted, info->a.data[0], size);
	second = find_index_arr(sorted, info->a.data[1], size);
	if (first != -1 && second != -1 && first - 1 == second)
		sa(&info->a);
}

static int	move_to_b(t_psinfo *info, int *sorted, int size, int index)
{
	int	counter;

	if (!size || !info->a.size)
		return (0);
	counter = 0;
	while (info->a.data[0] != sorted[0])
	{
		if (size > 1 && info->a.data[0] == sorted[1])
		{
			pb(&info->a, &info->b);
			counter++;
		}
		else
			optimize_move_on_a(info, sorted, size, index);
		if (issorted(info->a.data, info->a.size))
			return (counter);
	}
	pb(&info->a, &info->b);
	if (counter)
		sb(&info->b);
	return (++counter);
}

void	insertsort_on_a(t_psinfo *info, int *sorted, int size)
{
	int	i;
	int	index;
	int	add_size;
	int	temp;

	i = 0;
	add_size = 0;
	while (i < size)
	{
		index = smallnumber(&info->a);
		temp = move_to_b(info, &sorted[i], size - i, index);
		add_size += temp;
		if (issorted(info->a.data, info->a.size))
			break ;
		i += temp;
	}
	i = 0;
	while (i < add_size)
	{
		pa(&info->a, &info->b);
		if (info->a.size > 1 && info->a.data[0] > info->a.data[1])
			sa(&info->a);
		i++;
	}
}
