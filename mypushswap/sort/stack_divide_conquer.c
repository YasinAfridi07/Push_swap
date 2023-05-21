/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_divide_conquer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2023/05/21 23:54:29 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	divide_on_b(t_psinfo *info, int *sorted,
	int set_size, int mid_index)
{
	int	i[3];
	int	pivot;

	pivot = sorted[mid_index];
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < set_size && i[1] < mid_index)
	{
		if (info->b.data[0] > pivot)
		{
			pa(&info->a, &info->b);
			i[1]++;
		}
		else
		{
			rb(&info->b);
			i[2]++;
		}
		i[0]++;
	}
	return (i[2]);
}

static int	divide_on_a(t_psinfo *info, int *sorted,
	int set_size, int mid_index)
{
	int	i[3];
	int	pivot;

	pivot = sorted[mid_index];
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < set_size && i[1] < mid_index)
	{
		if (info->a.data[0] < pivot)
		{
			pb(&info->a, &info->b);
			i[1]++;
		}
		else
		{
			ra(&info->a);
			i[2]++;
		}
		i[0]++;
	}
	return (i[2]);
}

void	divide_conquer_a(t_psinfo *info, int *sorted,
	int size, int min_size)
{
	int	mid_index;
	int	moves;

	if (size <= min_size)
		return ;
	mid_index = (size / 2);
	moves = divide_on_a(info, sorted, size, mid_index);
	if (size - mid_index > min_size)
		reverse_move(info, "rra", moves);
	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);
	insertsort_on_a(info, &sorted[mid_index], size - mid_index);
	divide_conquer_b(info, sorted, mid_index, min_size);
}

void	divide_conquer_b(t_psinfo *info, int *sorted,
	int size, int min_size)
{
	int	mid_index;
	int	*rsorted;
	int	moves;

	if (size <= min_size)
	{
		rsorted = num_rsort(sorted, size);
		insertsort_on_b(info, rsorted, size);
		free(rsorted);
		return ;
	}
	mid_index = (size / 2) + 1;
	moves = divide_on_b(info, sorted, size, mid_index - 1);
	divide_conquer_a(info, &sorted[mid_index], size - mid_index, min_size);
	insertsort_on_a(info, &sorted[mid_index], size - mid_index);
	if (size - mid_index > min_size)
		reverse_move(info, "rrb", moves);
	divide_conquer_b(info, sorted, mid_index, min_size);
}

void	divide_conquer(t_psinfo *info, t_setinfo *setinfo, int min_size)
{
	int		i;
	int		*sorted;
	t_set	*set;

	i = setinfo->size - 1;
	set = &setinfo->sets[i];
	sorted = num_sort(set->values, set->size);
	insertsort_on_a(info, sorted, set->size);
	free(sorted);
	i--;
	if (i < 0)
		return ;
	set = &setinfo->sets[i];
	sorted = num_rsort(set->values, set->size);
	insertsort_on_b(info, sorted, set->size);
	free(sorted);
	i--;
	while (i >= 0)
	{
		set = &setinfo->sets[i];
		sorted = num_sort(set->values, set->size);
		divide_conquer_b(info, sorted, set->size, min_size);
		free(sorted);
		i--;
	}
}
