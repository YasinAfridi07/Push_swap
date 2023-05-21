/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2023/05/21 23:28:30 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_set_size(int size, int min_size)
{
	if (size <= min_size)
		return (1);
	return (get_set_size(size / 2, min_size) + 1);
}

void	add_set(t_psinfo *info, t_set *set)
{
	int		i;

	i = 0;
	while (i < info->a.size)
	{
		set->values[i] = info->a.data[i];
		i++;
	}
}

void	add_one_set(t_psinfo *info, t_set *set)
{
	int	i;
	int	j;
	int	pivot;

	pivot = get_pivot(info->a.data, info->a.size, set->size);
	i = 0;
	j = 0;
	while (i < info->a.size && j < set->size)
	{
		if (info->a.data[0] < pivot)
		{
			pb(&info->a, &info->b);
			set->values[j] = info->b.data[0];
			j++;
		}
		else
		{
			ra(&info->a);
			i++;
		}
	}
}

static int	set_value(t_psinfo *info, int *val1, int *val2, int midpivot)
{
	pb(&info->a, &info->b);
	if (info->b.data[0] < midpivot)
	{
		*val1 = info->b.data[0];
		rb(&info->b);
		return (1);
	}
	*val2 = info->b.data[0];
	return (0);
}

void	add_two_set(t_psinfo *info, t_set *s1, t_set *s2)
{
	int	i[3];
	int	pivot;
	int	midpivot;

	pivot = get_pivot(info->a.data, info->a.size, (s1->size + s2->size));
	midpivot = get_pivot(info->a.data, info->a.size, (s1->size + s2->size) / 2);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < info->a.size && i[1] + i[2] < (s1->size + s2->size))
	{
		if (info->a.data[0] < pivot)
		{
			if (set_value(info, &s1->values[i[1]], &s2->values[i[2]], midpivot))
				i[1]++;
			else
				i[2]++;
		}
		else
		{
			ra(&info->a);
			i[0]++;
		}
	}
}
