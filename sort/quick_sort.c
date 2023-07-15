/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:07:04 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:07:18 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	partition(int *a, int start, int end)
{
	int	i;
	int	pindex;
	int	pivot;

	pivot = a[end];
	pindex = start;
	i = start;
	while (i < end)
	{
		if (a[i] < pivot)
		{
			ft_numswap(&a[pindex], &a[i]);
			pindex++;
		}
		i++;
	}
	ft_numswap(&a[pindex], &a[end]);
	return (pindex);
}

void	quicksort(int *a, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(a, start, end);
	quicksort(a, start, pivot - 1);
	quicksort(a, pivot + 1, end);
}

int	*new_quicksort(int *a, int n)
{
	int	*sort;

	if (!a || n <= 0)
		return (0);
	sort = ft_numdup(a, n);
	quicksort(sort, 0, n - 1);
	return (sort);
}

int	issorted(int *a, int n)
{
	int	i;
	int	*sort;

	sort = new_quicksort(a, n);
	i = 0;
	while (i < n)
	{
		if (a[i] != sort[i])
		{
			free(sort);
			return (0);
		}
		i++;
	}
	free(sort);
	return (1);
}
